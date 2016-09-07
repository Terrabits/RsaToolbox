/****************************************************************************
** Meta object code from reading C++ file 'WizardPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Gui/Wizard/WizardPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WizardPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__WizardPage_t {
    QByteArrayData data[7];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__WizardPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__WizardPage_t qt_meta_stringdata_RsaToolbox__WizardPage = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 10),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 9),
QT_MOC_LITERAL(4, 45, 10),
QT_MOC_LITERAL(5, 56, 12),
QT_MOC_LITERAL(6, 69, 7)
    },
    "RsaToolbox::WizardPage\0enableNext\0\0"
    "isEnabled\0enableBack\0displayError\0"
    "message\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__WizardPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06,
       4,    1,   32,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   35,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void RsaToolbox::WizardPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WizardPage *_t = static_cast<WizardPage *>(_o);
        switch (_id) {
        case 0: _t->enableNext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->enableBack((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->displayError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WizardPage::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WizardPage::enableNext)) {
                *result = 0;
            }
        }
        {
            typedef void (WizardPage::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WizardPage::enableBack)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject RsaToolbox::WizardPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RsaToolbox__WizardPage.data,
      qt_meta_data_RsaToolbox__WizardPage,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::WizardPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::WizardPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__WizardPage.stringdata))
        return static_cast<void*>(const_cast< WizardPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int RsaToolbox::WizardPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void RsaToolbox::WizardPage::enableNext(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RsaToolbox::WizardPage::enableBack(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
