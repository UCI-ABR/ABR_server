/****************************************************************************
** Meta object code from reading C++ file 'ioio_udp_object.h'
**
** Created: Fri Oct 26 15:42:35 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ioio_udp_object.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ioio_udp_object.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IOIO_UDP_Object[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   16,   16,   16, 0x0a,
      71,   16,   16,   16, 0x0a,
      98,   86,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IOIO_UDP_Object[] = {
    "IOIO_UDP_Object\0\0,,,\0"
    "IR_val_ready(float,float,float,float)\0"
    "read_data()\0close_socket()\0motor,servo\0"
    "write_pwm_values(int,int)\0"
};

const QMetaObject IOIO_UDP_Object::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IOIO_UDP_Object,
      qt_meta_data_IOIO_UDP_Object, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IOIO_UDP_Object::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IOIO_UDP_Object::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IOIO_UDP_Object::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IOIO_UDP_Object))
        return static_cast<void*>(const_cast< IOIO_UDP_Object*>(this));
    return QObject::qt_metacast(_clname);
}

int IOIO_UDP_Object::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: IR_val_ready((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 1: read_data(); break;
        case 2: close_socket(); break;
        case 3: write_pwm_values((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void IOIO_UDP_Object::IR_val_ready(float _t1, float _t2, float _t3, float _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE