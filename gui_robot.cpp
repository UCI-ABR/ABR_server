/*******************************************************************************************************
Copyright (c) 2011 Regents of the University of California.
All rights reserved.

This software was developed at the University of California, Irvine.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in
   the documentation and/or other materials provided with the
   distribution.

3. All advertising materials mentioning features or use of this
   software must display the following acknowledgment:
   "This product includes software developed at the University of
   California, Irvine by Nicolas Oros, Ph.D.
   (http://www.cogsci.uci.edu/~noros/)."

4. The name of the University may not be used to endorse or promote
   products derived from this software without specific prior written
   permission.

5. Redistributions of any form whatsoever must retain the following
   acknowledgment:
   "This product includes software developed at the University of
   California, Irvine by Nicolas Oros, Ph.D.
   (http://www.cogsci.uci.edu/~noros/)."

THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL THE UNIVERSITY OR THE PROGRAM CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************************************/
#include <QThread>
#include <QKeyEvent>
#include <QGraphicsScene>

#include "gui_robot.h"
#include "ui_gui_robot.h"
#include "graphics_item.h"
#include "data_handler.h"
#include <QPalette>
#include <QRectF>

#define IOIO_CYCLE 50       //timer will update ioio commands and send them to robot over tcp socket every 50 ms

/**********************************************************************************************************************/
/****************************************************** GUI ************************************************************/
/**********************************************************************************************************************/

GUI_robot::GUI_robot(QString name, int idx_robot, Graphic_object *item_robot, QHostAddress IP_svr, int port_seed, QStringList list_res):QDialog(),ui(new Ui::GUI_robot)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);

    //    QPalette pal = palette();
    //    pal.setColor(backgroundRole(), Qt::white);
    //    setPalette(pal);

    //initialize pointers and vars
    name_robot          = name;
    id_robot            = idx_robot;
    robot_item          = item_robot;
    IP_server           = IP_svr;
    list_res_cam        = list_res;
    ioio_handler        = 0;
    sensors_handler     = 0;
    video_handler       = 0;
    timer_ioio_pwm      = 0;
    RC_MODE             = true;
    EXPLORE_MODE        = false;
    up_key_pressed      = false;
    left_key_pressed    = false;
    down_key_pressed    = false;
    right_key_pressed   = false;

    //connect GUI buttons to functions to be called
    connect(ui->sensors_start_btn,SIGNAL(clicked()),this,SLOT(start_sensors()),Qt::DirectConnection);
    connect(ui->sensors_stop_btn,SIGNAL(clicked()),this,SLOT(stop_sensors()),Qt::DirectConnection);
    connect(ui->camera_start_btn,SIGNAL(clicked()),this,SLOT(start_video()),Qt::DirectConnection);
    connect(ui->camera_stop_btn,SIGNAL(clicked()),this,SLOT(stop_video()),Qt::DirectConnection);
    connect(ui->img_compression_Slider,SIGNAL(valueChanged(int)),this,SLOT(set_compression(int)),Qt::DirectConnection);
    connect(ui->ima_color_radioButton,SIGNAL(clicked()),this,SLOT(set_color_mode()),Qt::DirectConnection);
    connect(ui->ima_gray_radioButton,SIGNAL(clicked()),this,SLOT(set_color_mode()),Qt::DirectConnection);
    connect(ui->ioio_start_btn,SIGNAL(clicked()),this,SLOT(start_IOIO()),Qt::DirectConnection);
    connect(ui->ioio_stop_btn,SIGNAL(clicked()),this,SLOT(stop_IOIO()),Qt::DirectConnection);
    connect(ui->rc_radioButton,SIGNAL(clicked()),this,SLOT(set_mode()));
    connect(ui->explore_radioButton,SIGNAL(clicked()),this,SLOT(set_mode()));

    //setup GUI
    QString title;
    title.append("Android ");
    title.append(QString::number(idx_robot));
    setWindowTitle(title);
    G_scene = new QGraphicsScene(this);
    QSize size_scene = ui->gV_video->size();
    ui->gV_video->setScene(G_scene);
    video_item = new Graphic_object(false, size_scene.width(), size_scene.height(), 0, 0);
    G_scene->addItem(video_item);
    G_scene->update();

    QPainter *p;
    QPixmap transparent;
