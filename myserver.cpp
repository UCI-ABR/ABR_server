#include "myserver.h"
#include "servermainwindow.h"
#include "android_tcp_object.h"
#include <QThread>

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
    the_gui = (ServerMainWindow*)parent;
    nb_phone_connected = 0;
}

void MyServer::StartServer(quint16 port, QHostAddress ip)
{
    port_tcp = port;
    IP_server = ip;

    if(!this->listen(IP_server,port_tcp))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Server listening...";
    }
}

void MyServer::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << " Client connecting...";

    nb_phone_connected++;

    Android_TCP_Object *a_phone = new Android_TCP_Object();
    QThread *thread = new QThread;
    a_phone->init(socketDescriptor,nb_phone_connected);

    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));
    connect(a_phone, SIGNAL(new_phone(Phone_thread*)),the_gui, SLOT(add_phone(Phone_thread*)));
    connect(a_phone,SIGNAL(phone_disconnected(int)),the_gui,SLOT(remove_phone(int)), Qt::DirectConnection);
    connect(the_gui, SIGNAL(stop_phone_theads()), a_phone, SLOT(disconnect_phone()), Qt::DirectConnection);

    a_phone->moveToThread(thread);
    thread->start();
}
