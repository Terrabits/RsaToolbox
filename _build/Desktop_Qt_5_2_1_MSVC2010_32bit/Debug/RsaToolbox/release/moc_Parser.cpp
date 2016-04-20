/****************************************************************************
** Meta object code from reading C++ file 'Parser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../RsaToolbox/Server/Parser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Parser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__Parser_t {
    QByteArrayData data[11];
    char stringdata[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__Parser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__Parser_t qt_meta_stringdata_RsaToolbox__Parser = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 5),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 5),
QT_MOC_LITERAL(4, 32, 15),
QT_MOC_LITERAL(5, 48, 7),
QT_MOC_LITERAL(6, 56, 7),
QT_MOC_LITERAL(7, 64, 5),
QT_MOC_LITERAL(8, 70, 7),
QT_MOC_LITERAL(9, 78, 4),
QT_MOC_LITERAL(10, 83, 11)
    },
    "RsaToolbox::Parser\0write\0\0bytes\0"
    "receivedCommand\0Command\0command\0error\0"
    "message\0read\0QByteArray&\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__Parser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06,
       4,    1,   37,    2, 0x06,
       7,    1,   40,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       9,    1,   43,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,    3,

       0        // eod
};

void RsaToolbox::Parser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Parser *_t = static_cast<Parser *>(_o);
        switch (_id) {
        case 0: _t->write((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 1: _t->receivedCommand((*reinterpret_cast< const Command(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->read((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Parser::*_t)(const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Parser::write)) {
                *result = 0;
            }
        }
        {
            typedef void (Parser::*_t)(const Command & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Parser::receivedCommand)) {
                *result = 1;
            }
        }
        {
            typedef void (Parser::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Parser::error)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject RsaToolbox::Parser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RsaToolbox__Parser.data,
      qt_meta_data_RsaToolbox__Parser,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::Parser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::Parser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__Parser.stringdata))
        return static_cast<void*>(const_cast< Parser*>(this));
    return QObject::qt_metacast(_clname);
}

int RsaToolbox::Parser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void RsaToolbox::Parser::write(const QByteArray & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RsaToolbox::Parser::receivedCommand(const Command & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RsaToolbox::Parser::error(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
