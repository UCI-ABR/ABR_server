/****************************************************************************
** Meta object code from reading C++ file 'camera_udp_object.h'
**
** Created: Tue Nov 19 09:04:20 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "camera_udp_object.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camera_udp_object.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Camera_UDP_Object[] = {

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
      33,   19,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   18,   18,   18, 0x0a,
      70,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Camera_UDP_Object[] = {
    "Camera_UDP_Object\0\0pix,size_data\0"
    "frame_ready(QImage,int)\0read_image()\0"
    "close_socket()\0"
};

const QMetaObject Camera_UDP_Object::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Camera_UDP_Object,
      qt_meta_data_Camera_UDP_Object, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Camera_UDP_Object::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Camera_UDP_Object::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Camera_UDP_Object::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Camera_UDP_Object))
        return static_cast<void*>(const_cast< Camera_UDP_Object*>(this));
    return QObject::qt_metacast(_clname);
}

int Camera_UDP_Object::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: frame_ready((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: read_image(); break;
        case 2: close_socket(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Camera_UDP_Object::frame_ready(QImage _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
