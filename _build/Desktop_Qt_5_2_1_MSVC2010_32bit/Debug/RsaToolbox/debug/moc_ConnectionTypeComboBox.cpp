/****************************************************************************
** Meta object code from reading C++ file 'ConnectionTypeComboBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../RsaToolbox/Gui/ConnectionTypeComboBox/ConnectionTypeComboBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConnectionTypeComboBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__ConnectionTypeComboBox_t {
    QByteArrayData data[8];
    char stringdata[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__ConnectionTypeComboBox_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__ConnectionTypeComboBox_t qt_meta_stringdata_RsaToolbox__ConnectionTypeComboBox = {
    {
QT_MOC_LITERAL(0, 0, 34),
QT_MOC_LITERAL(1, 35, 18),
QT_MOC_LITERAL(2, 54, 0),
QT_MOC_LITERAL(3, 55, 14),
QT_MOC_LITERAL(4, 70, 7),
QT_MOC_LITERAL(5, 78, 14),
QT_MOC_LITERAL(6, 93, 4),
QT_MOC_LITERAL(7, 98, 11)
    },
    "RsaToolbox::ConnectionTypeComboBox\0"
    "currentTypeChanged\0\0ConnectionType\0"
    "newType\0setCurrentType\0type\0currentType\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__ConnectionTypeComboBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   30, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   27,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    6,

 // properties: name, type, flags
       7, 0x80000000 | 3, 0x0049510b,

 // properties: notify_signal_id
       0,

       0        // eod
};

void RsaToolbox::ConnectionTypeComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConnectionTypeComboBox *_t = static_cast<ConnectionTypeComboBox *>(_o);
        switch (_id) {
        case 0: _t->currentTypeChanged((*reinterpret_cast< ConnectionType(*)>(_a[1]))); break;
        case 1: _t->setCurrentType((*reinterpret_cast< ConnectionType(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ConnectionTypeComboBox::*_t)(ConnectionType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConnectionTypeComboBox::currentTypeChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject RsaToolbox::ConnectionTypeComboBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_RsaToolbox__ConnectionTypeComboBox.data,
      qt_meta_data_RsaToolbox__ConnectionTypeComboBox,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::ConnectionTypeComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::ConnectionTypeComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__ConnectionTypeComboBox.stringdata))
        return static_cast<void*>(const_cast< ConnectionTypeComboBox*>(this));
    return QComboBox::qt_metacast(_clname);
}

int RsaToolbox::ConnectionTypeComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ConnectionType*>(_v) = currentType(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCurrentType(*reinterpret_cast< ConnectionType*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void RsaToolbox::ConnectionTypeComboBox::currentTypeChanged(ConnectionType _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
