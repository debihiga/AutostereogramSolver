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
    QByteArrayData data[35];
    char stringdata0[374];
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
QT_MOC_LITERAL(9, 127, 9), // "find_mask"
QT_MOC_LITERAL(10, 137, 4), // "int*"
QT_MOC_LITERAL(11, 142, 6), // "tx_min"
QT_MOC_LITERAL(12, 149, 4), // "Mat*"
QT_MOC_LITERAL(13, 154, 7), // "shifted"
QT_MOC_LITERAL(14, 162, 4), // "mask"
QT_MOC_LITERAL(15, 167, 14), // "get_image_left"
QT_MOC_LITERAL(16, 182, 5), // "shift"
QT_MOC_LITERAL(17, 188, 5), // "image"
QT_MOC_LITERAL(18, 194, 15), // "get_image_right"
QT_MOC_LITERAL(19, 210, 9), // "get_image"
QT_MOC_LITERAL(20, 220, 3), // "Mat"
QT_MOC_LITERAL(21, 224, 14), // "autostereogram"
QT_MOC_LITERAL(22, 239, 19), // "disparity_filtering"
QT_MOC_LITERAL(23, 259, 4), // "left"
QT_MOC_LITERAL(24, 264, 5), // "right"
QT_MOC_LITERAL(25, 270, 6), // "String"
QT_MOC_LITERAL(26, 277, 9), // "algorithm"
QT_MOC_LITERAL(27, 287, 6), // "filter"
QT_MOC_LITERAL(28, 294, 10), // "no_display"
QT_MOC_LITERAL(29, 305, 12), // "no_downscale"
QT_MOC_LITERAL(30, 318, 8), // "vis_mult"
QT_MOC_LITERAL(31, 327, 13), // "max_disparity"
QT_MOC_LITERAL(32, 341, 11), // "window_size"
QT_MOC_LITERAL(33, 353, 10), // "wls_lambda"
QT_MOC_LITERAL(34, 364, 9) // "wls_sigma"

    },
    "Solver\0show_image_autostereogram\0\0"
    "show_image_left\0show_image_right\0"
    "show_image_map_depth\0enable_btn_stop\0"
    "enable_btn_start\0solve\0find_mask\0int*\0"
    "tx_min\0Mat*\0shifted\0mask\0get_image_left\0"
    "shift\0image\0get_image_right\0get_image\0"
    "Mat\0autostereogram\0disparity_filtering\0"
    "left\0right\0String\0algorithm\0filter\0"
    "no_display\0no_downscale\0vis_mult\0"
    "max_disparity\0window_size\0wls_lambda\0"
    "wls_sigma"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Solver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       3,    1,  122,    2, 0x06 /* Public */,
       4,    1,  125,    2, 0x06 /* Public */,
       5,    1,  128,    2, 0x06 /* Public */,
       6,    1,  131,    2, 0x06 /* Public */,
       7,    1,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  137,    2, 0x0a /* Public */,
       9,    3,  138,    2, 0x0a /* Public */,
      15,    2,  145,    2, 0x0a /* Public */,
      18,    2,  150,    2, 0x0a /* Public */,
      19,    3,  155,    2, 0x0a /* Public */,
      22,   11,  162,    2, 0x0a /* Public */,
      22,   10,  185,    2, 0x2a /* Public | MethodCloned */,
      22,    9,  206,    2, 0x2a /* Public | MethodCloned */,
      22,    8,  225,    2, 0x2a /* Public | MethodCloned */,
      22,    7,  242,    2, 0x2a /* Public | MethodCloned */,
      22,    6,  257,    2, 0x2a /* Public | MethodCloned */,
      22,    5,  270,    2, 0x2a /* Public | MethodCloned */,
      22,    4,  281,    2, 0x2a /* Public | MethodCloned */,
      22,    3,  290,    2, 0x2a /* Public | MethodCloned */,
      22,    2,  297,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 12, 0x80000000 | 12,   11,   13,   14,
    QMetaType::Bool, 0x80000000 | 10, 0x80000000 | 12,   16,   17,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 12,   16,   17,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, QMetaType::Int,   21,   14,   16,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 25, 0x80000000 | 25, QMetaType::Bool, QMetaType::Bool, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Double, QMetaType::Double,   23,   24,   26,   27,   28,   29,   30,   31,   32,   33,   34,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 25, 0x80000000 | 25, QMetaType::Bool, QMetaType::Bool, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Double,   23,   24,   26,   27,   28,   29,   30,   31,   32,   33,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 25, 0x80000000 | 25, QMetaType::Bool, QMetaType::Bool, QMetaType::Double, QMetaType::Int, QMetaType::Int,   23,   24,   26,   27,   28,   29,   30,   31,   32,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 25, 0x80000000 | 25, QMetaType::Bool, QMetaType::Bool, QMetaType::Double, QMetaType::Int,   23,   24,   26,   27,   28,   29,   30,   31,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 25, 0x80000000 | 25, QMetaType::Bool, QMetaType::Bool, QMetaType::Double,   23,   24,   26,   27,   28,   29,   30,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 25, 0x80000000 | 25, QMetaType::Bool, QMetaType::Bool,   23,   24,   26,   27,   28,   29,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 25, 0x80000000 | 25, QMetaType::Bool,   23,   24,   26,   27,   28,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 25, 0x80000000 | 25,   23,   24,   26,   27,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 25,   23,   24,   26,
    0x80000000 | 20, 0x80000000 | 20, 0x80000000 | 20,   23,   24,

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
        case 7: { bool _r = _t->find_mask((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< Mat*(*)>(_a[2])),(*reinterpret_cast< Mat*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->get_image_left((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< Mat*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->get_image_right((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Mat*(*)>(_a[2]))); break;
        case 10: { Mat _r = _t->get_image((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 11: { Mat _r = _t->disparity_filtering((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< String(*)>(_a[3])),(*reinterpret_cast< String(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< double(*)>(_a[11])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 12: { Mat _r = _t->disparity_filtering((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< String(*)>(_a[3])),(*reinterpret_cast< String(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 13: { Mat _r = _t->disparity_filtering((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< String(*)>(_a[3])),(*reinterpret_cast< String(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])),(*reinterpret_cast< int(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 14: { Mat _r = _t->disparity_filtering((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< String(*)>(_a[3])),(*reinterpret_cast< String(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 15: { Mat _r = _t->disparity_filtering((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< String(*)>(_a[3])),(*reinterpret_cast< String(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 16: { Mat _r = _t->disparity_filtering((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< String(*)>(_a[3])),(*reinterpret_cast< String(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 17: { Mat _r = _t->disparity_filtering((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< String(*)>(_a[3])),(*reinterpret_cast< String(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 18: { Mat _r = _t->disparity_filtering((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< String(*)>(_a[3])),(*reinterpret_cast< String(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 19: { Mat _r = _t->disparity_filtering((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< String(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 20: { Mat _r = _t->disparity_filtering((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])));
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
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
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
