/****************************************************************************
** Meta object code from reading C++ file 'DDCbuff.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DDCbuff.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DDCbuff.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DDCbuff_t {
    QByteArrayData data[16];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DDCbuff_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DDCbuff_t qt_meta_stringdata_DDCbuff = {
    {
QT_MOC_LITERAL(0, 0, 7), // "DDCbuff"
QT_MOC_LITERAL(1, 8, 9), // "checkProg"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "inverseBonus"
QT_MOC_LITERAL(4, 32, 13), // "inverseBonusA"
QT_MOC_LITERAL(5, 46, 8), // "setHook1"
QT_MOC_LITERAL(6, 55, 8), // "setHook2"
QT_MOC_LITERAL(7, 64, 7), // "unHook1"
QT_MOC_LITERAL(8, 72, 7), // "unHook2"
QT_MOC_LITERAL(9, 80, 11), // "punishBonus"
QT_MOC_LITERAL(10, 92, 12), // "punishBonusA"
QT_MOC_LITERAL(11, 105, 11), // "playerStand"
QT_MOC_LITERAL(12, 117, 12), // "playerStandA"
QT_MOC_LITERAL(13, 130, 9), // "delayBomb"
QT_MOC_LITERAL(14, 140, 10), // "delayBombA"
QT_MOC_LITERAL(15, 151, 9) // "bombCount"

    },
    "DDCbuff\0checkProg\0\0inverseBonus\0"
    "inverseBonusA\0setHook1\0setHook2\0unHook1\0"
    "unHook2\0punishBonus\0punishBonusA\0"
    "playerStand\0playerStandA\0delayBomb\0"
    "delayBombA\0bombCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DDCbuff[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DDCbuff::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DDCbuff *_t = static_cast<DDCbuff *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkProg(); break;
        case 1: _t->inverseBonus(); break;
        case 2: _t->inverseBonusA(); break;
        case 3: _t->setHook1(); break;
        case 4: _t->setHook2(); break;
        case 5: _t->unHook1(); break;
        case 6: _t->unHook2(); break;
        case 7: _t->punishBonus(); break;
        case 8: _t->punishBonusA(); break;
        case 9: _t->playerStand(); break;
        case 10: _t->playerStandA(); break;
        case 11: _t->delayBomb(); break;
        case 12: _t->delayBombA(); break;
        case 13: _t->bombCount(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DDCbuff::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DDCbuff.data,
      qt_meta_data_DDCbuff,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DDCbuff::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DDCbuff::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DDCbuff.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DDCbuff::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
