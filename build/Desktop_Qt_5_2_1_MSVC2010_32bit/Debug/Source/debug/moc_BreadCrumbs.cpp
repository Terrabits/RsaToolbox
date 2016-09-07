/****************************************************************************
** Meta object code from reading C++ file 'BreadCrumbs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Gui/Wizard/BreadCrumbs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BreadCrumbs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__BreadCrumbs_t {
    QByteArrayData data[9];
    char stringdata[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__BreadCrumbs_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__BreadCrumbs_t qt_meta_stringdata_RsaToolbox__BreadCrumbs = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 4),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 9),
QT_MOC_LITERAL(4, 40, 8),
QT_MOC_LITERAL(5, 49, 13),
QT_MOC_LITERAL(6, 63, 11),
QT_MOC_LITERAL(7, 75, 20),
QT_MOC_LITERAL(8, 96, 4)
    },
    "RsaToolbox::BreadCrumbs\0back\0\0pagesBack\0"
    "setLinks\0previousPages\0currentPage\0"
    "processLinkActivated\0link\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__BreadCrumbs[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    2,   32,    2, 0x0a,
       7,    1,   37,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void RsaToolbox::BreadCrumbs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BreadCrumbs *_t = static_cast<BreadCrumbs *>(_o);
        switch (_id) {
        case 0: _t->back((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setLinks((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->processLinkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BreadCrumbs::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BreadCrumbs::back)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject RsaToolbox::BreadCrumbs::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RsaToolbox__BreadCrumbs.data,
      qt_meta_data_RsaToolbox__BreadCrumbs,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::BreadCrumbs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::BreadCrumbs::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__BreadCrumbs.stringdata))
        return static_cast<void*>(const_cast< BreadCrumbs*>(this));
    return QWidget::qt_metacast(_clname);
}

int RsaToolbox::BreadCrumbs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void RsaToolbox::BreadCrumbs::back(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