#if QT_VERSION < 0x050000

    left_pix_pressed.load(":/Images/Image_files/left_arrow.jpg");
    left_pix_released = left_pix_pressed.copy();
    transparent = left_pix_released;
    p = new QPainter(&transparent);
    p->fillRect(transparent.rect(), QColor(50, 50, 50));
    p->end();
    left_pix_released.setAlphaChannel(transparent);

    right_pix_pressed.load(":/Images/Image_files/right_arrow.jpg");
    right_pix_released = right_pix_pressed.copy();
    transparent = right_pix_released;
    p = new QPainter(&transparent);
    p->fillRect(transparent.rect(), QColor(50, 50, 50));
    p->end();
    right_pix_released.setAlphaChannel(transparent);

    up_pix_pressed.load(":/Images/Image_files/up_arrow.jpg");
    up_pix_released = up_pix_pressed.copy();
    transparent = up_pix_released;
    p = new QPainter(&transparent);
    p->fillRect(transparent.rect(), QColor(50, 50, 50));
    p->end();
    up_pix_released.setAlphaChannel(transparent);

    down_pix_pressed.load(":/Images/Image_files/down_arrow.jpg");
    down_pix_released = down_pix_pressed.copy();
    transparent = down_pix_released;
    p = new QPainter(&transparent);
    p->fillRect(transparent.rect(), QColor(50, 50, 50));
    p->end();
    down_pix_released.setAlphaChannel(transparent);
#else

    left_pix_pressed.load(":/Images/Image_files/left_arrow.jpg");
    transparent = left_pix_pressed.copy();
    transparent.fill(Qt::transparent);
    p = new QPainter(&transparent);
    p->setCompositionMode(QPainter::CompositionMode_Source);
    p->drawPixmap(0, 0, left_pix_pressed);
    p->setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p->fillRect(transparent.rect(), QColor(0, 0, 0, 150));
    p->end();
    left_pix_released = transparent;

    right_pix_pressed.load(":/Images/Image_files/right_arrow.jpg");
    transparent = right_pix_pressed.copy();
    transparent.fill(Qt::transparent);
    p = new QPainter(&transparent);
    p->setCompositionMode(QPainter::CompositionMode_Source);
    p->drawPixmap(0, 0, right_pix_pressed);
    p->setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p->fillRect(transparent.rect(), QColor(0, 0, 0, 150));
    p->end();
    right_pix_released = transparent;

    up_pix_pressed.load(":/Images/Image_files/up_arrow.jpg");
    transparent = up_pix_pressed.copy();
    transparent.fill(Qt::transparent);
    p = new QPainter(&transparent);
    p->setCompositionMode(QPainter::CompositionMode_Source);
    p->drawPixmap(0, 0, up_pix_pressed);
    p->setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p->fillRect(transparent.rect(), QColor(0, 0, 0, 150));
    p->end();
    up_pix_released = transparent;

    down_pix_pressed.load(":/Images/Image_files/down_arrow.jpg");
    transparent = down_pix_pressed.copy();
    transparent.fill(Qt::transparent);
    p = new QPainter(&transparent);
    p->setCompositionMode(QPainter::CompositionMode_Source);
    p->drawPixmap(0, 0, down_pix_pressed);
    p->setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p->fillRect(transparent.rect(), QColor(0, 0, 0, 150));
    p->end();
    down_pix_released = transparent;
#endif
    ui->left_label->setPixmap(left_pix_released);
    ui->right_label->setPixmap(right_pix_released);
    ui->up_label->setPixmap(up_pix_released);
    ui->down_label->setPixmap(down_pix_released);

    ui->phone_label->setText(name_robot);
    ui->IP_label->setText(IP_server.toString());
    ui->camera_stop_btn->setEnabled(false);
    ui->img_compression_Slider->setEnabled(false);
    ui->cam_sizes_box->insertItems(0,list_res);
    ui->cam_sizes_box->setCurrentIndex(list_res.size()-1);
    ui->cam_port_lineEdit->setText(QString::number(port_seed));
    ui->sensors_port_lineEdit->setText(QString::number(port_seed+1));
    ui->ioio_port_lineEdit->setText(QString::number(port_seed+2));
    ui->motor_progressBar->setEnabled(false);
    ui->servo_progressBar->setEnabled(false);
    ui->sensors_stop_btn->setEnabled(false);
    ui->ioio_stop_btn->setEnabled(false);
    ui->ioio_inv_checkBox->setEnabled(true);
    ui->mode_groupBox->setEnabled(true);
    ui->rc_radioButton->setChecked(true);
    this->adjustSize();
}

