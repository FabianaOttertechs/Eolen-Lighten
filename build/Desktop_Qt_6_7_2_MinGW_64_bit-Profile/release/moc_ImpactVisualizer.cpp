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
    "headLedColorChanged",
    "color",
    "chestLedColorChanged",
    "bellyLedColorChanged",
    "feetLedColorChanged",
    "webSocketConnectedChanged",
    "connected",
    "connectionStatusChanged",
    "status",
    "setHeadImpact",
    "setChestImpact",
    "setBellyImpact",
    "setFeetImpact",
    "setHeadLedColor",
    "setChestLedColor",
    "setBellyLedColor",
    "setFeetLedColor",
    "triggerHeadImpact",
    "triggerChestImpact",
    "triggerBellyImpact",
    "triggerFeetImpact",
    "setLedColor",
    "zone",
    "resetAllLeds",
    "isWebSocketConnected",
    "resetAllImpacts",
    "onConnected",
    "onDisconnected",
    "onMessageReceived",
    "message",
    "onError",
    "QAbstractSocket::SocketError",
    "error",
    "handleSocketStateChange",
    "QAbstractSocket::SocketState",
    "state",
    "webSocketConnected",
    "headLedColor",
    "chestLedColor",
    "bellyLedColor",
    "feetLedColor"
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
      31,   14, // methods
       9,  277, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  200,    2, 0x06,   10 /* Public */,
       4,    1,  203,    2, 0x06,   12 /* Public */,
       6,    1,  206,    2, 0x06,   14 /* Public */,
       8,    1,  209,    2, 0x06,   16 /* Public */,
      10,    1,  212,    2, 0x06,   18 /* Public */,
      12,    1,  215,    2, 0x06,   20 /* Public */,
      13,    1,  218,    2, 0x06,   22 /* Public */,
      14,    1,  221,    2, 0x06,   24 /* Public */,
      15,    1,  224,    2, 0x06,   26 /* Public */,
      17,    1,  227,    2, 0x06,   28 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      19,    1,  230,    2, 0x0a,   30 /* Public */,
      20,    1,  233,    2, 0x0a,   32 /* Public */,
      21,    1,  236,    2, 0x0a,   34 /* Public */,
      22,    1,  239,    2, 0x0a,   36 /* Public */,
      23,    1,  242,    2, 0x0a,   38 /* Public */,
      24,    1,  245,    2, 0x0a,   40 /* Public */,
      25,    1,  248,    2, 0x0a,   42 /* Public */,
      26,    1,  251,    2, 0x0a,   44 /* Public */,
      27,    0,  254,    2, 0x0a,   46 /* Public */,
      28,    0,  255,    2, 0x0a,   47 /* Public */,
      29,    0,  256,    2, 0x0a,   48 /* Public */,
      30,    0,  257,    2, 0x0a,   49 /* Public */,
      31,    2,  258,    2, 0x0a,   50 /* Public */,
      33,    0,  263,    2, 0x0a,   53 /* Public */,
      34,    0,  264,    2, 0x10a,   54 /* Public | MethodIsConst  */,
      35,    0,  265,    2, 0x0a,   55 /* Public */,
      36,    0,  266,    2, 0x08,   56 /* Private */,
      37,    0,  267,    2, 0x08,   57 /* Private */,
      38,    1,  268,    2, 0x08,   58 /* Private */,
      40,    1,  271,    2, 0x08,   60 /* Private */,
      43,    1,  274,    2, 0x08,   62 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::QString,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   32,   11,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void, 0x80000000 | 41,   42,
    QMetaType::Void, 0x80000000 | 44,   45,

 // properties: name, type, flags
       3, QMetaType::Bool, 0x00015103, uint(0), 0,
       5, QMetaType::Bool, 0x00015103, uint(1), 0,
       7, QMetaType::Bool, 0x00015103, uint(2), 0,
       9, QMetaType::Bool, 0x00015103, uint(3), 0,
      46, QMetaType::Bool, 0x00015001, uint(8), 0,
      47, QMetaType::QColor, 0x00015103, uint(4), 0,
      48, QMetaType::QColor, 0x00015103, uint(5), 0,
      49, QMetaType::QColor, 0x00015103, uint(6), 0,
      50, QMetaType::QColor, 0x00015103, uint(7), 0,

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
        // property 'webSocketConnected'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'headLedColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'chestLedColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'bellyLedColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'feetLedColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
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
        // method 'headLedColorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'chestLedColorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'bellyLedColorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'feetLedColorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'webSocketConnectedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'connectionStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
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
        // method 'setHeadLedColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'setChestLedColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'setBellyLedColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'setFeetLedColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'triggerHeadImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerChestImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerBellyImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggerFeetImpact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setLedColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'resetAllLeds'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isWebSocketConnected'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'resetAllImpacts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onMessageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'handleSocketStateChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketState, std::false_type>
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
        case 4: _t->headLedColorChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 5: _t->chestLedColorChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 6: _t->bellyLedColorChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 7: _t->feetLedColorChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 8: _t->webSocketConnectedChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->connectionStatusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->setHeadImpact((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->setChestImpact((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->setBellyImpact((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->setFeetImpact((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->setHeadLedColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 15: _t->setChestLedColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 16: _t->setBellyLedColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 17: _t->setFeetLedColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 18: _t->triggerHeadImpact(); break;
        case 19: _t->triggerChestImpact(); break;
        case 20: _t->triggerBellyImpact(); break;
        case 21: _t->triggerFeetImpact(); break;
        case 22: _t->setLedColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 23: _t->resetAllLeds(); break;
        case 24: { bool _r = _t->isWebSocketConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->resetAllImpacts(); break;
        case 26: _t->onConnected(); break;
        case 27: _t->onDisconnected(); break;
        case 28: _t->onMessageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->onError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 30: _t->handleSocketStateChange((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 30:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
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
        {
            using _t = void (ImpactVisualizer::*)(const QColor & );
            if (_t _q_method = &ImpactVisualizer::headLedColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ImpactVisualizer::*)(const QColor & );
            if (_t _q_method = &ImpactVisualizer::chestLedColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ImpactVisualizer::*)(const QColor & );
            if (_t _q_method = &ImpactVisualizer::bellyLedColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ImpactVisualizer::*)(const QColor & );
            if (_t _q_method = &ImpactVisualizer::feetLedColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ImpactVisualizer::*)(bool );
            if (_t _q_method = &ImpactVisualizer::webSocketConnectedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ImpactVisualizer::*)(QString );
            if (_t _q_method = &ImpactVisualizer::connectionStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
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
        case 4: *reinterpret_cast< bool*>(_v) = _t->isWebSocketConnected(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->headLedColor(); break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->chestLedColor(); break;
        case 7: *reinterpret_cast< QColor*>(_v) = _t->bellyLedColor(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = _t->feetLedColor(); break;
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
        case 5: _t->setHeadLedColor(*reinterpret_cast< QColor*>(_v)); break;
        case 6: _t->setChestLedColor(*reinterpret_cast< QColor*>(_v)); break;
        case 7: _t->setBellyLedColor(*reinterpret_cast< QColor*>(_v)); break;
        case 8: _t->setFeetLedColor(*reinterpret_cast< QColor*>(_v)); break;
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
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
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

// SIGNAL 4
void ImpactVisualizer::headLedColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ImpactVisualizer::chestLedColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ImpactVisualizer::bellyLedColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ImpactVisualizer::feetLedColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ImpactVisualizer::webSocketConnectedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ImpactVisualizer::connectionStatusChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
