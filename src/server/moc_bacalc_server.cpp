/****************************************************************************
** Meta object code from reading C++ file 'bacalc_server.h'
**
** Created: Tue Jan 19 18:50:08 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bacalc_server.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bacalc_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Server[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      27,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Server[] = {
    "Server\0\0acceptConnection()\0startRead()\0"
};

const QMetaObject Server::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Server,
      qt_meta_data_Server, 0 }
};

const QMetaObject *Server::metaObject() const
{
    return &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Server))
        return static_cast<void*>(const_cast< Server*>(this));
    return QObject::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: acceptConnection(); break;
        case 1: startRead(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
