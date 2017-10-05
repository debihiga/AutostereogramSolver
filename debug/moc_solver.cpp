/****************************************************************************
** Meta object code from reading C++ file 'solver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../solver.h"
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
    QByteArrayData data[25];
    char stringdata0[326];
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
QT_MOC_LITERAL(8, 121, 18), // "set_slider_minimum"
QT_MOC_LITERAL(9, 140, 18), // "set_slider_maximum"
QT_MOC_LITERAL(10, 159, 16), // "set_slider_value"
QT_MOC_LITERAL(11, 176, 18), // "set_slider_enabled"
QT_MOC_LITERAL(12, 195, 5), // "solve"
QT_MOC_LITERAL(13, 201, 9), // "find_mask"
QT_MOC_LITERAL(14, 211, 4), // "int*"
QT_MOC_LITERAL(15, 216, 6), // "tx_min"
QT_MOC_LITERAL(16, 223, 4), // "Mat*"
QT_MOC_LITERAL(17, 228, 4), // "mask"
QT_MOC_LITERAL(18, 233, 10), // "apply_mask"
QT_MOC_LITERAL(19, 244, 3), // "Mat"
QT_MOC_LITERAL(20, 248, 5), // "image"
QT_MOC_LITERAL(21, 254, 17), // "get_disparity_map"
QT_MOC_LITERAL(22, 272, 10), // "image_left"
QT_MOC_LITERAL(23, 283, 11), // "image_right"
QT_MOC_LITERAL(24, 295, 30) // "change_disparity_map_grayscale"

    },
    "Solver\0show_image_autostereogram\0\0"
    "show_image_left\0show_image_right\0"
    "show_image_map_depth\0enable_btn_stop\0"
    "enable_btn_start\0set_slider_minimum\0"
    "set_slider_maximum\0set_slider_value\0"
    "set_slider_enabled\0solve\0find_mask\0"
    "int*\0tx_min\0Mat*\0mask\0apply_mask\0Mat\0"
    "image\0get_disparity_map\0image_left\0"
    "image_right\0change_disparity_map_grayscale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Solver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    1,   92,    2, 0x06 /* Public */,
       4,    1,   95,    2, 0x06 /* Public */,
       5,    1,   98,    2, 0x06 /* Public */,
       6,    1,  101,    2, 0x06 /* Public */,
       7,    1,  104,    2, 0x06 /* Public */,
       8,    1,  107,    2, 0x06 /* Public */,
       9,    1,  110,    2, 0x06 /* Public */,
      10,    1,  113,    2, 0x06 /* Public */,
      11,    0,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  117,    2, 0x0a /* Public */,
      13,    2,  118,    2, 0x0a /* Public */,
      18,    2,  123,    2, 0x0a /* Public */,
      21,    2,  128,    2, 0x0a /* Public */,
      24,    1,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 14, 0x80000000 | 16,   15,   17,
    0x80000000 | 19, 0x80000000 | 19, 0x80000000 | 19,   20,   17,
    QMetaType::Void, 0x80000000 | 19, 0x80000000 | 19,   22,   23,
    QMetaType::Void, QMetaType::Int,    2,

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
        case 6: _t->set_slider_minimum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->set_slider_maximum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->set_slider_value((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->set_slider_enabled(); break;
        case 10: _t->solve(); break;
        case 11: { bool _r = _t->find_mask((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< Mat*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { Mat _r = _t->apply_mask((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->get_disparity_map((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 14: _t->change_disparity_map_grayscale((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        {
            typedef void (Solver::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::set_slider_minimum)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Solver::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::set_slider_maximum)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Solver::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::set_slider_value)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Solver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::set_slider_enabled)) {
                *result = 9;
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

// SIGNAL 6
void Solver::set_slider_minimum(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Solver::set_slider_maximum(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Solver::set_slider_value(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Solver::set_slider_enabled()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
