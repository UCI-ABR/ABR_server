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

#include "android_tcp_server.h"
#include "servermainwindow.h"
#include "android_tcp_object.h"
#include <QThread>

Android_TCP_Server::Android_TCP_Server(QObject *parent) :
    QTcpServer(parent)
{
    the_gui = (ServerMainWindow*)parent;
}

void Android_TCP_Server::StartServer(quint16 port, QHostAddress ip)
{
    port_tcp = port;
    IP_server = ip;
    nb_phone_connected = 0;

    if(!this->listen(IP_server,port_tcp))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Server listening...";
    }
}

void Android_TCP_Server::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << " Client connecting...";

    nb_phone_connected++;

    Android_TCP_Object *a_phone = new Android_TCP_Object(socketDescriptor,nb_phone_connected);
    QThread *thread = new QThread;

    connect(thread,SIGNAL(started()),a_phone,SLOT(init_socket()));
    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));
    connect(a_phone, SIGNAL(new_phone(Android_TCP_Object*)),the_gui, SLOT(add_phone(Android_TCP_Object*)));
    connect(a_phone,SIGNAL(phone_disconnected(int)),the_gui,SLOT(remove_phone(int)));
    connect(the_gui, SIGNAL(stop_phone_theads()), a_phone, SLOT(disconnect_phone()));

    a_phone->moveToThread(thread);
    thread->start();
}
