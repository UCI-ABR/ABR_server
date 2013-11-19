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

#include "camera_udp_object.h"
#include <QDebug>
#include <QByteArray>
#include <QPixmap>
#include <QVector>
#include <QFile>
#include <QTextStream>

#define HEADER_SIZE 5;
#define DATAGRAM_MAX_SIZE 1450;
#define DATA_MAX_SIZE 1445;

Camera_UDP_Object::Camera_UDP_Object(QHostAddress ip, quint16 port)
{
    udpSocket = new QUdpSocket(this);
    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(read_image()));

    bool b = udpSocket->bind(ip, port);
    qDebug()<<"udp cam bound: "<< b << " , ip server: "<< ip.toString() << " , port server: "<< port;

    current_frame = -1;
    slicesStored = 0;
    nb_total_frames = 0;
    mean_fps = 0;
    fps = 0;

    QFile file_data("fps.txt");
    file_data.open(QIODevice::WriteOnly | QIODevice::Text); //QIODevice::Append |
    file_data.close();
}

void Camera_UDP_Object::close_socket()
{
    float total_time = m_time.elapsed();
//    mean_fps = total_time / (float)nb_total_frames;
    mean_fps = ((float)nb_total_frames*1000)/total_time;
    udpSocket->close();
    this->deleteLater();
    qDebug()<<"socket close";
    qDebug()<<"mean FPS is " << mean_fps<< " time: " << total_time<< " frames: "<< nb_total_frames;
}

void Camera_UDP_Object::read_image()
{
    QByteArray datagram;
    datagram.resize(udpSocket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;

    udpSocket->readDatagram(datagram.data(), datagram.size(),&sender, &senderPort);

    int frame_nb = (int)datagram.at(0);
    int nb_packets = (int)datagram.at(1);
    int packet_nb = (int)datagram.at(2);
    int size_packet = (int) ((datagram.at(3) & 0xff) << 8 | (datagram.at(4) & 0xff));

    if((packet_nb==0) && (current_frame != frame_nb))
    {
        current_frame = frame_nb;
        imageData.clear();
        slicesStored=0;
        size_packets = 0;
        slices.clear();
        slices = QVector<QByteArray>(nb_packets);
    }

    if(frame_nb == current_frame)
    {
        datagram.remove(0,5);
        slicesStored++;
        size_packets += size_packet;

        slices[packet_nb] = datagram;

//        QFile file_data("fps.txt");
//        file_data.open(QIODevice::Append | QIODevice::Text); //QIODevice::Append |
//        QTextStream out(&file_data);
//        out << size_packet<< "\n";
//        file_data.close();

//        qDebug() << "current frame: " << current_frame << " packet_nb: " << packet_nb
//                 << " slicesStored:" << slicesStored << " nb_packets:" <<nb_packets
//                 << "time interval: " << size_packet << "size data: " << datagram.size();

        if (slicesStored == nb_packets)
        {
            for(int ii=0; ii<slicesStored; ii++)
            {
                imageData.append(slices.at(ii));
            }

            if (nb_total_frames == 0) m_time.start();

            nb_total_frames++;
            the_frame.loadFromData(imageData);  //have to use QImage instead of QPixmap because outside GUI thread

            int size_d = imageData.size();
            emit this->frame_ready(the_frame, size_d);
        }
    }
}
