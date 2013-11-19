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

#include "ioio_udp_object.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

IOIO_UDP_Object::IOIO_UDP_Object(QHostAddress ip, quint16 port)
{
    udpSocket = new QUdpSocket(this);
    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(read_data()));

    bool b = udpSocket->bind(ip, port);
    qDebug()<<"udp ioio bound: "<< b << " , ip: "<< ip.toString() << " , port: "<< port;

    QFile file_data("ioio.txt");
    file_data.open(QIODevice::WriteOnly | QIODevice::Text); //QIODevice::Append |
    file_data.close();
}

void IOIO_UDP_Object::close_socket()
{
    udpSocket->close();
    this->deleteLater();
    qDebug()<<"socket ioio closed";
}

void IOIO_UDP_Object::write_pwm_values(int motor, int servo)
{
    pwm_motor = motor;
    pwm_servo = servo;
}

void IOIO_UDP_Object::read_data()
{
    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(),&sender, &senderPort);

        QString data = QString(datagram);

//        qDebug()<<"ioio" << data;

//        QStringList a_list = data.split("/");

//        QString cycle = a_list.at(6);
//        QFile file_data("ioio.txt");
//        file_data.open(QIODevice::Append | QIODevice::Text); //QIODevice::Append |
//        QTextStream out(&file_data);
//        out << cycle << "\n";
//        file_data.close();

        emit values_ready(data);
        datagram.clear();
    }
}
