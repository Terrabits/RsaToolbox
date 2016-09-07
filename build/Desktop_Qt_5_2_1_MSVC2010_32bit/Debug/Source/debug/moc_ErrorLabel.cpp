/****************************************************************************
** Meta object code from reading C++ file 'ErrorLabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Gui/ErrorLabel/ErrorLabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ErrorLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__ErrorLabel_t {
    QByteArrayData data[7];
    char stringdata[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__ErrorLabel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__ErrorLabel_t qt_meta_stringdata_RsaToolbox__ErrorLabel = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 11),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 7),
QT_MOC_LITERAL(4, 44, 7),
QT_MOC_LITERAL(5, 52, 15),
QT_MOC_LITERAL(6, 68, 5)
    },
    "RsaToolbox::ErrorLabel\0showMessage\0\0"
    "message\0timeout\0Qt::GlobalColor\0color\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__ErrorLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x0a,
       1,    1,   49,    2, 0x2a,
       1,    3,   52,    2, 0x0a,
       1,    2,   59,    2, 0x2a,
       1,    3,   64,    2, 0x0a,
       1,    2,   71,    2, 0x2a,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, QMetaType::Int,    3,    6,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    3,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor, QMetaType::Int,    3,    6,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    3,    6,

       0        // eod
};

void RsaToolbox::ErrorLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ErrorLabel *_t = static_cast<ErrorLabel *>(_o);
        switch (_id) {
        case 0: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::GlobalColor(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< Qt::GlobalColor(*)>(_a[2]))); break;
        case 4: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject RsaToolbox::ErrorLabel::staticMetaObject = {
    { &QStatusBar::staticMetaObject, qt_meta_stringdata_RsaToolbox__ErrorLabel.data,
      qt_meta_data_RsaToolbox__ErrorLabel,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::ErrorLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::ErrorLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__ErrorLabel.stringdata))
        return static_cast<void*>(const_cast< ErrorLabel*>(this));
    return QStatusBar::qt_metacast(_clname);
}

int RsaToolbox::ErrorLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStatusBar::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
