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
    QByteArrayData data[49];
    char stringdata0[611];
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
QT_MOC_LITERAL(5, 67, 20), // "show_image_depth_map"
QT_MOC_LITERAL(6, 88, 15), // "enable_btn_stop"
QT_MOC_LITERAL(7, 104, 16), // "enable_btn_start"
QT_MOC_LITERAL(8, 121, 18), // "set_slider_minimum"
QT_MOC_LITERAL(9, 140, 18), // "set_slider_maximum"
QT_MOC_LITERAL(10, 159, 16), // "set_slider_value"
QT_MOC_LITERAL(11, 176, 18), // "set_slider_enabled"
QT_MOC_LITERAL(12, 195, 5), // "solve"
QT_MOC_LITERAL(13, 201, 8), // "method_1"
QT_MOC_LITERAL(14, 210, 11), // "find_mask_1"
QT_MOC_LITERAL(15, 222, 3), // "Mat"
QT_MOC_LITERAL(16, 226, 15), // "set_depth_map_1"
QT_MOC_LITERAL(17, 242, 8), // "method_2"
QT_MOC_LITERAL(18, 251, 19), // "get_max_disparity_2"
QT_MOC_LITERAL(19, 271, 19), // "get_disparity_map_2"
QT_MOC_LITERAL(20, 291, 15), // "get_disparity_2"
QT_MOC_LITERAL(21, 307, 10), // "block_left"
QT_MOC_LITERAL(22, 318, 9), // "row_right"
QT_MOC_LITERAL(23, 328, 10), // "block_size"
QT_MOC_LITERAL(24, 339, 14), // "get_blocks_SSD"
QT_MOC_LITERAL(25, 354, 11), // "block_right"
QT_MOC_LITERAL(26, 366, 6), // "filter"
QT_MOC_LITERAL(27, 373, 5), // "image"
QT_MOC_LITERAL(28, 379, 13), // "disparity_map"
QT_MOC_LITERAL(29, 393, 5), // "wsize"
QT_MOC_LITERAL(30, 399, 6), // "lambda"
QT_MOC_LITERAL(31, 406, 5), // "sigma"
QT_MOC_LITERAL(32, 412, 4), // "Mat*"
QT_MOC_LITERAL(33, 417, 22), // "disparity_map_filtered"
QT_MOC_LITERAL(34, 440, 8), // "method_3"
QT_MOC_LITERAL(35, 449, 8), // "method_4"
QT_MOC_LITERAL(36, 458, 9), // "find_mask"
QT_MOC_LITERAL(37, 468, 17), // "get_max_disparity"
QT_MOC_LITERAL(38, 486, 10), // "apply_mask"
QT_MOC_LITERAL(39, 497, 4), // "mask"
QT_MOC_LITERAL(40, 502, 17), // "get_disparity_map"
QT_MOC_LITERAL(41, 520, 10), // "image_left"
QT_MOC_LITERAL(42, 531, 11), // "image_right"
QT_MOC_LITERAL(43, 543, 11), // "match_block"
QT_MOC_LITERAL(44, 555, 11), // "match_image"
QT_MOC_LITERAL(45, 567, 11), // "n_iteration"
QT_MOC_LITERAL(46, 579, 8), // "_row_min"
QT_MOC_LITERAL(47, 588, 8), // "_col_min"
QT_MOC_LITERAL(48, 597, 13) // "set_depth_map"

    },
    "Solver\0show_image_autostereogram\0\0"
    "show_image_left\0show_image_right\0"
    "show_image_depth_map\0enable_btn_stop\0"
    "enable_btn_start\0set_slider_minimum\0"
    "set_slider_maximum\0set_slider_value\0"
    "set_slider_enabled\0solve\0method_1\0"
    "find_mask_1\0Mat\0set_depth_map_1\0"
    "method_2\0get_max_disparity_2\0"
    "get_disparity_map_2\0get_disparity_2\0"
    "block_left\0row_right\0block_size\0"
    "get_blocks_SSD\0block_right\0filter\0"
    "image\0disparity_map\0wsize\0lambda\0sigma\0"
    "Mat*\0disparity_map_filtered\0method_3\0"
    "method_4\0find_mask\0get_max_disparity\0"
    "apply_mask\0mask\0get_disparity_map\0"
    "image_left\0image_right\0match_block\0"
    "match_image\0n_iteration\0_row_min\0"
    "_col_min\0set_depth_map"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Solver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  164,    2, 0x06 /* Public */,
       3,    1,  167,    2, 0x06 /* Public */,
       4,    1,  170,    2, 0x06 /* Public */,
       5,    1,  173,    2, 0x06 /* Public */,
       6,    1,  176,    2, 0x06 /* Public */,
       7,    1,  179,    2, 0x06 /* Public */,
       8,    1,  182,    2, 0x06 /* Public */,
       9,    1,  185,    2, 0x06 /* Public */,
      10,    1,  188,    2, 0x06 /* Public */,
      11,    0,  191,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  192,    2, 0x0a /* Public */,
      13,    0,  193,    2, 0x0a /* Public */,
      14,    0,  194,    2, 0x0a /* Public */,
      16,    0,  195,    2, 0x0a /* Public */,
      17,    0,  196,    2, 0x0a /* Public */,
      18,    0,  197,    2, 0x0a /* Public */,
      19,    0,  198,    2, 0x0a /* Public */,
      20,    3,  199,    2, 0x0a /* Public */,
      24,    2,  206,    2, 0x0a /* Public */,
      26,    6,  211,    2, 0x0a /* Public */,
      34,    0,  224,    2, 0x0a /* Public */,
      35,    0,  225,    2, 0x0a /* Public */,
      36,    0,  226,    2, 0x0a /* Public */,
      37,    0,  227,    2, 0x0a /* Public */,
      38,    2,  228,    2, 0x0a /* Public */,
      40,    2,  233,    2, 0x0a /* Public */,
      40,    0,  238,    2, 0x0a /* Public */,
      43,    3,  239,    2, 0x0a /* Public */,
      44,    4,  246,    2, 0x0a /* Public */,
      48,    0,  255,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    0x80000000 | 15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::UInt, 0x80000000 | 15, 0x80000000 | 15, QMetaType::Int,   21,   22,   23,
    QMetaType::UInt, 0x80000000 | 15, 0x80000000 | 15,   21,   25,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15, QMetaType::Int, QMetaType::Double, QMetaType::Double, 0x80000000 | 32,   27,   28,   29,   30,   31,   33,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 15,
    QMetaType::Int,
    0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 15,   27,   39,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15,   41,   42,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 15, 0x80000000 | 15, QMetaType::Int,   21,   22,   23,
    QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   23,   45,   46,   47,
    QMetaType::Void,

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
        case 3: _t->show_image_depth_map((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 4: _t->enable_btn_stop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->enable_btn_start((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->set_slider_minimum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->set_slider_maximum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->set_slider_value((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->set_slider_enabled(); break;
        case 10: _t->solve(); break;
        case 11: _t->method_1(); break;
        case 12: { Mat _r = _t->find_mask_1();
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->set_depth_map_1(); break;
        case 14: _t->method_2(); break;
        case 15: { int _r = _t->get_max_disparity_2();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->get_disparity_map_2(); break;
        case 17: { uint _r = _t->get_disparity_2((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 18: { uint _r = _t->get_blocks_SSD((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->filter((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< Mat*(*)>(_a[6]))); break;
        case 20: _t->method_3(); break;
        case 21: _t->method_4(); break;
        case 22: { Mat _r = _t->find_mask();
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 23: { int _r = _t->get_max_disparity();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 24: { Mat _r = _t->apply_mask((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->get_disparity_map((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 26: _t->get_disparity_map(); break;
        case 27: { int _r = _t->match_block((*reinterpret_cast< Mat(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 28: { bool _r = _t->match_image((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 29: _t->set_depth_map(); break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::show_image_depth_map)) {
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
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 30;
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
void Solver::show_image_depth_map(const QPixmap & _t1)
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
