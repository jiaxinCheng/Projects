/****************************************************************************
** Meta object code from reading C++ file 'debugger.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "debugger.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'debugger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Debugger[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      17,    9,    9,    9, 0x0a,
      24,    9,    9,    9, 0x0a,
      31,    9,    9,    9, 0x0a,
      42,    9,    9,    9, 0x0a,
      56,    9,    9,    9, 0x0a,
      68,    9,    9,    9, 0x0a,
      77,    9,    9,    9, 0x0a,
      87,    9,    9,    9, 0x0a,
      95,    9,    9,    9, 0x0a,
     104,    9,    9,    9, 0x0a,
     113,    9,    9,    9, 0x0a,
     122,    9,    9,    9, 0x0a,
     130,    9,    9,    9, 0x0a,
     138,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Debugger[] = {
    "Debugger\0\0step()\0quit()\0load()\0"
    "addBreak()\0removeBreak()\0acontinue()\0"
    "reload()\0inspect()\0Iquit()\0Update()\0"
    "NameSI()\0NameSD()\0NumSI()\0NumSD()\0"
    "next()\0"
};

void Debugger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Debugger *_t = static_cast<Debugger *>(_o);
        switch (_id) {
        case 0: _t->step(); break;
        case 1: _t->quit(); break;
        case 2: _t->load(); break;
        case 3: _t->addBreak(); break;
        case 4: _t->removeBreak(); break;
        case 5: _t->acontinue(); break;
        case 6: _t->reload(); break;
        case 7: _t->inspect(); break;
        case 8: _t->Iquit(); break;
        case 9: _t->Update(); break;
        case 10: _t->NameSI(); break;
        case 11: _t->NameSD(); break;
        case 12: _t->NumSI(); break;
        case 13: _t->NumSD(); break;
        case 14: _t->next(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Debugger::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Debugger::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Debugger,
      qt_meta_data_Debugger, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Debugger::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Debugger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Debugger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Debugger))
        return static_cast<void*>(const_cast< Debugger*>(this));
    return QWidget::qt_metacast(_clname);
}

int Debugger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
