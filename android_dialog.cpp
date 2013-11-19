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

#include "android_dialog.h"
#include "ui_android_dialog.h"
#include "android_tcp_object.h"
#include "camera_udp_object.h"
#include "sensors_udp_object.h"
#include "ioio_udp_object.h"
#include "phone_item.h"
#include <QFile>
#include <QThread>
#include <QKeyEvent>
#include <QDateTime>
#include <QGraphicsScene>

Android_Dialog::Android_Dialog(QWidget *parent, Android_TCP_Object *android_obj, Phone_item *phone_item, int port_seed) :
    QDialog(parent),
    ui(new Ui::Android_Dialog)
{
    ui->setupUi(this);
    android_tcp = android_obj;
    the_phone_item = phone_item;

    this->setFocusPolicy(Qt::StrongFocus);

    counter = 0;

    //    setModal(true);
//        ui->video_label->setScaledContents(true);

    connect(the_phone_item,SIGNAL(show_dialog()), this, SLOT(show()));

    connect(ui->sensors_start_btn,SIGNAL(clicked()),this,SLOT(start_sensors_phone()),Qt::DirectConnection);
    connect(this,SIGNAL(start_sensors(QString)),android_tcp,SLOT(send_message(QString)));

    connect(ui->sensors_stop_btn,SIGNAL(clicked()),this,SLOT(stop_sensors_phone()),Qt::DirectConnection);
    connect(this,SIGNAL(stop_sensors(QString)),android_tcp,SLOT(send_message(QString)));

    connect(ui->camera_start_btn,SIGNAL(clicked()),this,SLOT(start_camera_phone()),Qt::DirectConnection);
    connect(this,SIGNAL(start_video(QString)),android_tcp,SLOT(send_message(QString)));

    connect(ui->camera_stop_btn,SIGNAL(clicked()),this,SLOT(stop_camera_phone()),Qt::DirectConnection);
    connect(this,SIGNAL(stop_video(QString)),android_tcp,SLOT(send_message(QString)));

    connect(ui->img_compression_Slider,SIGNAL(valueChanged(int)),this,SLOT(set_comp_rate(int)),Qt::DirectConnection);
    connect(this,SIGNAL(send_img_rate(QString)),android_tcp,SLOT(send_message(QString)));

    connect(ui->ioio_start_btn,SIGNAL(clicked()),this,SLOT(start_ioio_phone()),Qt::DirectConnection);
    connect(this,SIGNAL(start_ioio(QString)),android_tcp,SLOT(send_message(QString)));

    connect(ui->ioio_stop_btn,SIGNAL(clicked()),this,SLOT(stop_ioio_phone()),Qt::DirectConnection);
    connect(this,SIGNAL(stop_ioio(QString)),android_tcp,SLOT(send_message(QString)));

    connect(ui->rc_radioButton,SIGNAL(clicked()),this,SLOT(set_mode()));
    connect(ui->explore_radioButton,SIGNAL(clicked()),this,SLOT(set_mode()));
    connect(this,SIGNAL(send_ioio_mode(QString)),android_tcp,SLOT(send_message(QString)));

    QString title;
    title.append("Android ");
    title.append(QString::number(android_tcp->idx_phone));
    setWindowTitle(title);

    QPixmap pix;
    pix.load(":/Images/Image_files/carl_logo.jpg");
    ui->video_label->setPixmap(pix);
    pix.alphaChannel();

    QPixmap alpha;
    QPainter *p;

    left_pix_pressed.load(":/Images/Image_files/left_arrow.png");
    left_pix_released = left_pix_pressed.copy();
    alpha = left_pix_released;
    p = new QPainter(&alpha);
    p->fillRect(alpha.rect(), QColor(50, 50, 50));
    p->end();
    left_pix_released.setAlphaChannel(alpha);
    ui->left_label->setPixmap(left_pix_released);

    right_pix_pressed.load(":/Images/Image_files/right_arrow.png");
    right_pix_released = right_pix_pressed.copy();
    alpha = right_pix_released;
    p = new QPainter(&alpha);
    p->fillRect(alpha.rect(), QColor(50, 50, 50));
    p->end();
    right_pix_released.setAlphaChannel(alpha);
    ui->right_label->setPixmap(right_pix_released);

    up_pix_pressed.load(":/Images/Image_files/up_arrow.png");
    up_pix_released = up_pix_pressed.copy();
    alpha = up_pix_released;
    p = new QPainter(&alpha);
    p->fillRect(alpha.rect(), QColor(50, 50, 50));
    p->end();
    up_pix_released.setAlphaChannel(alpha);
    ui->up_label->setPixmap(up_pix_released);

    down_pix_pressed.load(":/Images/Image_files/down_arrow.png");
    down_pix_released = down_pix_pressed.copy();
    alpha = down_pix_released;
    p = new QPainter(&alpha);
    p->fillRect(alpha.rect(), QColor(50, 50, 50));
    p->end();
    down_pix_released.setAlphaChannel(alpha);
    ui->down_label->setPixmap(down_pix_released);

    up_key_pressed = false;
    left_key_pressed = false;
    down_key_pressed = false;
    right_key_pressed = false;

    ui->phone_label->setText(android_tcp->name);
    ui->IP_label->setText(android_tcp->IP);
    ui->camera_stop_btn->setEnabled(false);
    ui->img_compression_Slider->setEnabled(false);
    ui->cam_sizes_box->insertItems(0,android_tcp->list_sizes_cam);
    ui->cam_sizes_box->setCurrentIndex(android_tcp->list_sizes_cam.size()-1);
    ui->cam_port_lineEdit->setText(QString::number(port_seed));
    ui->sensors_port_lineEdit->setText(QString::number(port_seed+1));
    ui->ioio_port_lineEdit->setText(QString::number(port_seed+2));

    ui->motor_progressBar->setEnabled(false);
    ui->servo_progressBar->setEnabled(false);
    ui->sensors_stop_btn->setEnabled(false);
    ui->ioio_stop_btn->setEnabled(false);

    ui->ioio_inv_checkBox->setEnabled(false);

    ui->mode_groupBox->setEnabled(true);
    ui->rc_radioButton->setChecked(true);

    this->adjustSize();

    timer_ioio_pwm = new QTimer(this);
    connect(timer_ioio_pwm, SIGNAL(timeout()), this, SLOT(upd_ioio_pwm()));
}

