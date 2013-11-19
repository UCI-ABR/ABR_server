#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QString>
#include <QHostAddress>
#include <QVector>

namespace Ui {
class Phone_dialog;
}

class Phone_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Phone_dialog(QWidget *parent = 0);
    ~Phone_dialog();
    
private:
    Ui::Phone_dialog *ui;

public:
    QString *name;
    QHostAddress *IP;
    quint16 port_TCP, port_sensor, port_camera, port_IOIO;

    QVector<QString*> cam_sizes;

    float acceleration, compass;
    int img_compression_rate;

public slots:
    void add_text(QString s);
};

#endif // MYDIALOG_H
