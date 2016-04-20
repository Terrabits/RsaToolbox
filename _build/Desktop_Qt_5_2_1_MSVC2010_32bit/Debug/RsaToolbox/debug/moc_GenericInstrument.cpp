/****************************************************************************
** Meta object code from reading C++ file 'GenericInstrument.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../RsaToolbox/Instruments/GenericInstrument.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GenericInstrument.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__GenericInstrument_t {
    QByteArrayData data[11];
    char stringdata[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__GenericInstrument_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__GenericInstrument_t qt_meta_stringdata_RsaToolbox__GenericInstrument = {
    {
QT_MOC_LITERAL(0, 0, 29),
QT_MOC_LITERAL(1, 30, 8),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 9),
QT_MOC_LITERAL(4, 50, 12),
QT_MOC_LITERAL(5, 63, 4),
QT_MOC_LITERAL(6, 68, 6),
QT_MOC_LITERAL(7, 75, 5),
QT_MOC_LITERAL(8, 81, 6),
QT_MOC_LITERAL(9, 88, 6),
QT_MOC_LITERAL(10, 95, 11)
    },
    "RsaToolbox::GenericInstrument\0busError\0"
    "\0connected\0disconnected\0lock\0unlock\0"
    "local\0remote\0preset\0clearStatus\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__GenericInstrument[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06,
       3,    0,   60,    2, 0x06,
       4,    0,   61,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x0a,
       6,    0,   63,    2, 0x0a,
       7,    0,   64,    2, 0x0a,
       8,    0,   65,    2, 0x0a,
       9,    0,   66,    2, 0x0a,
      10,    0,   67,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RsaToolbox::GenericInstrument::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GenericInstrument *_t = static_cast<GenericInstrument *>(_o);
        switch (_id) {
        case 0: _t->busError(); break;
        case 1: _t->connected(); break;
        case 2: _t->disconnected(); break;
        case 3: { bool _r = _t->lock();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->unlock();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->local();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->remote();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->preset(); break;
        case 8: _t->clearStatus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GenericInstrument::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenericInstrument::busError)) {
                *result = 0;
            }
        }
        {
            typedef void (GenericInstrument::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenericInstrument::connected)) {
                *result = 1;
            }
        }
        {
            typedef void (GenericInstrument::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenericInstrument::disconnected)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject RsaToolbox::GenericInstrument::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RsaToolbox__GenericInstrument.data,
      qt_meta_data_RsaToolbox__GenericInstrument,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::GenericInstrument::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::GenericInstrument::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__GenericInstrument.stringdata))
        return static_cast<void*>(const_cast< GenericInstrument*>(this));
    return QObject::qt_metacast(_clname);
}

int RsaToolbox::GenericInstrument::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void RsaToolbox::GenericInstrument::busError()const
{
    QMetaObject::activate(const_cast< RsaToolbox::GenericInstrument *>(this), &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RsaToolbox::GenericInstrument::connected()const
{
    QMetaObject::activate(const_cast< RsaToolbox::GenericInstrument *>(this), &staticMetaObject, 1, 0);
}

// SIGNAL 2
void RsaToolbox::GenericInstrument::disconnected()const
{
    QMetaObject::activate(const_cast< RsaToolbox::GenericInstrument *>(this), &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
