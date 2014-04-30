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

#include <QNetworkInterface>
#include <QDebug>
#include <QGraphicsWidget>
#include <qdir.h>

#include "gui_server.h"
#include "ui_gui_server.h"
#include "gui_robot.h"
#include "graphics_item.h"
#include "tcp_server.h"
#include "data_handler.h"

GUI_server::GUI_server(QWidget *parent) : QMainWindow(parent), ui(new Ui::gui_server)
{
    ui->setupUi(this);
    ui->stop_server_btn->setEnabled(false);

    scene = new QGraphicsScene(this);
    ui->the_graphicsView->setScene(scene);

    init_IP_port();
    tcp_server = new TCP_Server(this);

    connect(ui->start_server_btn,SIGNAL(clicked()),this,SLOT(start()));
    connect(ui->stop_server_btn,SIGNAL(clicked()),this,SLOT(stop()));

    QDir dir("DATA/");
    if (!dir.exists()) dir.mkpath(".");
}

void GUI_server::init_IP_port()
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
//                    qDebug() << inter.name() + " "+ entry.ip().toString() +" " + inter.hardwareAddress();
                    ui->IP_edit->setText(IP_server.toString());
                }
            }
        }
    }

    ui->port_edit->setText("9000");
}

GUI_server::~GUI_server()
{
    tcp_server->close();
    emit SIG_STOP_ALL();
    delete ui;
}

void GUI_server::start()
{
    QString p = ui->port_edit->text();
    if(!p.isEmpty())
    {
        ui->port_edit->setEnabled(false);
        port_TCP = p.toUInt();

        tcp_server->start(IP_server, port_TCP);
        ui->stop_server_btn->setEnabled(true);
        ui->start_server_btn->setEnabled(false);
    }
    else
        qDebug()<<"port empty";
}

void GUI_server::stop()
{
    ui->port_edit->setEnabled(true);
    ui->stop_server_btn->setEnabled(false);
    ui->start_server_btn->setEnabled(true);

    tcp_server->close();
    scene->clear();
    scene->update();

    emit SIG_STOP_ALL();
}

void GUI_server::add_robot(Data_handler* handler)
{
    int seed = port_TCP + (handler->idx_robot * 3);

    QSize size_scene = ui->the_graphicsView->size();

    Graphic_object *item_robot = new Graphic_object(true, size_scene.width(), size_scene.height(), 0, 0);
    GUI_robot * gui_robot = new GUI_robot(handler->name, handler->idx_robot, item_robot, IP_server,seed,handler->list_sizes_cam);
    list_phone_dialogs.append(gui_robot);

    scene->addItem(item_robot);
    scene->update();

    connect(item_robot,SIGNAL(show_dialog()), gui_robot, SLOT(show()));
    connect(gui_robot,SIGNAL(SEND_TCP_MESSAGE(QString)),handler,SLOT(send_message(QString)));
}

void GUI_server::remove_robot(int idx)
{
    for(int nb=0; nb<list_phone_dialogs.size(); nb++)
    {
        GUI_robot *robot = list_phone_dialogs.at(nb);

        if(robot->id_robot == idx)
        {
            robot->stop_all();
            robot->close();
            list_phone_dialogs.remove(nb);

            if(scene->items().size() > 0)   scene->removeItem(robot->robot_item);    //if scene hasn't been cleared already
        }
    }
    scene->update();
}
