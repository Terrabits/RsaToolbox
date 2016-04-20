/****************************************************************************
** Meta object code from reading C++ file 'TcpBus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../RsaToolbox/Bus/Tcp/TcpBus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpBus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__TcpBus_t {
    QByteArrayData data[6];
    char stringdata[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__TcpBus_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__TcpBus_t qt_meta_stringdata_RsaToolbox__TcpBus = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 4),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 6),
QT_MOC_LITERAL(4, 32, 5),
QT_MOC_LITERAL(5, 38, 6)
    },
    "RsaToolbox::TcpBus\0lock\0\0unlock\0local\0"
    "remote\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__TcpBus[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a,
       3,    0,   35,    2, 0x0a,
       4,    0,   36,    2, 0x0a,
       5,    0,   37,    2, 0x0a,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

void RsaToolbox::TcpBus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpBus *_t = static_cast<TcpBus *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->lock();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->unlock();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->local();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->remote();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject RsaToolbox::TcpBus::staticMetaObject = {
    { &GenericBus::staticMetaObject, qt_meta_stringdata_RsaToolbox__TcpBus.data,
      qt_meta_data_RsaToolbox__TcpBus,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::TcpBus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::TcpBus::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__TcpBus.stringdata))
        return static_cast<void*>(const_cast< TcpBus*>(this));
    return GenericBus::qt_metacast(_clname);
}

int RsaToolbox::TcpBus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GenericBus::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
