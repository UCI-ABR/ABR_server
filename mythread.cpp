#include "mythread.h"
#include "servermainwindow.h"
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QByteArray>

MyThread::MyThread(int ID, int nb, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
    idx_phone = nb;
}

void MyThread::run()
{
    //thread starts here
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client Connected";

    exec();
}

void MyThread::readyRead()
{
    QByteArray Data = socket->readAll();

    qDebug() << socketDescriptor << " Data in: " << Data;

    QString s = QString(Data);
    QStringList a_list = s.split("/");
    QString flag = a_list.at(0);
    Data.clear();

    QHostAddress addr = socket->peerAddress();
    this->name = a_list.at(1);
    this->IP = addr.toString();
    this->port_TCP = socket->peerPort();

    if(flag == "PHONE")
    {
        emit new_phone(this);

        QString the_text = QString::number(idx_phone);
        the_text.append("\n");
        socket->write(the_text.toAscii());              //send idx phone back
    }
}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    emit phone_disconnected(idx_phone);

    socket->deleteLater();
    exit(0);
}

void MyThread::start_sensors_phone()
{
//    QTcpSocket a_socket;
//    if(a_socket.setSocketDescriptor(socketDescriptor))
//    {
//        qDebug() << " SENSORS START";
//        QString the_text("SENSORS_START \n");
//        a_socket.write(the_text.toAscii());              //send idx phone back
//    }

    qDebug() << " SENSORS START";
    QString the_text("SENSORS_START \n");
    socket->write(the_text.toAscii());              //send idx phone back
}