GUI_robot::~GUI_robot()
{
    delete ui;
}

void GUI_robot::stop_all()
{
    emit STOP_SENSORS_HANDLER();
    emit STOP_VIDEO_HANDLER();
    emit STOP_IOIO_HANDLER();

    emit SEND_TCP_MESSAGE("SENSORS_OFF\n");
    emit SEND_TCP_MESSAGE("CAMERA_OFF\n");
    emit SEND_TCP_MESSAGE("IOIO_OFF\n");
}

/**********************************************************************************************************************/
/****************************************************** sensors *******************************************************/
/**********************************************************************************************************************/

void GUI_robot::start_sensors()
{
    QString p = ui->sensors_port_lineEdit->text();
    if(!p.isEmpty())
    {
        port_sensor = p.toUInt();

        //update GUI when user clicked on Start
        ui->sensors_start_btn->setEnabled(false);
        ui->sensors_stop_btn->setEnabled(true);
        ui->sensors_port_lineEdit->setEnabled(false);

        sensors_handler = new Data_handler(IP_server,port_sensor);                                          //create handler with ip and port
        QThread *a_thread = new QThread;                                                                    //new thread to run the handler

        connect(a_thread, SIGNAL(started()), sensors_handler, SLOT(init()));                                //once thread started, init handler (open udp socket)
        connect(sensors_handler, SIGNAL(DATA_RECEIVED(QString)), this, SLOT(display_sensors_data(QString)));//display data on GUI when received
        connect(this, SIGNAL(STOP_SENSORS_HANDLER()), sensors_handler, SLOT(deleteLater()));                //delete object when done...will close socket in destructor
        connect(sensors_handler, SIGNAL(destroyed()), a_thread, SLOT(quit()));                              //stop thread when handler destroyed
        connect(a_thread, SIGNAL(finished()), a_thread, SLOT(deleteLater()));                               //delete thread object when finished

        sensors_handler->moveToThread(a_thread);                                                            //causes sensors_handler to run in a separate thread (a_thread)
        a_thread->start();                                                                                  //start thread...therefore ioio_handler

        QString msg;
        msg.append("SENSORS_ON/");
        msg.append(p);
        msg.append("\n");

        emit SEND_TCP_MESSAGE(msg);
    }
}

void GUI_robot::stop_sensors()
{
    emit STOP_SENSORS_HANDLER();                //will cause the socket to be close, sensors_handler to be deleted, the thread running it to be stopped and destroyed
    emit SEND_TCP_MESSAGE("SENSORS_OFF\n");

    //reset GUI
    ui->sensors_start_btn->setEnabled(true);
    ui->sensors_stop_btn->setEnabled(false);
    ui->sensors_port_lineEdit->setEnabled(true);

    sensors_handler = 0;    //reset pointer to null (0)
}

void GUI_robot::display_sensors_data(QString values)
{
    sensors_values = values;
    sensors_values.replace("/", "\n");
    ui->sensors_vals_label->setText(sensors_values);
}

/**********************************************************************************************************************/
/****************************************************** camera ************************************************************/
/**********************************************************************************************************************/

