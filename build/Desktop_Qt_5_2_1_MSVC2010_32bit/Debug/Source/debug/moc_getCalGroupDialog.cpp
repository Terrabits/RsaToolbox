/****************************************************************************
** Meta object code from reading C++ file 'getCalGroupDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Instruments/Vna/Dialogs/getCalGroupDialog/getCalGroupDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'getCalGroupDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__getCalGroupDialog_t {
    QByteArrayData data[7];
    char stringdata[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__getCalGroupDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__getCalGroupDialog_t qt_meta_stringdata_RsaToolbox__getCalGroupDialog = {
    {
QT_MOC_LITERAL(0, 0, 29),
QT_MOC_LITERAL(1, 30, 16),
QT_MOC_LITERAL(2, 47, 0),
QT_MOC_LITERAL(3, 48, 14),
QT_MOC_LITERAL(4, 63, 6),
QT_MOC_LITERAL(5, 70, 6),
QT_MOC_LITERAL(6, 77, 5)
    },
    "RsaToolbox::getCalGroupDialog\0"
    "selectionChanged\0\0QItemSelection\0"
    "accept\0reject\0reset\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__getCalGroupDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   39,    2, 0x0a,
       5,    0,   40,    2, 0x0a,
       6,    0,   41,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RsaToolbox::getCalGroupDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        getCalGroupDialog *_t = static_cast<getCalGroupDialog *>(_o);
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< QItemSelection(*)>(_a[1])),(*reinterpret_cast< QItemSelection(*)>(_a[2]))); break;
        case 1: _t->accept(); break;
        case 2: _t->reject(); break;
        case 3: _t->reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (getCalGroupDialog::*_t)(QItemSelection , QItemSelection );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&getCalGroupDialog::selectionChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject RsaToolbox::getCalGroupDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RsaToolbox__getCalGroupDialog.data,
      qt_meta_data_RsaToolbox__getCalGroupDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::getCalGroupDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::getCalGroupDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__getCalGroupDialog.stringdata))
        return static_cast<void*>(const_cast< getCalGroupDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RsaToolbox::getCalGroupDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void RsaToolbox::getCalGroupDialog::selectionChanged(QItemSelection _t1, QItemSelection _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
