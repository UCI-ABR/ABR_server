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

#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <QObject>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QTimer>
#include <QImage>
#include <QStringList>
#include <QString>

#define HEADER_SIZE 5;
#define DATAGRAM_MAX_SIZE 1450;
#define DATA_MAX_SIZE 1445;

class Data_handler : public QObject
{
    Q_OBJECT
public:
    explicit Data_handler(QHostAddress ip, quint16 port, bool is_data_ima=false);//UDP:constructor saves ip address, port number, and if data received is an image (or text)
    Data_handler(int socket_ID, int idx);                                        //TCP
    ~Data_handler();                                                             //destructor will close socket

public:
    QString name;                                           //name of the robot
    int idx_robot;                                          //idx robot (unique identifier)
    QStringList list_sizes_cam;                             //list of formats (resolution) supported by the robot's camera

private:
    bool IS_TCP;                                            //true if data is sent over tcp socket, false if over udp socket
    QTcpSocket *tcp_socket;
    int socketDescriptor;                                   // ID of tcp socket
    QUdpSocket *udp_socket;
    QHostAddress ip_address;                                // ip of server
    quint16 port_udp;                                       // udp port used on server
    quint16 port_robot;                                     // port used on robot / client (not really usefull to know)
    QHostAddress ip_robot;                                  // ip of the robot

    bool IS_DATA_IMAGE;                                     //true if data that will be received is an image, false if it's text
    int current_frame;
    int nb_slicesStored;
    int nb_frames;
    //    int size_packets;
    int fps;
    int counter;
    QByteArray imageData;
    QVector<QByteArray> slices;
    QImage the_frame;
    QTimer *timer;                                          //timer used to update fps value: will call calc_fps every second

    /***********************************        signals and slots     ***************************************************************/
signals:
    void DATA_RECEIVED(QString);                //signal to be emitted when data (text) is received on udp socket
    void DATA_RECEIVED(QImage);                 //signal to be emitted when data (image) is received on udp socket
    void IMAGE_SPECS(int, int);                 //signal to be emitted to give image size and fps
    void ROBOT_CONNECTED(Data_handler* handler);// called when a robot connects to the server...will create a gui robot...
    void ROBOT_DISCONNECTED(int idx);           // called to remove robot if it was disconnected

public slots:
    void init();                                // function called when attached thread starts in order to open udp socket
    void read_text();                           // function called when data (text) arrives on socket (udp or tcp)
    void read_image();                          // function called when data (image) arrives on socket (udp)
    void calc_fps();                            // function called by timer to calculate fps
    void save_frame();                          // saves frame as an image file on computer
    void send_message(QString msg);             // send message to robot / client over tcp socket
};
#endif // UDP_HANDLER_H
