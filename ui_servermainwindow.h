/********************************************************************************
** Form generated from reading UI file 'servermainwindow.ui'
**
** Created: Tue Nov 19 09:05:01 2013
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERMAINWINDOW_H
#define UI_SERVERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerMainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *IP_label;
    QLineEdit *IP_edit;
    QLabel *port_label;
    QLineEdit *port_edit;
    QPushButton *start_server_btn;
    QPushButton *stop_server_btn;
    QGraphicsView *the_graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ServerMainWindow)
    {
        if (ServerMainWindow->objectName().isEmpty())
            ServerMainWindow->setObjectName(QString::fromUtf8("ServerMainWindow"));
        ServerMainWindow->resize(478, 390);
        centralWidget = new QWidget(ServerMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        IP_label = new QLabel(centralWidget);
        IP_label->setObjectName(QString::fromUtf8("IP_label"));

        horizontalLayout->addWidget(IP_label);

        IP_edit = new QLineEdit(centralWidget);
        IP_edit->setObjectName(QString::fromUtf8("IP_edit"));
        IP_edit->setEnabled(true);
        IP_edit->setMaxLength(15);
        IP_edit->setReadOnly(false);

        horizontalLayout->addWidget(IP_edit);

        port_label = new QLabel(centralWidget);
        port_label->setObjectName(QString::fromUtf8("port_label"));

        horizontalLayout->addWidget(port_label);

        port_edit = new QLineEdit(centralWidget);
        port_edit->setObjectName(QString::fromUtf8("port_edit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(port_edit->sizePolicy().hasHeightForWidth());
        port_edit->setSizePolicy(sizePolicy);
        port_edit->setMaximumSize(QSize(50, 100));
        port_edit->setInputMethodHints(Qt::ImhNone);
        port_edit->setMaxLength(6);

        horizontalLayout->addWidget(port_edit);

        start_server_btn = new QPushButton(centralWidget);
        start_server_btn->setObjectName(QString::fromUtf8("start_server_btn"));

        horizontalLayout->addWidget(start_server_btn);

        stop_server_btn = new QPushButton(centralWidget);
        stop_server_btn->setObjectName(QString::fromUtf8("stop_server_btn"));

        horizontalLayout->addWidget(stop_server_btn);


        verticalLayout->addLayout(horizontalLayout);

        the_graphicsView = new QGraphicsView(centralWidget);
        the_graphicsView->setObjectName(QString::fromUtf8("the_graphicsView"));

        verticalLayout->addWidget(the_graphicsView);

        ServerMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ServerMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 478, 22));
        ServerMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ServerMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ServerMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ServerMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ServerMainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(start_server_btn, port_edit);
        QWidget::setTabOrder(port_edit, IP_edit);
        QWidget::setTabOrder(IP_edit, the_graphicsView);
        QWidget::setTabOrder(the_graphicsView, stop_server_btn);

        retranslateUi(ServerMainWindow);

        QMetaObject::connectSlotsByName(ServerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ServerMainWindow)
    {
        ServerMainWindow->setWindowTitle(QApplication::translate("ServerMainWindow", "Android Based Robotics - Server", 0, QApplication::UnicodeUTF8));
        IP_label->setText(QApplication::translate("ServerMainWindow", "IP", 0, QApplication::UnicodeUTF8));
        port_label->setText(QApplication::translate("ServerMainWindow", "Port", 0, QApplication::UnicodeUTF8));
        port_edit->setText(QString());
        start_server_btn->setText(QApplication::translate("ServerMainWindow", "Start", 0, QApplication::UnicodeUTF8));
        stop_server_btn->setText(QApplication::translate("ServerMainWindow", "Stop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ServerMainWindow: public Ui_ServerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERMAINWINDOW_H