void GUI_robot::start_video()
{
    QString p = ui->cam_port_lineEdit->text();
    if(!p.isEmpty())
    {
        port_camera         = p.toUInt();
        IS_COLOR            = ui->ima_color_radioButton->isChecked();      //true: color, false: grayscale
        RESIZE              = ui->ima_resize_checkBox->isChecked();

        ui->camera_start_btn->setEnabled(false);
        ui->camera_stop_btn->setEnabled(true);
        ui->cam_port_lineEdit->setEnabled(false);
        ui->cam_sizes_box->setEnabled(false);
        ui->img_compression_Slider->setEnabled(true);
        ui->ima_resize_checkBox->setEnabled(false);
        ui->ima_width_lineEdit->setEnabled(false);
        ui->ima_height_lineEdit->setEnabled(false);

        video_handler       = new Data_handler(IP_server,port_camera,true);                                 //create handler with ip and port, and data is an image
        QThread *a_thread   = new QThread;                                                                  //new thread to run the handler

        connect(a_thread, SIGNAL(started()), video_handler, SLOT(init()));                                  //once thread started, init handler (open udp socket)
        connect(video_handler, SIGNAL(DATA_RECEIVED(QImage)),robot_item, SLOT(display_image(QImage)));      //display frame on server gui when received
        connect(video_handler, SIGNAL(DATA_RECEIVED(QImage)),video_item, SLOT(display_image(QImage)));      //display frame on robot gui when received
        connect(video_handler, SIGNAL(IMAGE_SPECS(int, int)),this, SLOT(display_image_specs(int,int)));     //display frame specs when received
        connect(this, SIGNAL(STOP_VIDEO_HANDLER()), video_handler, SLOT(deleteLater()));                    //delete object when done...will close socket in destructor
        connect(video_handler, SIGNAL(destroyed()), a_thread, SLOT(quit()));                                //stop thread when handler destroyed
        connect(a_thread, SIGNAL(finished()), a_thread, SLOT(deleteLater()));                               //delete thread object when finished

        video_handler->moveToThread(a_thread);                                                              //causes video_handler to run in a separate thread (a_thread)
        a_thread->start();                                                                                  //start thread...therefore ioio_handler

        QString msg;
        msg.append("CAMERA_ON/");
        msg.append(p);
        msg.append("/");
        msg.append(QString::number(ui->cam_sizes_box->currentIndex()));
        msg.append("/");
        msg.append(QString::number(IS_COLOR));          //color mode
        msg.append("/");
        msg.append(QString::number(RESIZE));            //resize ON/OFF
        msg.append("/");
        msg.append(ui->ima_width_lineEdit->text());     //resize image to width (80)
        msg.append("/");
        msg.append(ui->ima_height_lineEdit->text());    //resize image to height (64)
        msg.append("\n");

        emit SEND_TCP_MESSAGE(msg);
    }
    else
        qDebug()<<"port empty";
}

void GUI_robot::stop_video()
{
    emit STOP_VIDEO_HANDLER();
    emit SEND_TCP_MESSAGE("CAMERA_OFF\n");

    ui->camera_stop_btn->setEnabled(false);
    ui->camera_start_btn->setEnabled(true);
    ui->cam_port_lineEdit->setEnabled(true);
    ui->cam_sizes_box->setEnabled(true);
    ui->img_compression_Slider->setValue(75);
    ui->img_compression_Slider->setEnabled(false);
    ui->ima_resize_checkBox->setEnabled(true);
    ui->ima_width_lineEdit->setEnabled(true);
    ui->ima_height_lineEdit->setEnabled(true);

    video_handler = 0;    //reset pointer to null (0)
}

void GUI_robot::set_compression(int rate)
{
    img_compression_rate = rate;
    QString s_rate;
    s_rate.append(QString::number(img_compression_rate));
    ui->compr_rate_label->setText(s_rate);

    QString msg;
    msg.append("IMG_RATE/");
    msg.append(s_rate);
    msg.append("\n");

    emit SEND_TCP_MESSAGE(msg);
}

void GUI_robot::set_color_mode()
{
    IS_COLOR = ui->ima_color_radioButton->isChecked();      //true: color, false: grayscale

    QString msg;
    msg.append("COLOR/");
    msg.append(QString::number(IS_COLOR));
    msg.append("\n");

    emit SEND_TCP_MESSAGE(msg);
}

void GUI_robot::display_image_specs(int size, int fps)
{
    ui->size_image_label->setText(QString::number(size));
    ui->fps_label->setText(QString::number(fps));
}

/**********************************************************************************************************************/
/****************************************************** IOIO ************************************************************/
/**********************************************************************************************************************/

