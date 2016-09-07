/****************************************************************************
** Meta object code from reading C++ file 'Wizard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Gui/Wizard/Wizard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Wizard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__Wizard_t {
    QByteArrayData data[20];
    char stringdata[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__Wizard_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__Wizard_t qt_meta_stringdata_RsaToolbox__Wizard = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 18),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 5),
QT_MOC_LITERAL(4, 45, 14),
QT_MOC_LITERAL(5, 60, 4),
QT_MOC_LITERAL(6, 65, 7),
QT_MOC_LITERAL(7, 73, 9),
QT_MOC_LITERAL(8, 83, 11),
QT_MOC_LITERAL(9, 95, 4),
QT_MOC_LITERAL(10, 100, 5),
QT_MOC_LITERAL(11, 106, 4),
QT_MOC_LITERAL(12, 111, 7),
QT_MOC_LITERAL(13, 119, 10),
QT_MOC_LITERAL(14, 130, 9),
QT_MOC_LITERAL(15, 140, 11),
QT_MOC_LITERAL(16, 152, 10),
QT_MOC_LITERAL(17, 163, 18),
QT_MOC_LITERAL(18, 182, 19),
QT_MOC_LITERAL(19, 202, 5)
    },
    "RsaToolbox::Wizard\0currentPageChanged\0"
    "\0index\0historyChanged\0past\0current\0"
    "pageAdded\0pageRemoved\0back\0count\0next\0"
    "restart\0setEnabled\0isEnabled\0setDisabled\0"
    "isDisabled\0enableLoadingImage\0"
    "disableLoadingImage\0shake\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__Wizard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06,
       4,    2,   92,    2, 0x06,
       7,    1,   97,    2, 0x06,
       8,    1,  100,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       9,    1,  103,    2, 0x0a,
       9,    0,  106,    2, 0x2a,
      11,    0,  107,    2, 0x0a,
      12,    0,  108,    2, 0x0a,
      13,    0,  109,    2, 0x0a,
      13,    1,  110,    2, 0x0a,
      15,    0,  113,    2, 0x0a,
      15,    1,  114,    2, 0x0a,
      17,    0,  117,    2, 0x0a,
      18,    0,  118,    2, 0x0a,
      19,    0,  119,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RsaToolbox::Wizard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Wizard *_t = static_cast<Wizard *>(_o);
        switch (_id) {
        case 0: _t->currentPageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->historyChanged((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->pageAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->pageRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->back((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->back(); break;
        case 6: _t->next(); break;
        case 7: _t->restart(); break;
        case 8: _t->setEnabled(); break;
        case 9: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setDisabled(); break;
        case 11: _t->setDisabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->enableLoadingImage(); break;
        case 13: _t->disableLoadingImage(); break;
        case 14: _t->shake(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Wizard::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Wizard::currentPageChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Wizard::*_t)(QStringList , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Wizard::historyChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Wizard::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Wizard::pageAdded)) {
                *result = 2;
            }
        }
        {
            typedef void (Wizard::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Wizard::pageRemoved)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject RsaToolbox::Wizard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RsaToolbox__Wizard.data,
      qt_meta_data_RsaToolbox__Wizard,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::Wizard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::Wizard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__Wizard.stringdata))
        return static_cast<void*>(const_cast< Wizard*>(this));
    return QWidget::qt_metacast(_clname);
}

int RsaToolbox::Wizard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void RsaToolbox::Wizard::currentPageChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RsaToolbox::Wizard::historyChanged(QStringList _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RsaToolbox::Wizard::pageAdded(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RsaToolbox::Wizard::pageRemoved(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