Android_Dialog::~Android_Dialog()
{
    delete ui;
}

void Android_Dialog::delete_phone_dialog()
{
    emit stop_sensors("SENSORS_OFF\n");
    emit stop_video("CAMERA_OFF\n");
    emit close_upd_sensors();
    emit close_upd_cam();
//    the_phone_item->deleteLater();
//    this->deleteLater();
}

void Android_Dialog::start_sensors_phone()
{
    QString p = ui->sensors_port_lineEdit->text();
    if(!p.isEmpty())
    {
        ui->sensors_start_btn->setEnabled(false);
        ui->sensors_stop_btn->setEnabled(true);
        ui->sensors_port_lineEdit->setEnabled(false);

        qDebug()<<"port sensors: " << p;
        port_sensor = p.toUInt();
        Sensors_UDP_Object *sensors_obj = new Sensors_UDP_Object(android_tcp->ip_server,port_sensor);
        QThread *a_thread = new QThread;

        connect(a_thread, SIGNAL(finished()),a_thread, SLOT(deleteLater()));
        connect(sensors_obj, SIGNAL(values_ready(QString)), this, SLOT(display_sensors(QString)));
        connect(this,SIGNAL(close_upd_sensors()), sensors_obj,SLOT(close_socket()));

        sensors_obj->moveToThread(a_thread);
        a_thread->start();

        QString ss;
        ss.append("SENSORS_ON/");
        ss.append(p);
        ss.append("\n");

        emit start_sensors(ss);
    }
}

void Android_Dialog::stop_sensors_phone()
{
    emit close_upd_sensors();
    emit stop_sensors("SENSORS_OFF\n");

    ui->sensors_start_btn->setEnabled(true);
    ui->sensors_stop_btn->setEnabled(false);
    ui->sensors_port_lineEdit->setEnabled(true);
}