void GUI_robot::start_IOIO()
{
    QString p = ui->ioio_port_lineEdit->text();
    if(!p.isEmpty())
    {
        port_IOIO       = p.toUInt();

        //get values entered on GUI
        min_servo       = ui->servo_min_lineEdit->text().toInt();
        max_servo       = ui->servo_max_lineEdit->text().toInt();
        step_servo      = ui->step_servo_lineEdit->text().toInt();
        step_motor      = ui->step_motor_lineEdit->text().toInt();
        min_motor       = ui->motor_min_lineEdit->text().toInt();
        max_motor       = ui->motor_max_lineEdit->text().toInt();
        default_servo   = ui->default_servo_lineEdit->text().toInt();
        default_motor   = ui->default_motor_lineEdit->text().toInt();

        //update GUI after clicking on Start
        ui->ioio_start_btn->setEnabled(false);
        ui->ioio_stop_btn->setEnabled(true);
        ui->ioio_port_lineEdit->setEnabled(false);
        ui->servo_min_lineEdit->setEnabled(false);
        ui->motor_min_lineEdit->setEnabled(false);
        ui->servo_max_lineEdit->setEnabled(false);
        ui->motor_max_lineEdit->setEnabled(false);
        ui->default_servo_lineEdit->setEnabled(false);
        ui->default_motor_lineEdit->setEnabled(false);
        ui->motor_progressBar->setEnabled(true);
        ui->servo_progressBar->setEnabled(true);
        ui->step_servo_lineEdit->setEnabled(false);
        ui->step_motor_lineEdit->setEnabled(false);
        ui->motor_progressBar->setMinimum(min_motor);
        ui->servo_progressBar->setMinimum(min_servo);
        ui->motor_progressBar->setMaximum(max_motor);
        ui->servo_progressBar->setMaximum(max_servo);
        ui->motor_progressBar->setValue(default_motor);
        ui->servo_progressBar->setValue(default_servo);
        ui->ioio_inv_checkBox->setEnabled(false);


        ioio_handler = new Data_handler(IP_server,port_IOIO);                                            //create handler with ip and port
        QThread *a_thread = new QThread;                                                                //new thread to run the handler

        connect(a_thread, SIGNAL(started()), ioio_handler, SLOT(init()));                               //once thread started, init handler (open udp socket)
        connect(ioio_handler, SIGNAL(DATA_RECEIVED(QString)), this, SLOT(display_IOIO_data(QString)));  //display data when received
        connect(this, SIGNAL(STOP_IOIO_HANDLER()), ioio_handler, SLOT(deleteLater()));                  //delete object when done...will close socket in destructor
        connect(ioio_handler, SIGNAL(destroyed()), a_thread, SLOT(quit()));                             //stop thread when handler destroyed
        connect(a_thread, SIGNAL(finished()), a_thread, SLOT(deleteLater()));                           //delete thread object when finished

        ioio_handler->moveToThread(a_thread);                                                           //causes ioio_handler to run in a separate thread (a_thread)
        a_thread->start();                                                                              //start thread...therefore ioio_handler

        set_mode(); //set robot mode from gui radio buttons (RC, RC_NN, explore)

        //create message to send to client over TCP socket
        QString msg;
        msg.append("IOIO_ON/");
        msg.append(p);
        msg.append("/");
        msg.append(QString::number(INVERTED));          //inverted pwm
        msg.append("/");
        msg.append(QString::number(RC_MODE));           //rc_mode
        msg.append("/");
        msg.append(QString::number(EXPLORE_MODE));      //explore mode
        msg.append("/");
        msg.append(QString::number(min_servo));         //min_servo
        msg.append("/");
        msg.append(QString::number(min_motor));         //min_motor
        msg.append("/");
        msg.append(QString::number(max_servo));         //max_servo
        msg.append("/");
        msg.append(QString::number(max_motor));         //max_motor
        msg.append("/");
        msg.append(QString::number(default_servo));     //default_servo
        msg.append("/");
        msg.append(QString::number(default_motor));      //default_motor
        msg.append("\n");

        emit SEND_TCP_MESSAGE(msg);                     // send message to client over TCP socket
    }
}
void GUI_robot::stop_IOIO()
{
    if(timer_ioio_pwm != 0) timer_ioio_pwm->stop();

    emit STOP_IOIO_HANDLER();                           // will stop ioio handler (thread)
    emit SEND_TCP_MESSAGE("IOIO_OFF\n");                // send message to client to stop IOIO

    //reset GUI
    ui->motor_progressBar->setValue(default_motor);
    ui->servo_progressBar->setValue(default_servo);
    ui->ioio_inv_checkBox->setEnabled(true);
    ui->ioio_start_btn->setEnabled(true);
    ui->ioio_stop_btn->setEnabled(false);
    ui->ioio_port_lineEdit->setEnabled(true);
    ui->servo_min_lineEdit->setEnabled(true);
    ui->motor_min_lineEdit->setEnabled(true);
    ui->servo_max_lineEdit->setEnabled(true);
    ui->motor_max_lineEdit->setEnabled(true);
    ui->default_servo_lineEdit->setEnabled(true);
    ui->default_motor_lineEdit->setEnabled(true);
    ui->motor_progressBar->setEnabled(false);
    ui->servo_progressBar->setEnabled(false);
    ui->step_servo_lineEdit->setEnabled(true);
    ui->step_motor_lineEdit->setEnabled(true);

    ioio_handler    = 0;    //reset pointer to null (0)
    timer_ioio_pwm  = 0;
}

