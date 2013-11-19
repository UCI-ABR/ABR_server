/****************************************************************************
** Meta object code from reading C++ file 'phone_item.h'
**
** Created: Fri Oct 26 15:42:27 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../phone_item.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'phone_item.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Phone_item[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   26,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Phone_item[] = {
    "Phone_item\0\0show_dialog()\0pix,size\0"
    "display_pix(QPixmap,int)\0"
};

const QMetaObject Phone_item::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Phone_item,
      qt_meta_data_Phone_item, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Phone_item::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Phone_item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Phone_item::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Phone_item))
        return static_cast<void*>(const_cast< Phone_item*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< Phone_item*>(this));
    return QObject::qt_metacast(_clname);
}

int Phone_item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: show_dialog(); break;
        case 1: display_pix((*reinterpret_cast< QPixmap(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Phone_item::show_dialog()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
