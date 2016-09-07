/****************************************************************************
** Meta object code from reading C++ file 'Log.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Log/Log.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Log.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__Log_t {
    QByteArrayData data[13];
    char stringdata[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__Log_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__Log_t qt_meta_stringdata_RsaToolbox__Log = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 6),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 6),
QT_MOC_LITERAL(4, 31, 7),
QT_MOC_LITERAL(5, 39, 8),
QT_MOC_LITERAL(6, 48, 4),
QT_MOC_LITERAL(7, 53, 5),
QT_MOC_LITERAL(8, 59, 6),
QT_MOC_LITERAL(9, 66, 11),
QT_MOC_LITERAL(10, 78, 5),
QT_MOC_LITERAL(11, 84, 4),
QT_MOC_LITERAL(12, 89, 9)
    },
    "RsaToolbox::Log\0closed\0\0opened\0renamed\0"
    "pathName\0open\0close\0rename\0printHeader\0"
    "print\0text\0printLine\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__Log[] = {

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
       4,    1,   61,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   64,    2, 0x0a,
       7,    0,   65,    2, 0x0a,
       8,    1,   66,    2, 0x0a,
       9,    0,   69,    2, 0x0a,
      10,    1,   70,    2, 0x0a,
      12,    1,   73,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    5,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString,   11,
    QMetaType::Bool, QMetaType::QString,   11,

       0        // eod
};

void RsaToolbox::Log::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Log *_t = static_cast<Log *>(_o);
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->opened(); break;
        case 2: _t->renamed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: { bool _r = _t->open();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->close(); break;
        case 5: { bool _r = _t->rename((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->printHeader();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->print((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->printLine((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Log::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Log::closed)) {
                *result = 0;
            }
        }
        {
            typedef void (Log::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Log::opened)) {
                *result = 1;
            }
        }
        {
            typedef void (Log::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Log::renamed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject RsaToolbox::Log::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RsaToolbox__Log.data,
      qt_meta_data_RsaToolbox__Log,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::Log::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::Log::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__Log.stringdata))
        return static_cast<void*>(const_cast< Log*>(this));
    return QObject::qt_metacast(_clname);
}

int RsaToolbox::Log::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RsaToolbox::Log::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RsaToolbox::Log::opened()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void RsaToolbox::Log::renamed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