void Android_Dialog::start_camera_phone()
{
    QString p = ui->cam_port_lineEdit->text();
    if(!p.isEmpty())
    {
        ui->camera_start_btn->setEnabled(false);
        ui->camera_stop_btn->setEnabled(true);
        ui->cam_port_lineEdit->setEnabled(false);
        ui->cam_sizes_box->setEnabled(false);
        ui->img_compression_Slider->setEnabled(true);

        qDebug()<<"port cam: " << p;
        port_camera = p.toUInt();
        Camera_UDP_Object *cam_obj = new Camera_UDP_Object(android_tcp->ip_server,port_camera);
        QThread *a_thread = new QThread;

        connect(a_thread, SIGNAL(finished()),a_thread, SLOT(deleteLater()));
        connect(cam_obj, SIGNAL(frame_ready(QImage, int)), this, SLOT(display_frame(QImage, int)));
        connect(cam_obj, SIGNAL(frame_ready(QImage, int)),the_phone_item, SLOT(display_pix(QImage, int)));
        connect(this,SIGNAL(close_upd_cam()), cam_obj,SLOT(close_socket()));

        cam_obj->moveToThread(a_thread);
        a_thread->start();

        QString ss;
        ss.append("CAMERA_ON/");
        ss.append(p);
        ss.append("/");
        ss.append(QString::number(ui->cam_sizes_box->currentIndex()));
        ss.append("\n");

        emit start_video(ss);
    }
    else
        qDebug()<<"port empty";
}

void Android_Dialog::stop_camera_phone()
{
    emit close_upd_cam();
    emit stop_video("CAMERA_OFF\n");

    ui->camera_stop_btn->setEnabled(false);
    ui->camera_start_btn->setEnabled(true);
    ui->cam_port_lineEdit->setEnabled(true);
    ui->cam_sizes_box->setEnabled(true);
    ui->img_compression_Slider->setValue(50);
    ui->img_compression_Slider->setEnabled(false);
}

void Android_Dialog::start_ioio_phone()
{
    QString p = ui->ioio_port_lineEdit->text();
    if(!p.isEmpty())
    {
        ui->ioio_inv_checkBox->setEnabled(false);

//        ui->mode_groupBox->setEnabled(false);

        ui->ioio_start_btn->setEnabled(false);
        ui->ioio_stop_btn->setEnabled(true);
        ui->ioio_port_lineEdit->setEnabled(false);

        min_motor = ui->motor_min_lineEdit->text().toInt();
        max_motor = ui->motor_max_lineEdit->text().toInt();
        min_servo = ui->servo_min_lineEdit->text().toInt();
        max_servo = ui->servo_max_lineEdit->text().toInt();
        default_servo = ui->default_servo_lineEdit->text().toInt();
        default_motor = ui->default_motor_lineEdit->text().toInt();
        step_servo =  ui->step_servo_lineEdit->text().toInt();
        step_motor = ui->step_motor_lineEdit->text().toInt();

        pwm_servo = default_servo;
        pwm_motor = default_motor;

        ui->motor_progressBar->setMinimum(min_motor);
        ui->servo_progressBar->setMinimum(min_servo);
        ui->motor_progressBar->setMaximum(max_motor);
        ui->servo_progressBar->setMaximum(max_servo);

        ui->motor_progressBar->setValue(default_motor);
        ui->servo_progressBar->setValue(default_servo);

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

        qDebug()<<"port ioio: " << p;
        port_IOIO = p.toUInt();

        IOIO_UDP_Object * the_ioio = new IOIO_UDP_Object(android_tcp->ip_server,port_IOIO);
        QThread *a_thread = new QThread;

        connect(a_thread, SIGNAL(finished()),a_thread, SLOT(deleteLater()));
        connect(the_ioio, SIGNAL(values_ready(QString)), this, SLOT(display_IR(QString)));
        connect(this,SIGNAL(close_upd_ioio()), the_ioio,SLOT(close_socket()));
//        connect(this,SIGNAL(send_ioio_pwm(int,int)),the_ioio,SLOT(write_pwm_values(int,int)));
        connect(this,SIGNAL(send_ioio_pwm(QString)),android_tcp,SLOT(send_message(QString)));


        the_ioio->moveToThread(a_thread);
        a_thread->start();

        bool inverted = ui->ioio_inv_checkBox->isChecked();
        bool rc_mode = ui->rc_radioButton->isChecked();
        bool explore = ui->explore_radioButton->isChecked();

        QString ss;
        ss.append("IOIO_ON/");
        ss.append(p);
        ss.append("/");
        ss.append(QString::number(inverted));  //inverted pwm
        ss.append("/");
        ss.append(QString::number(rc_mode));  //rc_mode
        ss.append("/");
        ss.append(QString::number(explore));  //explore mode
        ss.append("\n");

        emit start_ioio(ss);

        timer_ioio_pwm->start(50);  //was 100
    }
}
void Android_Dialog::stop_ioio_phone()
{
    timer_ioio_pwm->stop();
    emit close_upd_ioio();
    emit stop_ioio("IOIO_OFF\n");

    ui->motor_progressBar->setValue(default_motor);
    ui->servo_progressBar->setValue(default_servo);

    ui->ioio_inv_checkBox->setEnabled(true);
//    ui->mode_groupBox->setEnabled(true);

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
}

