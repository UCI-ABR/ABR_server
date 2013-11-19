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

#ifndef ANDROID_DIALOG_H
#define ANDROID_DIALOG_H

#include <QDialog>
#include <QString>
#include <QHostAddress>
#include <QVector>
#include <QTimer>

namespace Ui {
class Android_Dialog;
}

class Android_TCP_Object;
class Camera_UDP_Object;
class Phone_item;

class Android_Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Android_Dialog(QWidget *parent = 0, Android_TCP_Object *android_obj=0, Phone_item *phone_item=0, int port_seed=0);
    ~Android_Dialog();
    void delete_phone_dialog();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent * event);
    
private:
    Ui::Android_Dialog *ui;

public:
    Android_TCP_Object* android_tcp;
    Phone_item *the_phone_item;
    QString name, IP;
    quint16 port_TCP, port_sensor, port_camera, port_IOIO, port_NN;
    int idx_phone;
    QVector<QString*> cam_sizes;
    int idx_size_selected;
    float acceleration, compass;
    int img_compression_rate;
    int pwm_servo, pwm_motor;
    int min_servo, min_motor, max_servo, max_motor, default_servo, default_motor, step_servo, step_motor;
    QTimer *timer_ioio_pwm;
    bool up_key_pressed, left_key_pressed, down_key_pressed, right_key_pressed;
    QPixmap up_pix_pressed, down_pix_pressed, right_pix_pressed, left_pix_pressed;
    QPixmap up_pix_released, down_pix_released, right_pix_released, left_pix_released;

    //data to save
    QTimer *timer_data;
    int counter;
    QPixmap video_frame;
    float accel_x, accel_y, accel_z, compass_x, compass_y, compass_z;
    float GPS_long, GPS_lat, GPS_accu;
    QVector<QString*> wifi_APs;
    QString sensors_values, ioio_values;

signals:
    void start_sensors(QString);
    void stop_sensors(QString);
    void start_video(QString);
    void stop_video(QString);
    void start_ioio(QString);
    void stop_ioio(QString);
    void close_upd_cam();
    void close_upd_sensors();
    void close_upd_ioio();
    void send_img_rate(QString);
//    void send_ioio_pwm(int, int);
    void send_ioio_pwm(QString);
    void send_ioio_mode(QString);

public slots:
    void start_sensors_phone();
    void stop_sensors_phone();
    void start_camera_phone();
    void stop_camera_phone();
    void start_ioio_phone();
    void stop_ioio_phone();
    void set_comp_rate(int rate);
    void display_frame(QImage ima, int size);
    void display_sensors(QString values);
    void display_IR(QString values);
    void upd_ioio_pwm();
    void save_data();
    void set_mode();
};

#endif // ANDROID_DIALOG_H
