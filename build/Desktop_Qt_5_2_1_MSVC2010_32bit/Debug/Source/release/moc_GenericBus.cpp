/****************************************************************************
** Meta object code from reading C++ file 'GenericBus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Bus/GenericBus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GenericBus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__GenericBus_t {
    QByteArrayData data[9];
    char stringdata[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__GenericBus_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__GenericBus_t qt_meta_stringdata_RsaToolbox__GenericBus = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 5),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 5),
QT_MOC_LITERAL(4, 36, 4),
QT_MOC_LITERAL(5, 41, 4),
QT_MOC_LITERAL(6, 46, 6),
QT_MOC_LITERAL(7, 53, 5),
QT_MOC_LITERAL(8, 59, 6)
    },
    "RsaToolbox::GenericBus\0error\0\0print\0"
    "text\0lock\0unlock\0local\0remote\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__GenericBus[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06,
       3,    1,   45,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x0a,
       6,    0,   49,    2, 0x0a,
       7,    0,   50,    2, 0x0a,
       8,    0,   51,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

void RsaToolbox::GenericBus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GenericBus *_t = static_cast<GenericBus *>(_o);
        switch (_id) {
        case 0: _t->error(); break;
        case 1: _t->print((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: { bool _r = _t->lock();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->unlock();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->local();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->remote();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GenericBus::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenericBus::error)) {
                *result = 0;
            }
        }
        {
            typedef void (GenericBus::*_t)(QString ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenericBus::print)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject RsaToolbox::GenericBus::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RsaToolbox__GenericBus.data,
      qt_meta_data_RsaToolbox__GenericBus,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::GenericBus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::GenericBus::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__GenericBus.stringdata))
        return static_cast<void*>(const_cast< GenericBus*>(this));
    return QObject::qt_metacast(_clname);
}

int RsaToolbox::GenericBus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RsaToolbox::GenericBus::error()const
{
    QMetaObject::activate(const_cast< RsaToolbox::GenericBus *>(this), &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RsaToolbox::GenericBus::print(QString _t1)const
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< RsaToolbox::GenericBus *>(this), &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
