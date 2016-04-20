/****************************************************************************
** Meta object code from reading C++ file 'Server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../RsaToolbox/Server/Server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__Server_t {
    QByteArrayData data[11];
    char stringdata[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__Server_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__Server_t qt_meta_stringdata_RsaToolbox__Server = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 7),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 9),
QT_MOC_LITERAL(4, 38, 7),
QT_MOC_LITERAL(5, 46, 13),
QT_MOC_LITERAL(6, 60, 17),
QT_MOC_LITERAL(7, 78, 4),
QT_MOC_LITERAL(8, 83, 5),
QT_MOC_LITERAL(9, 89, 4),
QT_MOC_LITERAL(10, 94, 12)
    },
    "RsaToolbox::Server\0running\0\0connected\0"
    "stopped\0sessionOpened\0connectionPending\0"
    "read\0write\0data\0disconnected\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__Server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06,
       3,    0,   55,    2, 0x06,
       4,    0,   56,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x08,
       6,    0,   58,    2, 0x08,
       7,    0,   59,    2, 0x08,
       8,    1,   60,    2, 0x08,
      10,    0,   63,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void,

       0        // eod
};

void RsaToolbox::Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Server *_t = static_cast<Server *>(_o);
        switch (_id) {
        case 0: _t->running(); break;
        case 1: _t->connected(); break;
        case 2: _t->stopped(); break;
        case 3: _t->sessionOpened(); break;
        case 4: _t->connectionPending(); break;
        case 5: _t->read(); break;
        case 6: _t->write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::running)) {
                *result = 0;
            }
        }
        {
            typedef void (Server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::connected)) {
                *result = 1;
            }
        }
        {
            typedef void (Server::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Server::stopped)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject RsaToolbox::Server::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RsaToolbox__Server.data,
      qt_meta_data_RsaToolbox__Server,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::Server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__Server.stringdata))
        return static_cast<void*>(const_cast< Server*>(this));
    return QObject::qt_metacast(_clname);
}

int RsaToolbox::Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void RsaToolbox::Server::running()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RsaToolbox::Server::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void RsaToolbox::Server::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
