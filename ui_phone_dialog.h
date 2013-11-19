/********************************************************************************
** Form generated from reading UI file 'phone_dialog.ui'
**
** Created: Tue Apr 10 20:33:45 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONE_DIALOG_H
#define UI_PHONE_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *sensors_label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *sensors_port_label;
    QLineEdit *sensors_port_lineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *compass_label;
    QLCDNumber *compass_LCD;
    QVBoxLayout *verticalLayout_2;
    QLabel *acceleration_label;
    QLCDNumber *accelerometer_LCD;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *camera_label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSlider *img_compression_Slider;
    QComboBox *cam_sizes_box;
    QLabel *video_label;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QString::fromUtf8("MyDialog"));
        MyDialog->resize(330, 300);
        MyDialog->setAutoFillBackground(false);
        MyDialog->setModal(false);
        verticalLayout_4 = new QVBoxLayout(MyDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        sensors_label = new QLabel(MyDialog);
        sensors_label->setObjectName(QString::fromUtf8("sensors_label"));

        horizontalLayout_3->addWidget(sensors_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sensors_port_label = new QLabel(MyDialog);
        sensors_port_label->setObjectName(QString::fromUtf8("sensors_port_label"));

        horizontalLayout_2->addWidget(sensors_port_label);

        sensors_port_lineEdit = new QLineEdit(MyDialog);
        sensors_port_lineEdit->setObjectName(QString::fromUtf8("sensors_port_lineEdit"));

        horizontalLayout_2->addWidget(sensors_port_lineEdit);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        compass_label = new QLabel(MyDialog);
        compass_label->setObjectName(QString::fromUtf8("compass_label"));

        verticalLayout_3->addWidget(compass_label);

        compass_LCD = new QLCDNumber(MyDialog);
        compass_LCD->setObjectName(QString::fromUtf8("compass_LCD"));

        verticalLayout_3->addWidget(compass_LCD);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        acceleration_label = new QLabel(MyDialog);
        acceleration_label->setObjectName(QString::fromUtf8("acceleration_label"));

        verticalLayout_2->addWidget(acceleration_label);

        accelerometer_LCD = new QLCDNumber(MyDialog);
        accelerometer_LCD->setObjectName(QString::fromUtf8("accelerometer_LCD"));

        verticalLayout_2->addWidget(accelerometer_LCD);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        camera_label = new QLabel(MyDialog);
        camera_label->setObjectName(QString::fromUtf8("camera_label"));

        horizontalLayout_4->addWidget(camera_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        img_compression_Slider = new QSlider(MyDialog);
        img_compression_Slider->setObjectName(QString::fromUtf8("img_compression_Slider"));
        img_compression_Slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(img_compression_Slider);

        cam_sizes_box = new QComboBox(MyDialog);
        cam_sizes_box->setObjectName(QString::fromUtf8("cam_sizes_box"));

        verticalLayout->addWidget(cam_sizes_box);


        horizontalLayout->addLayout(verticalLayout);

        video_label = new QLabel(MyDialog);
        video_label->setObjectName(QString::fromUtf8("video_label"));
        video_label->setMinimumSize(QSize(100, 100));

        horizontalLayout->addWidget(video_label);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QDialog *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        sensors_label->setText(QApplication::translate("MyDialog", "SENSORS", 0, QApplication::UnicodeUTF8));
        sensors_port_label->setText(QApplication::translate("MyDialog", "Port", 0, QApplication::UnicodeUTF8));
        compass_label->setText(QApplication::translate("MyDialog", "Compass", 0, QApplication::UnicodeUTF8));
        acceleration_label->setText(QApplication::translate("MyDialog", "Acceleration", 0, QApplication::UnicodeUTF8));
        camera_label->setText(QApplication::translate("MyDialog", "CAMERA", 0, QApplication::UnicodeUTF8));
        video_label->setText(QApplication::translate("MyDialog", "VIDEO", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONE_DIALOG_H
