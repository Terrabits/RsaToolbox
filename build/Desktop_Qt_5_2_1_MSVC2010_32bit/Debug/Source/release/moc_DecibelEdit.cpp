/****************************************************************************
** Meta object code from reading C++ file 'DecibelEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Gui/DecibelEdit/DecibelEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DecibelEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__DecibelEdit_t {
    QByteArrayData data[11];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__DecibelEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__DecibelEdit_t qt_meta_stringdata_RsaToolbox__DecibelEdit = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 10),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 7),
QT_MOC_LITERAL(4, 44, 12),
QT_MOC_LITERAL(5, 57, 8),
QT_MOC_LITERAL(6, 66, 13),
QT_MOC_LITERAL(7, 80, 7),
QT_MOC_LITERAL(8, 88, 4),
QT_MOC_LITERAL(9, 93, 8),
QT_MOC_LITERAL(10, 102, 19)
    },
    "RsaToolbox::DecibelEdit\0outOfRange\0\0"
    "message\0valueChanged\0value_dB\0"
    "DecibelEdited\0setText\0text\0setValue\0"
    "handleReturnPressed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__DecibelEdit[] = {

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

void RsaToolbox::DecibelEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DecibelEdit *_t = static_cast<DecibelEdit *>(_o);
        switch (_id) {
        case 0: _t->outOfRange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->DecibelEdited((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->handleReturnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DecibelEdit::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DecibelEdit::outOfRange)) {
                *result = 0;
            }
        }
        {
            typedef void (DecibelEdit::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DecibelEdit::valueChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (DecibelEdit::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DecibelEdit::DecibelEdited)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject RsaToolbox::DecibelEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_RsaToolbox__DecibelEdit.data,
      qt_meta_data_RsaToolbox__DecibelEdit,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::DecibelEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::DecibelEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__DecibelEdit.stringdata))
        return static_cast<void*>(const_cast< DecibelEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int RsaToolbox::DecibelEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RsaToolbox::DecibelEdit::outOfRange(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RsaToolbox::DecibelEdit::valueChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RsaToolbox::DecibelEdit::DecibelEdited(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
