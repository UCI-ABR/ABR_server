/****************************************************************************
** Meta object code from reading C++ file 'nn_udp_object.h'
**
** Created: Wed Jun 26 14:10:06 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "nn_udp_object.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nn_udp_object.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NN_udp_object[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   14,   14,   14, 0x0a,
      49,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NN_udp_object[] = {
    "NN_udp_object\0\0values_ready(QString)\0"
    "read_data()\0close_socket()\0"
};

const QMetaObject NN_udp_object::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NN_udp_object,
      qt_meta_data_NN_udp_object, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NN_udp_object::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NN_udp_object::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NN_udp_object::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NN_udp_object))
        return static_cast<void*>(const_cast< NN_udp_object*>(this));
    return QObject::qt_metacast(_clname);
}

int NN_udp_object::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: values_ready((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: read_data(); break;
        case 2: close_socket(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void NN_udp_object::values_ready(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
