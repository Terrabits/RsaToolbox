/****************************************************************************
** Meta object code from reading C++ file 'ChannelsModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../RsaToolbox/Instruments/Vna/Models/ChannelsModel/ChannelsModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChannelsModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__ChannelsModel_t {
    QByteArrayData data[7];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__ChannelsModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__ChannelsModel_t qt_meta_stringdata_RsaToolbox__ChannelsModel = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 5),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 8),
QT_MOC_LITERAL(4, 42, 14),
QT_MOC_LITERAL(5, 57, 7),
QT_MOC_LITERAL(6, 65, 11)
    },
    "RsaToolbox::ChannelsModel\0reset\0\0"
    "vnaReset\0vnaDataChanged\0topLeft\0"
    "bottomRight\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__ChannelsModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a,
       3,    0,   30,    2, 0x08,
       4,    2,   31,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    5,    6,

       0        // eod
};

void RsaToolbox::ChannelsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChannelsModel *_t = static_cast<ChannelsModel *>(_o);
        switch (_id) {
        case 0: _t->reset(); break;
        case 1: _t->vnaReset(); break;
        case 2: _t->vnaDataChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject RsaToolbox::ChannelsModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_RsaToolbox__ChannelsModel.data,
      qt_meta_data_RsaToolbox__ChannelsModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::ChannelsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::ChannelsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__ChannelsModel.stringdata))
        return static_cast<void*>(const_cast< ChannelsModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int RsaToolbox::ChannelsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
