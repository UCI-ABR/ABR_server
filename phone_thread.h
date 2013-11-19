#ifndef PHONE_THREAD_H
#define PHONE_THREAD_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>

class Phone_thread : public QObject
{
    Q_OBJECT
public:
//    explicit Phone_thread(QObject *parent = 0, int ID=0, int nb=0);
    explicit Phone_thread();
    
signals:
//    void error(QTcpSocket::SocketError socketerror);
//    void new_phone(int idx, QString name_phone, QString IP_phone, quint16 port_phone);
    void new_phone(Phone_thread* thread);
    void phone_disconnected(int idx);

public slots:
    void Read_data();
    void disconnected_slot();
    void disconnect_phone();
    void send_message(QString msg);

public:
    QTcpSocket *socket;
    int socketDescriptor;

    QString name, IP;
    quint16 port_TCP, port_sensor, port_camera, port_IOIO;
    int idx_phone;
    void init(int ID, int nb);

};

#endif // PHONE_THREAD_H
