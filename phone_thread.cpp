#include "phone_thread.h"
#include "servermainwindow.h"
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QThread>

Phone_thread::Phone_thread()
{
}

void Phone_thread::init(int ID, int nb)
{
    socketDescriptor = ID;
    idx_phone = nb;

    //thread starts here
    qDebug() << socketDescriptor << " Starting thread" << idx_phone;
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(socketDescriptor))
    {
//        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(Read_data()), Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected_slot()), Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client Connected";
}

void Phone_thread::Read_data()
{
    QByteArray Data = socket->readAll();
    QString s = QString(Data);
    QStringList a_list = s.split("/");
    QString flag = a_list.at(0);
    Data.clear();

    QHostAddress addr = socket->peerAddress();
    this->name = a_list.at(1);
    this->IP = addr.toString();
    this->port_TCP = socket->peerPort();

    qDebug() << socketDescriptor << " reading..." << flag;

    if(flag == "PHONE")
    {
        emit new_phone(this);

        QString the_text = QString::number(idx_phone);
        the_text.append("\n");
        QByteArray by = the_text.toAscii();
        socket->write(by);              //send idx phone back
    }
}

void Phone_thread::disconnect_phone()
{
    qDebug() << socketDescriptor << " Closing socket...";
    socket->close();        //will emit disconnected...calling disconnected_slot()
}

void Phone_thread::disconnected_slot()
{    
    emit phone_disconnected(idx_phone);

    socket->deleteLater();
    this->deleteLater();
    qDebug() << socketDescriptor << " Disconnected \n";
}

void Phone_thread::send_message(QString msg)
{
    qDebug() << socketDescriptor << " Sending " << msg;
    socket->write(msg.toAscii());              //send idx phone back
}