//function called when user clicks on a radio button to select mode robot
void GUI_robot::set_mode()
{
    //set variables to default values
    pwm_servo           = default_servo;
    pwm_motor           = default_motor;

    left_key_pressed    = false;
    right_key_pressed   = false;
    down_key_pressed    = false;
    up_key_pressed      = false;

    RC_MODE             = ui->rc_radioButton->isChecked();
    EXPLORE_MODE        = ui->explore_radioButton->isChecked();
    INVERTED            = ui->ioio_inv_checkBox->isChecked();       //inverted pwm commands (for some rc cars)

    if(ioio_handler != 0)     //only update gui, and send mode over tcp if ioio_handler created
    {
        if(RC_MODE) //if rc mode, timer will update ioio pwm and send commands to robot
        {
            timer_ioio_pwm = new QTimer(this);                                          // create timer...
            connect(timer_ioio_pwm, SIGNAL(timeout()), this, SLOT(upd_ioio_pwm()));     // that will update values...
            timer_ioio_pwm->start(IOIO_CYCLE);                                          // every IOIO_CYCLE (50ms)
        }
        else
        {
            if(timer_ioio_pwm != 0) timer_ioio_pwm->stop();
        }

        QString msg;
        msg.append("MODE/");
        msg.append(QString::number(RC_MODE));
        msg.append("/");
        msg.append(QString::number(EXPLORE_MODE));
        msg.append("\n");

        emit SEND_TCP_MESSAGE(msg);
    }
}

void GUI_robot::display_IOIO_data(QString data)
{
    ioio_values = data;
    ioio_values.replace("/", "\n");
    ui->ioio_values_label->setText(ioio_values);
}

//ckeck keys pressed by user or NN, change pwm values accordingly, update gui, and sends commands to client over tcp socket
void GUI_robot::upd_ioio_pwm()
{    
    if (left_key_pressed == true)
    {
        ui->left_label->setPixmap(left_pix_pressed);
        ui->right_label->setPixmap(right_pix_released);

        if(pwm_servo > min_servo) pwm_servo -= step_servo;
    }
    else if(right_key_pressed == true)
    {
        ui->left_label->setPixmap(left_pix_released);
        ui->right_label->setPixmap(right_pix_pressed);
        if(pwm_servo < max_servo) pwm_servo += step_servo;
    }
    else
    {
        ui->left_label->setPixmap(left_pix_released);
        ui->right_label->setPixmap(right_pix_released);
        if(pwm_servo < default_servo) pwm_servo+= step_servo;
        else if(pwm_servo > default_servo) pwm_servo-= step_servo;
    }

    if (up_key_pressed == true)
    {
        ui->up_label->setPixmap(up_pix_pressed);
        ui->down_label->setPixmap(down_pix_released);
        if(pwm_motor < max_motor) pwm_motor += step_motor;
    }
    else if (down_key_pressed == true)
    {
        ui->up_label->setPixmap(up_pix_released);
        ui->down_label->setPixmap(down_pix_pressed);
        if(pwm_motor > min_motor) pwm_motor -= step_motor;
    }
    else
    {
        ui->up_label->setPixmap(up_pix_released);
        ui->down_label->setPixmap(down_pix_released);
        if(pwm_motor < default_motor) pwm_motor += step_motor;
        else if(pwm_motor > default_motor) pwm_motor-= step_motor;
    }

    ui->motor_progressBar->setValue(pwm_motor);
    ui->servo_progressBar->setValue(pwm_servo);


    QString msg;
    msg.append("PWM/");
    msg.append(QString::number(pwm_motor));
    msg.append("/");
    msg.append(QString::number(pwm_servo));
    msg.append("\n");

    emit SEND_TCP_MESSAGE(msg);
}

/**********************************************************************************************************************/
/****************************************************** keyboard ************************************************************/
/**********************************************************************************************************************/

void GUI_robot::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:
        up_key_pressed = true;
        break;

    case Qt::Key_A:
        left_key_pressed = true;
        break;

    case Qt::Key_S:
        down_key_pressed = true;
        break;

    case Qt::Key_D:
        right_key_pressed = true;
        break;
    }

}

void GUI_robot::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:
        up_key_pressed = false;
        break;

    case Qt::Key_A:
        left_key_pressed = false;
        break;

    case Qt::Key_S:
        down_key_pressed = false;
        break;

    case Qt::Key_D:
        right_key_pressed = false;
        break;
    }
}
