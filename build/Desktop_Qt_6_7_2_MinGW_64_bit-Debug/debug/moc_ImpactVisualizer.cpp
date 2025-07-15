/****************************************************************************
** Meta object code from reading C++ file 'ImpactVisualizer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ImpactVisualizer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImpactVisualizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSImpactVisualizerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSImpactVisualizerENDCLASS = QtMocHelpers::stringData(
    "ImpactVisualizer",
    "headImpactChanged",
    "",
    "headImpact",
    "chestImpactChanged",
    "chestImpact",
    "bellyImpactChanged",
    "bellyImpact",
    "feetImpactChanged",
    "feetImpact",
    "setHeadImpact",
    "setChestImpact",
    "setBellyImpact",
    "setFeetImpact",
    "triggerHeadImpact",
    "triggerChestImpact",
    "triggerBellyImpact",
    "triggerFeetImpact",
    "resetAllImpacts"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSImpactVisualizerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       4,  121, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    5 /* Public */,
       4,    1,   95,    2, 0x06,    7 /* Public */,
       6,    1,   98,    2, 0x06,    9 /* Public */,
       8,    1,  101,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,  104,    2, 0x0a,   13 /* Public */,
      11,    1,  107,    2, 0x0a,   15 /* Public */,
      12,    1,  110,    2, 0x0a,   17 /* Public */,
      13,    1,  113,    2, 0x0a,   19 /* Public */,
      14,    0,  116,    2, 0x0a,   21 /* Public */,
      15,    0,  117,    2, 0x0a,   22 /* Public */,
      16,    0,  118,    2, 0x0a,   23 /* Public */,
      17,    0,  119,    2, 0x0a,   24 /* Public */,
      18,    0,  120,    2, 0x0a,   25 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00015103, uint(0), 0,
       5, QMetaType::Bool, 0x00015103, uint(1), 0,
       7, QMetaType::Bool, 0x00015103, uint(2), 0,
       9, QMetaType::Bool, 0x00015103, uint(3), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ImpactVisualizer::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_CLASSImpactVisualizerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSImpactVisualizerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSImpactVisualizerENDCLASS_t,
        // property 'headImpact'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'chestImpact'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'bellyImpact'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'feetImpact'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ImpactVisualizer, std::true_type>,
        // method 'headImpactChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'chestImpactChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'bellyImpactChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'feetImpactChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setHeadImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setChestImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setBellyImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setFeetImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'triggerHeadImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerChestImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerBellyImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerFeetImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetAllImpacts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ImpactVisualizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImpactVisualizer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->headImpactChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->chestImpactChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->bellyImpactChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->feetImpactChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->setHeadImpact((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->setChestImpact((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->setBellyImpact((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->setFeetImpact((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->triggerHeadImpact(); break;
        case 9: _t->triggerChestImpact(); break;
        case 10: _t->triggerBellyImpact(); break;
        case 11: _t->triggerFeetImpact(); break;
        case 12: _t->resetAllImpacts(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImpactVisualizer::*)(bool );
            if (_t _q_method = &ImpactVisualizer::headImpactChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ImpactVisualizer::*)(bool );
            if (_t _q_method = &ImpactVisualizer::chestImpactChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ImpactVisualizer::*)(bool );
            if (_t _q_method = &ImpactVisualizer::bellyImpactChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ImpactVisualizer::*)(bool );
            if (_t _q_method = &ImpactVisualizer::feetImpactChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ImpactVisualizer *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->headImpact(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->chestImpact(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->bellyImpact(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->feetImpact(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ImpactVisualizer *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHeadImpact(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setChestImpact(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setBellyImpact(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setFeetImpact(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *ImpactVisualizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImpactVisualizer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSImpactVisualizerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int ImpactVisualizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ImpactVisualizer::headImpactChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImpactVisualizer::chestImpactChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImpactVisualizer::bellyImpactChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImpactVisualizer::feetImpactChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
