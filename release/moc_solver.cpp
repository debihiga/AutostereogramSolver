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
    QByteArrayData data[7];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Solver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Solver_t qt_meta_stringdata_Solver = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Solver"
QT_MOC_LITERAL(1, 7, 20), // "show_image_processed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "Mat*"
QT_MOC_LITERAL(4, 34, 15), // "image_processed"
QT_MOC_LITERAL(5, 50, 5), // "peppa"
QT_MOC_LITERAL(6, 56, 5) // "solve"

    },
    "Solver\0show_image_processed\0\0Mat*\0"
    "image_processed\0peppa\0solve"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Solver[] = {

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
       1,    1,   29,    2, 0x06 /* Public */,
       5,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Solver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Solver *_t = static_cast<Solver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show_image_processed((*reinterpret_cast< Mat*(*)>(_a[1]))); break;
        case 1: _t->peppa(); break;
        case 2: _t->solve(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Solver::*_t)(Mat * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::show_image_processed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Solver::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Solver::peppa)) {
                *result = 1;
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
void Solver::show_image_processed(Mat * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Solver::peppa()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
