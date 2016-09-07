/****************************************************************************
** Meta object code from reading C++ file 'Update.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Source/Gui/Update/Update.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Update.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RsaToolbox__Update_t {
    QByteArrayData data[18];
    char stringdata[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RsaToolbox__Update_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RsaToolbox__Update_t qt_meta_stringdata_RsaToolbox__Update = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 15),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 5),
QT_MOC_LITERAL(4, 42, 7),
QT_MOC_LITERAL(5, 50, 15),
QT_MOC_LITERAL(6, 66, 12),
QT_MOC_LITERAL(7, 79, 12),
QT_MOC_LITERAL(8, 92, 12),
QT_MOC_LITERAL(9, 105, 21),
QT_MOC_LITERAL(10, 127, 14),
QT_MOC_LITERAL(11, 142, 22),
QT_MOC_LITERAL(12, 165, 13),
QT_MOC_LITERAL(13, 179, 10),
QT_MOC_LITERAL(14, 190, 23),
QT_MOC_LITERAL(15, 214, 16),
QT_MOC_LITERAL(16, 231, 38),
QT_MOC_LITERAL(17, 270, 5)
    },
    "RsaToolbox::Update\0updateAvailable\0\0"
    "error\0message\0automaticUpdate\0"
    "manualUpdate\0downloadJson\0jsonFinished\0"
    "requestDownloadHeader\0downloadUpdate\0"
    "updateDownloadProgress\0bytesReceived\0"
    "totalBytes\0writeDownloadDataToFile\0"
    "downloadFinished\0"
    "on_updateFrequency_currentIndexChanged\0"
    "index\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RsaToolbox__Update[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06,
       3,    1,   75,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   78,    2, 0x0a,
       6,    0,   79,    2, 0x0a,
       7,    0,   80,    2, 0x08,
       8,    0,   81,    2, 0x08,
       9,    0,   82,    2, 0x08,
      10,    0,   83,    2, 0x08,
      11,    2,   84,    2, 0x08,
      14,    0,   89,    2, 0x08,
      15,    0,   90,    2, 0x08,
      16,    1,   91,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void RsaToolbox::Update::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Update *_t = static_cast<Update *>(_o);
        switch (_id) {
        case 0: _t->updateAvailable(); break;
        case 1: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->automaticUpdate(); break;
        case 3: _t->manualUpdate(); break;
        case 4: _t->downloadJson(); break;
        case 5: _t->jsonFinished(); break;
        case 6: _t->requestDownloadHeader(); break;
        case 7: _t->downloadUpdate(); break;
        case 8: _t->updateDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 9: _t->writeDownloadDataToFile(); break;
        case 10: _t->downloadFinished(); break;
        case 11: _t->on_updateFrequency_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Update::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Update::updateAvailable)) {
                *result = 0;
            }
        }
        {
            typedef void (Update::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Update::error)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject RsaToolbox::Update::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RsaToolbox__Update.data,
      qt_meta_data_RsaToolbox__Update,  qt_static_metacall, 0, 0}
};


const QMetaObject *RsaToolbox::Update::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RsaToolbox::Update::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RsaToolbox__Update.stringdata))
        return static_cast<void*>(const_cast< Update*>(this));
    return QWidget::qt_metacast(_clname);
}

int RsaToolbox::Update::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void RsaToolbox::Update::updateAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RsaToolbox::Update::error(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
