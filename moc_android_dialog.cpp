/****************************************************************************
** Meta object code from reading C++ file 'android_dialog.h'
**
** Created: Tue Nov 19 09:04:19 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "android_dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'android_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Android_Dialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      39,   15,   15,   15, 0x05,
      61,   15,   15,   15, 0x05,
      82,   15,   15,   15, 0x05,
     102,   15,   15,   15, 0x05,
     122,   15,   15,   15, 0x05,
     141,   15,   15,   15, 0x05,
     157,   15,   15,   15, 0x05,
     177,   15,   15,   15, 0x05,
     194,   15,   15,   15, 0x05,
     217,   15,   15,   15, 0x05,
     240,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     264,   15,   15,   15, 0x0a,
     286,   15,   15,   15, 0x0a,
     307,   15,   15,   15, 0x0a,
     328,   15,   15,   15, 0x0a,
     348,   15,   15,   15, 0x0a,
     367,   15,   15,   15, 0x0a,
     390,  385,   15,   15, 0x0a,
     418,  409,   15,   15, 0x0a,
     451,  444,   15,   15, 0x0a,
     476,  444,   15,   15, 0x0a,
     496,   15,   15,   15, 0x0a,
     511,   15,   15,   15, 0x0a,
     523,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Android_Dialog[] = {
    "Android_Dialog\0\0start_sensors(QString)\0"
    "stop_sensors(QString)\0start_video(QString)\0"
    "stop_video(QString)\0start_ioio(QString)\0"
    "stop_ioio(QString)\0close_upd_cam()\0"
    "close_upd_sensors()\0close_upd_ioio()\0"
    "send_img_rate(QString)\0send_ioio_pwm(QString)\0"
    "send_ioio_mode(QString)\0start_sensors_phone()\0"
    "stop_sensors_phone()\0start_camera_phone()\0"
    "stop_camera_phone()\0start_ioio_phone()\0"
    "stop_ioio_phone()\0rate\0set_comp_rate(int)\0"
    "ima,size\0display_frame(QImage,int)\0"
    "values\0display_sensors(QString)\0"
    "display_IR(QString)\0upd_ioio_pwm()\0"
    "save_data()\0set_mode()\0"
};

const QMetaObject Android_Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Android_Dialog,
      qt_meta_data_Android_Dialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Android_Dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Android_Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Android_Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Android_Dialog))
        return static_cast<void*>(const_cast< Android_Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Android_Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: start_sensors((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: stop_sensors((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: start_video((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: stop_video((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: start_ioio((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: stop_ioio((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: close_upd_cam(); break;
        case 7: close_upd_sensors(); break;
        case 8: close_upd_ioio(); break;
        case 9: send_img_rate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: send_ioio_pwm((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: send_ioio_mode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: start_sensors_phone(); break;
        case 13: stop_sensors_phone(); break;
        case 14: start_camera_phone(); break;
        case 15: stop_camera_phone(); break;
        case 16: start_ioio_phone(); break;
        case 17: stop_ioio_phone(); break;
        case 18: set_comp_rate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: display_frame((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: display_sensors((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: display_IR((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: upd_ioio_pwm(); break;
        case 23: save_data(); break;
        case 24: set_mode(); break;
        default: ;
        }
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void Android_Dialog::start_sensors(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Android_Dialog::stop_sensors(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Android_Dialog::start_video(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Android_Dialog::stop_video(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Android_Dialog::start_ioio(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Android_Dialog::stop_ioio(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Android_Dialog::close_upd_cam()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Android_Dialog::close_upd_sensors()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void Android_Dialog::close_upd_ioio()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void Android_Dialog::send_img_rate(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Android_Dialog::send_ioio_pwm(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Android_Dialog::send_ioio_mode(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_END_MOC_NAMESPACE
