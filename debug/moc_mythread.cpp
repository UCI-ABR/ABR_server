/****************************************************************************
** Meta object code from reading C++ file 'mythread.h'
**
** Created: Fri Apr 13 11:12:29 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mythread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mythread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   10,    9,    9, 0x05,
      60,   53,    9,    9, 0x05,
      85,   81,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     109,    9,    9,    9, 0x0a,
     121,    9,    9,    9, 0x0a,
     136,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyThread[] = {
    "MyThread\0\0socketerror\0"
    "error(QTcpSocket::SocketError)\0thread\0"
    "new_phone(MyThread*)\0idx\0"
    "phone_disconnected(int)\0readyRead()\0"
    "disconnected()\0start_sensors_phone()\0"
};

const QMetaObject MyThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_MyThread,
      qt_meta_data_MyThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyThread))
        return static_cast<void*>(const_cast< MyThread*>(this));
    return QThread::qt_metacast(_clname);
}

int MyThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: error((*reinterpret_cast< QTcpSocket::SocketError(*)>(_a[1]))); break;
        case 1: new_phone((*reinterpret_cast< MyThread*(*)>(_a[1]))); break;
        case 2: phone_disconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: readyRead(); break;
        case 4: disconnected(); break;
        case 5: start_sensors_phone(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MyThread::error(QTcpSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyThread::new_phone(MyThread * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyThread::phone_disconnected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
