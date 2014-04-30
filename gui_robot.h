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

//how to create threads in Qt:
//http://blog.qt.digia.com/blog/2010/06/17/youre-doing-it-wrong/
//http://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/


#ifndef GUI_ROBOT_H
#define GUI_ROBOT_H

#include <QDialog>
#include <QString>
#include <QHostAddress>
#include <QVector>
#include <QTimer>
#include <QGraphicsScene>

namespace Ui {
class GUI_robot;
}

//forward declaration so we don't include header files here (but we do in the .cpp file)
class GUI_server;
class Data_handler;
class Graphic_object;

//class used to diplay data (video, sensory, IOIO ), start/stop camera, sensors, IOIO, neural network
class GUI_robot : public QDialog
{
    Q_OBJECT
    
    /********************************  GUI  ********************************************************************************/
public:
    explicit GUI_robot(QString name, int idx_robot, Graphic_object *item_robot, QHostAddress IP_svr, int port_seed, QStringList list_res);
    ~GUI_robot();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent * event);

public:
    Graphic_object *robot_item;
    
private:
    Ui::GUI_robot *ui;
    QGraphicsScene *G_scene;
    Graphic_object *video_item;
    QPixmap up_pix_pressed, down_pix_pressed, right_pix_pressed, left_pix_pressed;
    QPixmap up_pix_released, down_pix_released, right_pix_released, left_pix_released;
    bool up_key_pressed, left_key_pressed, down_key_pressed, right_key_pressed;


    /********************************  ROBOT  ********************************************************************************/

public:
    void stop_all();

public:
    int id_robot;

private:    
    QHostAddress IP_server;
    quint16 port_sensor, port_camera, port_IOIO;
    QString name_robot;
    QStringList list_res_cam;    

    Data_handler *ioio_handler;
    Data_handler *sensors_handler;
    Data_handler *video_handler;

    bool RC_MODE,EXPLORE_MODE, INVERTED, IS_COLOR, RESIZE;
    int img_compression_rate;   
    int pwm_motor, pwm_servo;
    int min_servo, min_motor, max_servo, max_motor, default_servo, default_motor, step_servo, step_motor;
    QTimer *timer_ioio_pwm;
    QPixmap video_frame;
    QString sensors_values, ioio_values;


    /********************************  signals and slots  ********************************************************************************/

signals:
    void SEND_TCP_MESSAGE(QString);
    void STOP_IOIO_HANDLER();
    void STOP_SENSORS_HANDLER();
    void STOP_VIDEO_HANDLER();
    void IMG_PARAM(bool, bool, int);

public slots:
    void start_IOIO();
    void stop_IOIO();
    void display_IOIO_data(QString data);
    void upd_ioio_pwm();
    void set_mode();

    void start_sensors();
    void stop_sensors();
    void display_sensors_data(QString values);

    void start_video();
    void stop_video();
    void set_compression(int rate);
    void display_image_specs(int size, int fps);
    void set_color_mode();
};

#endif // GUI_ROBOT_H
