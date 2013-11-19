#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int ID, int nb, QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);
//    void new_phone(int idx, QString name_phone, QString IP_phone, quint16 port_phone);
    void new_phone(MyThread* thread);
    void phone_disconnected(int idx);

public slots:
    void readyRead();
    void disconnected();
    void start_sensors_phone();

public:
    QTcpSocket *socket;
    int socketDescriptor;

    QString name, IP;
    quint16 port_TCP, port_sensor, port_camera, port_IOIO;
    int idx_phone;
};

#endif // MYTHREAD_H
