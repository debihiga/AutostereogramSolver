/****************************************************************************
** Meta object code from reading C++ file 'solver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Downloads/AutostereogramSolver-a81095352b476bee7939d01f919cb2c2ac9db59f/solver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'solver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Solver_t {
    QByteArrayData data[18];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Solver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Solver_t qt_meta_stringdata_Solver = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Solver"
QT_MOC_LITERAL(1, 7, 25), // "show_image_autostereogram"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "show_image_left"
QT_MOC_LITERAL(4, 50, 16), // "show_image_right"
QT_MOC_LITERAL(5, 67, 20), // "show_image_map_depth"
QT_MOC_LITERAL(6, 88, 15), // "enable_btn_stop"
QT_MOC_LITERAL(7, 104, 16), // "enable_btn_start"
QT_MOC_LITERAL(8, 121, 5), // "solve"
QT_MOC_LITERAL(9, 127, 14), // "get_image_left"
QT_MOC_LITERAL(10, 142, 3), // "Mat"
QT_MOC_LITERAL(11, 146, 14), // "autostereogram"
QT_MOC_LITERAL(12, 161, 4), // "mask"
QT_MOC_LITERAL(13, 166, 5), // "shift"
QT_MOC_LITERAL(14, 172, 15), // "get_image_right"
QT_MOC_LITERAL(15, 188, 10), // "translated"
QT_MOC_LITERAL(16, 199, 10), // "image_left"
QT_MOC_LITERAL(17, 210, 13) // "max_disparity"

    },
    "Solver\0show_image_autostereogram\0\0"
    "show_image_left\0show_image_right\0"
    "show_image_map_depth\0enable_btn_stop\0"
    "enable_btn_start\0solve\0get_image_left\0"
    "Mat\0autostereogram\0mask\0shift\0"
    "get_image_right\0translated\0image_left\0"
    "max_disparity"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Solver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,
       6,    1,   71,    2, 0x06 /* Public */,
       7,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   77,    2, 0x0a /* Public */,
       9,    3,   78,    2, 0x0a /* Public */,
      14,    4,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 10, QMetaType::Int,   11,   12,   13,
    0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 10, 0x80000000 | 10, QMetaType::Int,   11,   15,   16,   17,

       0        // eod
};

void Solver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Solver *_t = static_cast<Solver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show_image_autostereogram((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 1: _t->show_image_left((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 2: _t->show_image_right((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 3: _t->show_image_map_depth((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 4: _t->enable_btn_stop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->enable_btn_start((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->solve(); break;
        case 7: { Mat _r = _t->get_image_left((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 8: { Mat _r = _t->get_image_right((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< Mat(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Solver::*_t)(const QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::show_image_autostereogram)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Solver::*_t)(const QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::show_image_left)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Solver::*_t)(const QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::show_image_right)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Solver::*_t)(const QPixmap & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::show_image_map_depth)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Solver::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::enable_btn_stop)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Solver::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::enable_btn_start)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Solver::staticMetaObject = {
    { &WBase::staticMetaObject, qt_meta_stringdata_Solver.data,
      qt_meta_data_Solver,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Solver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Solver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Solver.stringdata0))
        return static_cast<void*>(const_cast< Solver*>(this));
    return WBase::qt_metacast(_clname);
}

int Solver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = WBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Solver::show_image_autostereogram(const QPixmap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Solver::show_image_left(const QPixmap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Solver::show_image_right(const QPixmap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Solver::show_image_map_depth(const QPixmap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Solver::enable_btn_stop(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Solver::enable_btn_start(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
