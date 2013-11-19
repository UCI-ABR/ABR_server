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

#include <QGLWidget>
#include <QNetworkInterface>
#include <QDebug>

#include "servermainwindow.h"
#include "ui_servermainwindow.h"
#include "android_dialog.h"
#include "phone_item.h"
#include "android_tcp_server.h"
#include "android_tcp_object.h"

ServerMainWindow::ServerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerMainWindow)
{
    ui->setupUi(this);
    ui->stop_server_btn->setEnabled(false);

    scene = new QGraphicsScene(this);
    ui->the_graphicsView->setViewport(new QGLWidget(QGLFormat(QGL::DoubleBuffer)));
    ui->the_graphicsView->setScene(scene);

    init_IP_port();

    tcp_server = new Android_TCP_Server(this);

    connect(ui->start_server_btn,SIGNAL(clicked()),this,SLOT(start_server_thread()));
    connect(ui->stop_server_btn,SIGNAL(clicked()),this,SLOT(stop_server_thread()));
}

void ServerMainWindow::init_IP_port()
{
    QList<QNetworkInterface> list= QNetworkInterface::allInterfaces();
    for(int i=0; i<list.size();i++)
    {
        QNetworkInterface inter = list.at(i);
        if (inter.flags().testFlag(QNetworkInterface::IsUp) && !inter.flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            QList<QNetworkAddressEntry> list2= inter.addressEntries();
            for(int j=0; j<list2.size();j++)
            {
                QNetworkAddressEntry entry = list2.at(j);

                if ( inter.hardwareAddress() != "00:00:00:00:00:00" && entry.ip().toString().contains("."))
                {
                    IP_server = entry.ip();
                    qDebug() << inter.name() + " "+ entry.ip().toString() +" " + inter.hardwareAddress();
                    ui->IP_edit->setText(IP_server.toString());
                }
            }
        }
    }

    ui->port_edit->setText("9000");
}

ServerMainWindow::~ServerMainWindow()
{
    tcp_server->close();
    emit stop_phone_theads();
    delete ui;
}

void ServerMainWindow::start_server_thread()
{
    QString p = ui->port_edit->text();
    if(!p.isEmpty())
    {
        ui->port_edit->setEnabled(false);
        port_TCP = p.toUInt();

        tcp_server->StartServer(port_TCP, IP_server);
        ui->stop_server_btn->setEnabled(true);
        ui->start_server_btn->setEnabled(false);
    }
    else
        qDebug()<<"port empty";

}

void ServerMainWindow::stop_server_thread()
{
    ui->port_edit->setEnabled(true);
    ui->stop_server_btn->setEnabled(false);
    ui->start_server_btn->setEnabled(true);

    tcp_server->close();
    scene->clear();
    scene->update();

    emit stop_phone_theads();
}

void ServerMainWindow::add_phone(Android_TCP_Object* thread)
{
    int seed = port_TCP + (thread->idx_phone * 3);

    Phone_item *new_item = new Phone_item();
    Android_Dialog * new_dialog = new Android_Dialog(this, thread, new_item, seed);
    list_phone_dialogs.append(new_dialog);
    scene->addItem(new_item);
    scene->update();

    qDebug() << " scene has : "<< scene->items().size() << " items";
}

void ServerMainWindow::remove_phone(int idx)
{
    qDebug()<<"remove phone: " << idx;

    for(int nb=0; nb<list_phone_dialogs.size(); nb++)
    {
        Android_Dialog *a_dialog = list_phone_dialogs.at(nb);
//        Phone_item *an_item = a_dialog->the_phone_item;

        if(a_dialog->android_tcp->idx_phone == idx)
        {
            a_dialog->delete_phone_dialog();
            a_dialog->close();
            list_phone_dialogs.remove(nb);

            if(scene->items().size() > 0)   scene->removeItem(a_dialog->the_phone_item);    //if scene hasn't been cleared already

            qDebug() << "remove, list has : "<<list_phone_dialogs.size()<< ", nb: " << nb;

            //            a_dialog->the_phone_item->deleteLater();
            //            a_dialog->deleteLater();
        }
    }
    scene->update();
    qDebug() << "scene has : "<< scene->items().size() << " items";
}
