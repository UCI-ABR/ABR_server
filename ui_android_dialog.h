/********************************************************************************
** Form generated from reading UI file 'android_dialog.ui'
**
** Created: Mon Nov 4 14:10:32 2013
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANDROID_DIALOG_H
#define UI_ANDROID_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Android_Dialog
{
public:
    QHBoxLayout *horizontalLayout_23;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_6;
    QLabel *phone_label;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_7;
    QLabel *IP_label;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout_14;
    QLabel *label;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QPushButton *camera_start_btn;
    QPushButton *camera_stop_btn;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *port_cam_label;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *cam_port_lineEdit;
    QComboBox *cam_sizes_box;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *compr_rate_label;
    QSlider *img_compression_Slider;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *size_image_label;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_10;
    QLabel *video_label;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *sensors_start_btn;
    QPushButton *sensors_stop_btn;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *sensors_port_label;
    QLineEdit *sensors_port_lineEdit;
    QSpacerItem *verticalSpacer_4;
    QLabel *sensors_vals_label;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QPushButton *ioio_start_btn;
    QPushButton *ioio_stop_btn;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *ioio_port_label;
    QLineEdit *ioio_port_lineEdit;
    QCheckBox *ioio_inv_checkBox;
    QFrame *line_4;
    QGroupBox *mode_groupBox;
    QRadioButton *rc_radioButton;
    QRadioButton *explore_radioButton;
    QHBoxLayout *horizontalLayout_20;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_17;
    QLineEdit *motor_min_lineEdit;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_23;
    QLineEdit *motor_max_lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_28;
    QLineEdit *default_motor_lineEdit;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_30;
    QLineEdit *step_motor_lineEdit;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_25;
    QLineEdit *servo_min_lineEdit;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_24;
    QLineEdit *servo_max_lineEdit;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_29;
    QLineEdit *default_servo_lineEdit;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_31;
    QLineEdit *step_servo_lineEdit;
    QVBoxLayout *verticalLayout_13;
    QLabel *ioio_label_2;
    QGridLayout *gridLayout_4;
    QLabel *left_label;
    QLabel *right_label;
    QLabel *up_label;
    QProgressBar *motor_progressBar;
    QLabel *down_label;
    QProgressBar *servo_progressBar;
    QLabel *ioio_values_label;

    void setupUi(QDialog *Android_Dialog)
    {
        if (Android_Dialog->objectName().isEmpty())
            Android_Dialog->setObjectName(QString::fromUtf8("Android_Dialog"));
        Android_Dialog->resize(1058, 860);
        Android_Dialog->setSizeGripEnabled(false);
        horizontalLayout_23 = new QHBoxLayout(Android_Dialog);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_13);

        label_6 = new QLabel(Android_Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_21->addWidget(label_6);

        phone_label = new QLabel(Android_Dialog);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));
        phone_label->setScaledContents(true);

        horizontalLayout_21->addWidget(phone_label);

        horizontalSpacer_7 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_7);

        label_7 = new QLabel(Android_Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_21->addWidget(label_7);

        IP_label = new QLabel(Android_Dialog);
        IP_label->setObjectName(QString::fromUtf8("IP_label"));
        IP_label->setScaledContents(true);

        horizontalLayout_21->addWidget(IP_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_2);


        verticalLayout_15->addLayout(horizontalLayout_21);

        line_2 = new QFrame(Android_Dialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_15->addWidget(line_2);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        label = new QLabel(Android_Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ethnocentric"));
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        camera_start_btn = new QPushButton(Android_Dialog);
        camera_start_btn->setObjectName(QString::fromUtf8("camera_start_btn"));

        verticalLayout_5->addWidget(camera_start_btn);

        camera_stop_btn = new QPushButton(Android_Dialog);
        camera_stop_btn->setObjectName(QString::fromUtf8("camera_stop_btn"));

        verticalLayout_5->addWidget(camera_stop_btn);


        horizontalLayout_7->addLayout(verticalLayout_5);

        horizontalSpacer_4 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        port_cam_label = new QLabel(Android_Dialog);
        port_cam_label->setObjectName(QString::fromUtf8("port_cam_label"));

        verticalLayout_6->addWidget(port_cam_label);

        label_5 = new QLabel(Android_Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_6->addWidget(label_5);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        cam_port_lineEdit = new QLineEdit(Android_Dialog);
        cam_port_lineEdit->setObjectName(QString::fromUtf8("cam_port_lineEdit"));
        cam_port_lineEdit->setEnabled(false);
        cam_port_lineEdit->setMaximumSize(QSize(50, 16777215));
        cam_port_lineEdit->setMaxLength(6);

        verticalLayout_7->addWidget(cam_port_lineEdit);

        cam_sizes_box = new QComboBox(Android_Dialog);
        cam_sizes_box->setObjectName(QString::fromUtf8("cam_sizes_box"));

        verticalLayout_7->addWidget(cam_sizes_box);


        horizontalLayout_5->addLayout(verticalLayout_7);


        horizontalLayout_7->addLayout(horizontalLayout_5);

        horizontalSpacer_5 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Android_Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        compr_rate_label = new QLabel(Android_Dialog);
        compr_rate_label->setObjectName(QString::fromUtf8("compr_rate_label"));
        compr_rate_label->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(compr_rate_label);


        verticalLayout->addLayout(horizontalLayout);

        img_compression_Slider = new QSlider(Android_Dialog);
        img_compression_Slider->setObjectName(QString::fromUtf8("img_compression_Slider"));
        img_compression_Slider->setMouseTracking(false);
        img_compression_Slider->setMaximum(100);
        img_compression_Slider->setSingleStep(10);
        img_compression_Slider->setPageStep(10);
        img_compression_Slider->setValue(75);
        img_compression_Slider->setSliderPosition(75);
        img_compression_Slider->setTracking(true);
        img_compression_Slider->setOrientation(Qt::Horizontal);
        img_compression_Slider->setInvertedAppearance(false);
        img_compression_Slider->setTickPosition(QSlider::TicksBelow);
        img_compression_Slider->setTickInterval(10);

        verticalLayout->addWidget(img_compression_Slider);


        horizontalLayout_7->addLayout(verticalLayout);

        horizontalSpacer_9 = new QSpacerItem(13, 51, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_4 = new QLabel(Android_Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setFrameShadow(QFrame::Plain);

        verticalLayout_8->addWidget(label_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        size_image_label = new QLabel(Android_Dialog);
        size_image_label->setObjectName(QString::fromUtf8("size_image_label"));
        size_image_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(size_image_label);

        horizontalSpacer_6 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        label_9 = new QLabel(Android_Dialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_6->addWidget(label_9);


        verticalLayout_8->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_8);

        horizontalSpacer_8 = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout_14->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        video_label = new QLabel(Android_Dialog);
        video_label->setObjectName(QString::fromUtf8("video_label"));
        video_label->setMinimumSize(QSize(300, 300));
        video_label->setLayoutDirection(Qt::LeftToRight);
        video_label->setScaledContents(true);
        video_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(video_label);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);


        verticalLayout_14->addLayout(horizontalLayout_8);

        label_2 = new QLabel(Android_Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        sensors_start_btn = new QPushButton(Android_Dialog);
        sensors_start_btn->setObjectName(QString::fromUtf8("sensors_start_btn"));

        verticalLayout_3->addWidget(sensors_start_btn);

        sensors_stop_btn = new QPushButton(Android_Dialog);
        sensors_stop_btn->setObjectName(QString::fromUtf8("sensors_stop_btn"));

        verticalLayout_3->addWidget(sensors_stop_btn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sensors_port_label = new QLabel(Android_Dialog);
        sensors_port_label->setObjectName(QString::fromUtf8("sensors_port_label"));

        horizontalLayout_2->addWidget(sensors_port_label);

        sensors_port_lineEdit = new QLineEdit(Android_Dialog);
        sensors_port_lineEdit->setObjectName(QString::fromUtf8("sensors_port_lineEdit"));
        sensors_port_lineEdit->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sensors_port_lineEdit->sizePolicy().hasHeightForWidth());
        sensors_port_lineEdit->setSizePolicy(sizePolicy);
        sensors_port_lineEdit->setMaximumSize(QSize(50, 16777215));
        sensors_port_lineEdit->setMaxLength(6);

        horizontalLayout_2->addWidget(sensors_port_lineEdit);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_4);

        sensors_vals_label = new QLabel(Android_Dialog);
        sensors_vals_label->setObjectName(QString::fromUtf8("sensors_vals_label"));
        sensors_vals_label->setMinimumSize(QSize(400, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Optima"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        sensors_vals_label->setFont(font1);

        horizontalLayout_3->addWidget(sensors_vals_label);


        verticalLayout_14->addLayout(horizontalLayout_3);


        horizontalLayout_22->addLayout(verticalLayout_14);

        line = new QFrame(Android_Dialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_22->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_21 = new QLabel(Android_Dialog);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font);
        label_21->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_21);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        ioio_start_btn = new QPushButton(Android_Dialog);
        ioio_start_btn->setObjectName(QString::fromUtf8("ioio_start_btn"));

        verticalLayout_10->addWidget(ioio_start_btn);

        ioio_stop_btn = new QPushButton(Android_Dialog);
        ioio_stop_btn->setObjectName(QString::fromUtf8("ioio_stop_btn"));

        verticalLayout_10->addWidget(ioio_stop_btn);


        horizontalLayout_11->addLayout(verticalLayout_10);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        ioio_port_label = new QLabel(Android_Dialog);
        ioio_port_label->setObjectName(QString::fromUtf8("ioio_port_label"));

        horizontalLayout_10->addWidget(ioio_port_label);

        ioio_port_lineEdit = new QLineEdit(Android_Dialog);
        ioio_port_lineEdit->setObjectName(QString::fromUtf8("ioio_port_lineEdit"));
        ioio_port_lineEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(ioio_port_lineEdit->sizePolicy().hasHeightForWidth());
        ioio_port_lineEdit->setSizePolicy(sizePolicy);
        ioio_port_lineEdit->setMaximumSize(QSize(50, 16777215));
        ioio_port_lineEdit->setMaxLength(6);

        horizontalLayout_10->addWidget(ioio_port_lineEdit);


        verticalLayout_9->addLayout(horizontalLayout_10);

        ioio_inv_checkBox = new QCheckBox(Android_Dialog);
        ioio_inv_checkBox->setObjectName(QString::fromUtf8("ioio_inv_checkBox"));
        ioio_inv_checkBox->setChecked(true);

        verticalLayout_9->addWidget(ioio_inv_checkBox);

        line_4 = new QFrame(Android_Dialog);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_4);


        horizontalLayout_11->addLayout(verticalLayout_9);


        horizontalLayout_4->addLayout(horizontalLayout_11);

        mode_groupBox = new QGroupBox(Android_Dialog);
        mode_groupBox->setObjectName(QString::fromUtf8("mode_groupBox"));
        rc_radioButton = new QRadioButton(mode_groupBox);
        rc_radioButton->setObjectName(QString::fromUtf8("rc_radioButton"));
        rc_radioButton->setGeometry(QRect(0, 40, 102, 20));
        explore_radioButton = new QRadioButton(mode_groupBox);
        explore_radioButton->setObjectName(QString::fromUtf8("explore_radioButton"));
        explore_radioButton->setGeometry(QRect(90, 40, 102, 20));

        horizontalLayout_4->addWidget(mode_groupBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_15 = new QLabel(Android_Dialog);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QFont font2;
        font2.setPointSize(12);
        label_15->setFont(font2);
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_15);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_17 = new QLabel(Android_Dialog);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_12->addWidget(label_17);

        motor_min_lineEdit = new QLineEdit(Android_Dialog);
        motor_min_lineEdit->setObjectName(QString::fromUtf8("motor_min_lineEdit"));
        motor_min_lineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_12->addWidget(motor_min_lineEdit);


        verticalLayout_12->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_23 = new QLabel(Android_Dialog);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_13->addWidget(label_23);

        motor_max_lineEdit = new QLineEdit(Android_Dialog);
        motor_max_lineEdit->setObjectName(QString::fromUtf8("motor_max_lineEdit"));
        motor_max_lineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_13->addWidget(motor_max_lineEdit);


        verticalLayout_12->addLayout(horizontalLayout_13);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_28 = new QLabel(Android_Dialog);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_9->addWidget(label_28);

        default_motor_lineEdit = new QLineEdit(Android_Dialog);
        default_motor_lineEdit->setObjectName(QString::fromUtf8("default_motor_lineEdit"));
        default_motor_lineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_9->addWidget(default_motor_lineEdit);


        verticalLayout_12->addLayout(horizontalLayout_9);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_30 = new QLabel(Android_Dialog);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_17->addWidget(label_30);

        step_motor_lineEdit = new QLineEdit(Android_Dialog);
        step_motor_lineEdit->setObjectName(QString::fromUtf8("step_motor_lineEdit"));
        step_motor_lineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_17->addWidget(step_motor_lineEdit);


        verticalLayout_12->addLayout(horizontalLayout_17);


        horizontalLayout_19->addLayout(verticalLayout_12);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_16 = new QLabel(Android_Dialog);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font2);
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_16);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_25 = new QLabel(Android_Dialog);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_14->addWidget(label_25);

        servo_min_lineEdit = new QLineEdit(Android_Dialog);
        servo_min_lineEdit->setObjectName(QString::fromUtf8("servo_min_lineEdit"));
        servo_min_lineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_14->addWidget(servo_min_lineEdit);


        verticalLayout_11->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_24 = new QLabel(Android_Dialog);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_15->addWidget(label_24);

        servo_max_lineEdit = new QLineEdit(Android_Dialog);
        servo_max_lineEdit->setObjectName(QString::fromUtf8("servo_max_lineEdit"));
        servo_max_lineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_15->addWidget(servo_max_lineEdit);


        verticalLayout_11->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_29 = new QLabel(Android_Dialog);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_16->addWidget(label_29);

        default_servo_lineEdit = new QLineEdit(Android_Dialog);
        default_servo_lineEdit->setObjectName(QString::fromUtf8("default_servo_lineEdit"));
        default_servo_lineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_16->addWidget(default_servo_lineEdit);


        verticalLayout_11->addLayout(horizontalLayout_16);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_31 = new QLabel(Android_Dialog);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_18->addWidget(label_31);

        step_servo_lineEdit = new QLineEdit(Android_Dialog);
        step_servo_lineEdit->setObjectName(QString::fromUtf8("step_servo_lineEdit"));
        step_servo_lineEdit->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_18->addWidget(step_servo_lineEdit);


        verticalLayout_11->addLayout(horizontalLayout_18);


        horizontalLayout_19->addLayout(verticalLayout_11);


        horizontalLayout_20->addLayout(horizontalLayout_19);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        ioio_label_2 = new QLabel(Android_Dialog);
        ioio_label_2->setObjectName(QString::fromUtf8("ioio_label_2"));
        ioio_label_2->setFont(font2);
        ioio_label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(ioio_label_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        left_label = new QLabel(Android_Dialog);
        left_label->setObjectName(QString::fromUtf8("left_label"));
        left_label->setLayoutDirection(Qt::LeftToRight);
        left_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(left_label, 1, 1, 1, 1);

        right_label = new QLabel(Android_Dialog);
        right_label->setObjectName(QString::fromUtf8("right_label"));
        right_label->setLayoutDirection(Qt::LeftToRight);
        right_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(right_label, 1, 3, 1, 1);

        up_label = new QLabel(Android_Dialog);
        up_label->setObjectName(QString::fromUtf8("up_label"));
        up_label->setLayoutDirection(Qt::LeftToRight);
        up_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(up_label, 0, 2, 1, 1);

        motor_progressBar = new QProgressBar(Android_Dialog);
        motor_progressBar->setObjectName(QString::fromUtf8("motor_progressBar"));
        motor_progressBar->setMinimum(1000);
        motor_progressBar->setMaximum(2000);
        motor_progressBar->setValue(1500);
        motor_progressBar->setOrientation(Qt::Vertical);

        gridLayout_4->addWidget(motor_progressBar, 0, 0, 4, 1);

        down_label = new QLabel(Android_Dialog);
        down_label->setObjectName(QString::fromUtf8("down_label"));
        down_label->setLayoutDirection(Qt::LeftToRight);
        down_label->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(down_label, 2, 2, 1, 1);

        servo_progressBar = new QProgressBar(Android_Dialog);
        servo_progressBar->setObjectName(QString::fromUtf8("servo_progressBar"));
        servo_progressBar->setMinimum(1000);
        servo_progressBar->setMaximum(2000);
        servo_progressBar->setValue(1500);
        servo_progressBar->setTextVisible(false);

        gridLayout_4->addWidget(servo_progressBar, 3, 1, 1, 3);


        verticalLayout_13->addLayout(gridLayout_4);


        horizontalLayout_20->addLayout(verticalLayout_13);


        verticalLayout_2->addLayout(horizontalLayout_20);

        ioio_values_label = new QLabel(Android_Dialog);
        ioio_values_label->setObjectName(QString::fromUtf8("ioio_values_label"));
        ioio_values_label->setMinimumSize(QSize(200, 500));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Optima"));
        font3.setPointSize(12);
        ioio_values_label->setFont(font3);

        verticalLayout_2->addWidget(ioio_values_label);


        horizontalLayout_22->addLayout(verticalLayout_2);


        verticalLayout_15->addLayout(horizontalLayout_22);


        horizontalLayout_23->addLayout(verticalLayout_15);


        retranslateUi(Android_Dialog);

        QMetaObject::connectSlotsByName(Android_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Android_Dialog)
    {
        Android_Dialog->setWindowTitle(QApplication::translate("Android_Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Android_Dialog", "Name: ", 0, QApplication::UnicodeUTF8));
        phone_label->setText(QApplication::translate("Android_Dialog", "...", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Android_Dialog", "IP: ", 0, QApplication::UnicodeUTF8));
        IP_label->setText(QApplication::translate("Android_Dialog", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Android_Dialog", "CAMERA", 0, QApplication::UnicodeUTF8));
        camera_start_btn->setText(QApplication::translate("Android_Dialog", "Start", 0, QApplication::UnicodeUTF8));
        camera_stop_btn->setText(QApplication::translate("Android_Dialog", "Stop", 0, QApplication::UnicodeUTF8));
        port_cam_label->setText(QApplication::translate("Android_Dialog", "Port:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Android_Dialog", "Size:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Android_Dialog", "Quality:", 0, QApplication::UnicodeUTF8));
        compr_rate_label->setText(QApplication::translate("Android_Dialog", "75", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Android_Dialog", "Size image received:", 0, QApplication::UnicodeUTF8));
        size_image_label->setText(QApplication::translate("Android_Dialog", "0", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Android_Dialog", "bytes", 0, QApplication::UnicodeUTF8));
        video_label->setText(QApplication::translate("Android_Dialog", "VIDEO", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Android_Dialog", "SENSORS", 0, QApplication::UnicodeUTF8));
        sensors_start_btn->setText(QApplication::translate("Android_Dialog", "Start", 0, QApplication::UnicodeUTF8));
        sensors_stop_btn->setText(QApplication::translate("Android_Dialog", "Stop", 0, QApplication::UnicodeUTF8));
        sensors_port_label->setText(QApplication::translate("Android_Dialog", "Port:", 0, QApplication::UnicodeUTF8));
        sensors_vals_label->setText(QApplication::translate("Android_Dialog", "values", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Android_Dialog", "IOIO", 0, QApplication::UnicodeUTF8));
        ioio_start_btn->setText(QApplication::translate("Android_Dialog", "Start", 0, QApplication::UnicodeUTF8));
        ioio_stop_btn->setText(QApplication::translate("Android_Dialog", "Stop", 0, QApplication::UnicodeUTF8));
        ioio_port_label->setText(QApplication::translate("Android_Dialog", "Port:", 0, QApplication::UnicodeUTF8));
        ioio_inv_checkBox->setText(QApplication::translate("Android_Dialog", "Inverted", 0, QApplication::UnicodeUTF8));
        mode_groupBox->setTitle(QApplication::translate("Android_Dialog", "Robot Mode", 0, QApplication::UnicodeUTF8));
        rc_radioButton->setText(QApplication::translate("Android_Dialog", "RC ", 0, QApplication::UnicodeUTF8));
        explore_radioButton->setText(QApplication::translate("Android_Dialog", "Explore", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Android_Dialog", "Motor", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Android_Dialog", "Min", 0, QApplication::UnicodeUTF8));
        motor_min_lineEdit->setText(QApplication::translate("Android_Dialog", "1300", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("Android_Dialog", "Max", 0, QApplication::UnicodeUTF8));
        motor_max_lineEdit->setText(QApplication::translate("Android_Dialog", "1700", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("Android_Dialog", "Default", 0, QApplication::UnicodeUTF8));
        default_motor_lineEdit->setText(QApplication::translate("Android_Dialog", "1500", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("Android_Dialog", "Step", 0, QApplication::UnicodeUTF8));
        step_motor_lineEdit->setText(QApplication::translate("Android_Dialog", "50", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Android_Dialog", "Servo", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("Android_Dialog", "Min", 0, QApplication::UnicodeUTF8));
        servo_min_lineEdit->setText(QApplication::translate("Android_Dialog", "1000", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Android_Dialog", "Max", 0, QApplication::UnicodeUTF8));
        servo_max_lineEdit->setText(QApplication::translate("Android_Dialog", "2000", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("Android_Dialog", "Default", 0, QApplication::UnicodeUTF8));
        default_servo_lineEdit->setText(QApplication::translate("Android_Dialog", "1500", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("Android_Dialog", "Step", 0, QApplication::UnicodeUTF8));
        step_servo_lineEdit->setText(QApplication::translate("Android_Dialog", "100", 0, QApplication::UnicodeUTF8));
        ioio_label_2->setText(QApplication::translate("Android_Dialog", "Commands", 0, QApplication::UnicodeUTF8));
        left_label->setText(QApplication::translate("Android_Dialog", "LEFT", 0, QApplication::UnicodeUTF8));
        right_label->setText(QApplication::translate("Android_Dialog", "RIGHT", 0, QApplication::UnicodeUTF8));
        up_label->setText(QApplication::translate("Android_Dialog", "FOWARD", 0, QApplication::UnicodeUTF8));
        down_label->setText(QApplication::translate("Android_Dialog", "BACKWARD", 0, QApplication::UnicodeUTF8));
        ioio_values_label->setText(QApplication::translate("Android_Dialog", "values", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Android_Dialog: public Ui_Android_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANDROID_DIALOG_H
