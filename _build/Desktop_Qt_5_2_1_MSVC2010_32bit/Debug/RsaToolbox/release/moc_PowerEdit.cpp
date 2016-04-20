/****************************************************************************
** Meta object code from reading C++ file 'PowerEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../RsaToolbox/Gui/PowerEdit/PowerEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PowerEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__PowerEdit_t {
    QByteArrayData data[11];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__PowerEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__PowerEdit_t qt_meta_stringdata_RsaToolbox__PowerEdit = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 10),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 7),
QT_MOC_LITERAL(4, 42, 12),
QT_MOC_LITERAL(5, 55, 9),
QT_MOC_LITERAL(6, 65, 11),
QT_MOC_LITERAL(7, 77, 7),
QT_MOC_LITERAL(8, 85, 4),
QT_MOC_LITERAL(9, 90, 8),
QT_MOC_LITERAL(10, 99, 19)
    },
    "RsaToolbox::PowerEdit\0outOfRange\0\0"
    "message\0powerChanged\0power_dBm\0"
    "PowerEdited\0setText\0text\0setPower\0"
    "handleReturnPressed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__PowerEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       4,    1,   47,    2, 0x06,
       6,    1,   50,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    1,   53,    2, 0x0a,
       9,    1,   56,    2, 0x0a,
      10,    0,   59,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void,

       0        // eod
};

void RsaToolbox::PowerEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowerEdit *_t = static_cast<PowerEdit *>(_o);
        switch (_id) {
        case 0: _t->outOfRange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->powerChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->PowerEdited((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setPower((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->handleReturnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PowerEdit::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PowerEdit::outOfRange)) {
                *result = 0;
            }
        }
        {
            typedef void (PowerEdit::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PowerEdit::powerChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (PowerEdit::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PowerEdit::PowerEdited)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject RsaToolbox::PowerEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_RsaToolbox__PowerEdit.data,
      qt_meta_data_RsaToolbox__PowerEdit,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::PowerEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::PowerEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__PowerEdit.stringdata))
        return static_cast<void*>(const_cast< PowerEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int RsaToolbox::PowerEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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
void RsaToolbox::PowerEdit::outOfRange(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RsaToolbox::PowerEdit::powerChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RsaToolbox::PowerEdit::PowerEdited(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
