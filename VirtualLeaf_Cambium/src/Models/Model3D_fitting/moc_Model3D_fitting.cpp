/****************************************************************************
** Meta object code from reading C++ file 'Model3D_fitting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Model3D_fitting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Model3D_fitting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Model3D_fitting_t {
    const uint offsetsAndSize[2];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Model3D_fitting_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Model3D_fitting_t qt_meta_stringdata_Model3D_fitting = {
    {
QT_MOC_LITERAL(0, 15) // "Model3D_fitting"

    },
    "Model3D_fitting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Model3D_fitting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Model3D_fitting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Model3D_fitting::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Model3D_fitting.offsetsAndSize,
    qt_meta_data_Model3D_fitting,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *Model3D_fitting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model3D_fitting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Model3D_fitting.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "SimPluginInterface"))
        return static_cast< SimPluginInterface*>(this);
    if (!strcmp(_clname, "nl.cwi.VirtualLeaf.SimPluginInterface/1.3"))
        return static_cast< SimPluginInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int Model3D_fitting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1f,  'o',  'r',  'g',  '.',  'v', 
    'i',  'r',  't',  'u',  'a',  'l',  'l',  'e', 
    'a',  'f',  '.',  'M',  'o',  'd',  'e',  'l', 
    '3',  'D',  '_',  'f',  'i',  't',  't',  'i', 
    'n',  'g', 
    // "className"
    0x03,  0x6f,  'M',  'o',  'd',  'e',  'l',  '3', 
    'D',  '_',  'f',  'i',  't',  't',  'i',  'n', 
    'g', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(Model3D_fitting, Model3D_fitting)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
