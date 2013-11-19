/****************************************************************************
** Meta object code from reading C++ file 'phone_thread.h'
**
** Created: Fri Apr 13 11:12:41 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../phone_thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'phone_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Phone_thread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   14,   13,   13, 0x05,
      50,   46,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   13,   13,   13, 0x0a,
      86,   13,   13,   13, 0x0a,
     106,   13,   13,   13, 0x0a,
     129,  125,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Phone_thread[] = {
    "Phone_thread\0\0thread\0new_phone(Phone_thread*)\0"
    "idx\0phone_disconnected(int)\0Read_data()\0"
    "disconnected_slot()\0disconnect_phone()\0"
    "msg\0send_message(QString)\0"
};

const QMetaObject Phone_thread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Phone_thread,
      qt_meta_data_Phone_thread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Phone_thread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Phone_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Phone_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Phone_thread))
        return static_cast<void*>(const_cast< Phone_thread*>(this));
    return QObject::qt_metacast(_clname);
}

int Phone_thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: new_phone((*reinterpret_cast< Phone_thread*(*)>(_a[1]))); break;
        case 1: phone_disconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: Read_data(); break;
        case 3: disconnected_slot(); break;
        case 4: disconnect_phone(); break;
        case 5: send_message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Phone_thread::new_phone(Phone_thread * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Phone_thread::phone_disconnected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