void Android_Dialog::display_IR(QString values)
{
    ioio_values = values;
    ioio_values.replace("/", "\n");

    ui->ioio_values_label->setText(ioio_values);
}

void Android_Dialog::set_comp_rate(int rate)
{
    img_compression_rate = rate;
    QString ss;
    QString s_rate;
    ss.append("IMG_RATE/");
    s_rate.append(QString::number(img_compression_rate));
    ss.append(s_rate);
    ss.append("\n");

    ui->compr_rate_label->setText(s_rate);

    emit send_img_rate(ss);
}

void Android_Dialog::set_mode()
{
    bool rc_mode = ui->rc_radioButton->isChecked();
    bool explore = ui->explore_radioButton->isChecked();

    QString s;
    s.append("MODE/");
    s.append(QString::number(rc_mode));
    s.append("/");
    s.append(QString::number(explore));
    s.append("\n");

//    if(ui->ioio_start_btn->isChecked()==true)     //only send mode over tcp if ioio started... no need to send twice the same info
        emit send_ioio_mode(s);
}

void Android_Dialog::display_frame(QImage ima, int size)
{
//    ui->video_label->setPixmap(QPixmap::fromImage(ima));
    ui->video_label->setPixmap(QPixmap::fromImage(ima).scaled(300,300));
    ui->size_image_label->setText(QString::number(size));
    this->adjustSize();
}

void Android_Dialog::display_sensors(QString values)
{
    sensors_values = values;
    sensors_values.replace("/", "\n");

//    QStringList a_list = sensors_values.split("/");
//    compass_x = a_list.at(2).toFloat();
//    compass_y = a_list.at(4).toFloat();
//    compass_z = a_list.at(6).toFloat();

//    accel_x = a_list.at(8).toFloat();
//    accel_y = a_list.at(10).toFloat();
//    accel_z = a_list.at(12).toFloat();

    ui->sensors_vals_label->setText(sensors_values);
}

void Android_Dialog::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:        up_key_pressed = true;
        break;

    case Qt::Key_A:        left_key_pressed = true;
        break;

    case Qt::Key_S:        down_key_pressed = true;
        break;

    case Qt::Key_D:        right_key_pressed = true;
        break;
    }
}

void Android_Dialog::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_W:        up_key_pressed = false;
        break;

    case Qt::Key_A:        left_key_pressed = false;
        break;

    case Qt::Key_S:        down_key_pressed = false;
        break;

    case Qt::Key_D:        right_key_pressed = false;
        break;
    }
}

void Android_Dialog::upd_ioio_pwm()
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

    QString s;
    s.append("PWM/");
    s.append(QString::number(pwm_motor));
    s.append("/");
    s.append(QString::number(pwm_servo));
    s.append("\n");

    emit send_ioio_pwm(s);
//    emit send_ioio_pwm(pwm_motor, pwm_servo);
}


void Android_Dialog::save_data()
{
    QDateTime date = QDateTime::currentDateTime();
    QString name_file;
    name_file.append("DATA/video_frames_11_4_2012/frame_");
    name_file.append(date.toString("MM_dd_hh_mm_ss"));
    name_file.append("_" + QString::number(counter)+".jpg");

    video_frame.save(name_file,"jpg",-1);

    name_file.clear();
    name_file.append("DATA/sensors_gps/");
    name_file.append(date.toString("MM_dd")+ "_sensors.txt");

    QFile file_data(name_file);
    file_data.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&file_data);
    out << date.toString("MM_dd_hh_mm_ss") + "\n";
    out << sensors_values;
    out.flush();
    file_data.close();

    counter++;
}



