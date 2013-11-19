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

#include "android_tcp_object.h"
#include "servermainwindow.h"
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QThread>
#include <QTimer>
#include <QFile>
#include <QTextStream>

Android_TCP_Object::Android_TCP_Object(int ID, int nb)
{
    socketDescriptor = ID;
    idx_phone = nb;
}

void Android_TCP_Object::init_socket()
{
    qDebug() << socketDescriptor << " Starting TCP thread for Android idx:" << idx_phone;
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(socketDescriptor)) return;

    ip_server = socket->localAddress();

    connect(socket,SIGNAL(readyRead()),this,SLOT(Read_data()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected_slot()), Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client Connected";

    QFile file_data("main.txt");
    file_data.open(QIODevice::WriteOnly | QIODevice::Text); //QIODevice::Append |
    file_data.close();
}

void Android_TCP_Object::Read_data()
{
    qDebug() << socketDescriptor << " reading...";

    QTextStream in(socket);
    QString s;
    s = in.readAll();
    qDebug() << socketDescriptor << " received...";// << s;

    QStringList a_list = s.split("/");
    QString flag = a_list.at(0);

    if(flag == "PHONE")
    {
        QHostAddress addr = socket->peerAddress();
        name = a_list.at(1);
        IP = addr.toString();
        port_TCP = socket->peerPort();

        a_list.removeAt(0);
        a_list.removeAt(0);
        a_list.removeLast();
        list_sizes_cam = QStringList(a_list);

        emit new_phone(this);

        QString the_text = QString::number(idx_phone);
        the_text.append("\n");
        QByteArray by = the_text.toAscii();
        socket->write(by);              //send idx phone back
    }   
    else if (flag == "MAIN")
    {
        QString cycle = a_list.at(1);

//        qDebug()<<"main: " << cycle;

        QFile file_data("main.txt");
        file_data.open(QIODevice::Append | QIODevice::Text); //QIODevice::Append |
        QTextStream out(&file_data);
        out << cycle;
        file_data.close();
    }
//    else if (flag == "TCP_CHECK")
//    {
//        qDebug() << socketDescriptor << "tcp: tcp check received";

//        QString reply = "TCP_OK/\n";
//        QByteArray by = reply.toAscii();
//        socket->write(by);

//        qDebug() << socketDescriptor << "tcp: sent reply TCP_OK";
//    }
}

void Android_TCP_Object::save_data_file(QString file_name, QStringList data)
{
    QFile file_data(file_name);
    file_data.open(QIODevice::WriteOnly | QIODevice::Text); //QIODevice::Append |
    QTextStream out(&file_data);

    for(int i=0;i<data.size();i++)
    {
        out << data.at(i) << "\n";
        out.flush();
    }
    file_data.close();
}

void Android_TCP_Object::disconnect_phone()
{
    qDebug() << socketDescriptor << " Closing socket from PC";
    socket->close();        //will emit disconnected...calling disconnected_slot()
}

void Android_TCP_Object::disconnected_slot()
{
    emit phone_disconnected(idx_phone);

    socket->deleteLater();
    this->deleteLater();
    qDebug() << socketDescriptor << " Disconnected \n";
}

void Android_TCP_Object::send_message(QString msg)
{
    if(socket->isOpen())
    {
//        qDebug() << socketDescriptor << " Sending " << msg;
        socket->write(msg.toAscii());              //send idx phone back
        socket->flush();
    }
    else qDebug() << socketDescriptor << " socket not open...can't write ";
}
