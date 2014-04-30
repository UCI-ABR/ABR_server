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

#include <QThread>
#include "gui_server.h"
#include "tcp_server.h"
#include "data_handler.h"


TCP_Server::TCP_Server(QObject *parent) : QTcpServer(parent)
{
    gui_server = (GUI_server*)parent;
}

void TCP_Server::start(QHostAddress ip, quint16 port)
{
    nb_robot_connected = 0;

    if(!listen(ip,port))   qDebug() << "Could not start server";
    else                   qDebug() << "Server listening...";
}

void TCP_Server::incomingConnection(int socketDescriptor)
{
    nb_robot_connected++;
    qDebug() << "Robot "<<nb_robot_connected<< " connecting...";

    Data_handler *handler = new Data_handler(socketDescriptor,nb_robot_connected);                  //create handler with tcp socket ID, and total nb robot connected
    QThread *a_thread = new QThread;                                                                //new thread to run the handler

    connect(a_thread,SIGNAL(started()),handler,SLOT(init()));                                           //once thread started, init handler (open TCP socket)
    connect(handler, SIGNAL(ROBOT_CONNECTED(Data_handler*)),gui_server, SLOT(add_robot(Data_handler*)));// add robot in gui...create robot gui
    connect(handler,SIGNAL(ROBOT_DISCONNECTED(int)),gui_server,SLOT(remove_robot(int)));                //when robot disconnects, remove from gui and stop everything
    connect(gui_server, SIGNAL(SIG_STOP_ALL()), handler, SLOT(deleteLater()));                          //if user clicks on stop on gui, delete / disconnect robot
    connect(handler, SIGNAL(destroyed()), a_thread, SLOT(quit()));                                      //stop thread when handler destroyed
    connect(a_thread, SIGNAL(finished()), a_thread, SLOT(deleteLater()));                               //delete thread object when finished

    handler->moveToThread(a_thread);                                                                    //causes handler to run in a separate thread (a_thread)
    a_thread->start();                                                                                  //start thread...therefore handler
}
