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

#include "data_handler.h"

/************************************************************************************************************************************/
/***************************** Data_handler is used to handle data sent over tcp or udp sockets **************************************/
/************************************************************************************************************************************/

//constructor for UDP socket saves ip address and port number
Data_handler::Data_handler(QHostAddress ip, quint16 port, bool is_data_ima)
{
    ip_address = ip;
    port_udp = port;
    IS_DATA_IMAGE = is_data_ima;

    current_frame = -1;
    nb_slicesStored = 0;
    nb_frames = 0;
    counter =0;

    IS_TCP = false; //socket will be UDP
}

//constructor for TCP socket, socket_ID is given by TCP server
Data_handler::Data_handler(int socket_ID, int idx)
{
    socketDescriptor = socket_ID;
    idx_robot = idx;

    IS_TCP = true; //socket will be TCP
}

//destructor will close socket
Data_handler::~Data_handler()
{
    if(IS_TCP)
    {
        emit ROBOT_DISCONNECTED(idx_robot); //emit signal to remove robot from gui and stop all running handlers
        tcp_socket->close();

        qDebug()<<"Robot "<<idx_robot<<", TCP socket closed: robot disconnected";
    }
    else
    {
        if(IS_DATA_IMAGE) timer->stop();
        udp_socket->close();        
        qDebug()<<"UDP socket closed, port:" << port_udp;
    }
}

/************************************************************************************************************************************/
/****************************************** initialization socket (UDP or TCP) ******************************************************/
/************************************************************************************************************************************/
//function called when attached thread starts in order to open udp or tcp socket
void Data_handler::init()
{
    if(IS_TCP)   //TCP socket
    {
        tcp_socket = new QTcpSocket();
        if(!tcp_socket->setSocketDescriptor(socketDescriptor)) return;

        connect(tcp_socket,SIGNAL(readyRead()),this,SLOT(read_text()));
        connect(tcp_socket,SIGNAL(disconnected()),this,SLOT(deleteLater()));

        qDebug() << "Robot "<<idx_robot<<" Connected";
    }
    else        //UDP socket
    {
        udp_socket = new QUdpSocket(this);

        if(IS_DATA_IMAGE)
        {
            //timer used to calculate fps
            timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(calc_fps()));  //timer will call calc_fps every second
            timer->start(1000);

            connect(udp_socket, SIGNAL(readyRead()),this, SLOT(read_image()));
        }
        else
            connect(udp_socket, SIGNAL(readyRead()),this, SLOT(read_text()));

        bool b = udp_socket->bind(ip_address, port_udp);
        qDebug()<<"UDP socket connected: "<< b << ", port: "<< port_udp;
    }
}

/************************************************************************************************************************************/
/********************************************************** read data text (string) *************************************************/
/************************************************************************************************************************************/

//function called when data (text) arrives on socket (UDP or TCP)
void Data_handler::read_text()
{
    if(IS_TCP)      //read data on tcp socket
    {
        QTextStream in(tcp_socket);
        QString s;
        s = in.readAll();
        QStringList a_list = s.split("/");
        QString flag = a_list.at(0);

        if(flag == "PHONE")
        {
            ip_robot = tcp_socket->peerAddress();

            name = a_list.at(1);
            a_list.removeAt(0);
            a_list.removeAt(0);
            a_list.removeLast();
            list_sizes_cam = QStringList(a_list);

            emit ROBOT_CONNECTED(this);

            QString the_text = QString::number(idx_robot);
            the_text.append("\n");
            tcp_socket->write(the_text.toLatin1());              //send idx phone back
        }
        else if (flag == "TCP_CHECK")           //client send TCP_CHECK every 5s to check connection (keepalive signal)...server replies with TCP_OK
        {
            QString reply = "TCP_OK/\n";
            tcp_socket->write(reply.toLatin1());
        }
    }
    else    //read data on udp socket
    {
        while (udp_socket->hasPendingDatagrams())
        {
            QByteArray datagram;
            datagram.resize(udp_socket->pendingDatagramSize());

            udp_socket->readDatagram(datagram.data(), datagram.size(),&ip_robot, &port_robot);
            QString data = QString(datagram);

            emit DATA_RECEIVED(data);
            datagram.clear();
        }
    }
}

/************************************************************************************************************************************/
/**************************************** send messages to robot / client over TCP socket *******************************************/
/************************************************************************************************************************************/
void Data_handler::send_message(QString msg)
{
    if(tcp_socket->isOpen())
    {
//        tcp_socket->write(msg.toAscii());
        tcp_socket->write(msg.toLatin1());
        tcp_socket->flush();
    }
    else qDebug() << "tcp socket not open...can't write ";
}

/************************************************************************************************************************************/
/************************************************ video / image processing (UDP) ****************************************************/
/************************************************************************************************************************************/

//function called when data (image) arrives on UDP socket
void Data_handler::read_image()
{
    QByteArray datagram;
    datagram.resize(udp_socket->pendingDatagramSize());

    udp_socket->readDatagram(datagram.data(), datagram.size(),&ip_robot, &port_robot);

    int frame_nb = (int)datagram.at(0);
    int nb_packets = (int)datagram.at(1);
    int packet_nb = (int)datagram.at(2);
    //    int size_packet = (int) ((datagram.at(3) & 0xff) << 8 | (datagram.at(4) & 0xff));

    if((packet_nb==0) && (current_frame != frame_nb))   //initialize for new frame
    {
        current_frame = frame_nb;
        imageData.clear();
        nb_slicesStored=0;
        //        size_packets = 0;
        slices.clear();
        slices = QVector<QByteArray>(nb_packets);
    }

    if(frame_nb == current_frame)
    {
        datagram.remove(0,5);
        nb_slicesStored++;
        //        size_packets += size_packet;

        slices[packet_nb] = datagram;

        if (nb_slicesStored == nb_packets)
        {
            for(int ii=0; ii<nb_slicesStored; ii++)
            {
                imageData.append(slices.at(ii));
            }
            nb_frames++;
            the_frame.loadFromData(imageData);  //have to use QImage instead of QPixmap because outside GUI thread           

            emit DATA_RECEIVED(the_frame.rgbSwapped());
            emit IMAGE_SPECS(imageData.size(), fps);
            //            save_frame();
        }
    }
}

// function called by timer to calculate fps
void Data_handler::calc_fps()
{
    fps = nb_frames;
    nb_frames = 0;
}

void Data_handler::save_frame()
{
    QString number = QString("%1").arg(counter, 10, 10, QChar('0')).toUpper();  //add 10 zeros in front of number
    QString name_file("DATA/frame_"+ number +".jpg");
    the_frame.save(name_file,"jpg",-1);
    counter++;
}
