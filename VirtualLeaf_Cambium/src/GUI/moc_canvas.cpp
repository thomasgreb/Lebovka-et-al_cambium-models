/****************************************************************************
** Meta object code from reading C++ file 'canvas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "canvas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FigureEditor_t {
    const uint offsetsAndSize[10];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FigureEditor_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FigureEditor_t qt_meta_stringdata_FigureEditor = {
    {
QT_MOC_LITERAL(0, 12), // "FigureEditor"
QT_MOC_LITERAL(13, 6), // "status"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 12), // "MousePressed"
QT_MOC_LITERAL(34, 13) // "MouseReleased"

    },
    "FigureEditor\0status\0\0MousePressed\0"
    "MouseReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FigureEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    0,   32,    2, 0x06 /* Public */,
       4,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FigureEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FigureEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->status((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->MousePressed(); break;
        case 2: _t->MouseReleased(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FigureEditor::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FigureEditor::status)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FigureEditor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FigureEditor::MousePressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FigureEditor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FigureEditor::MouseReleased)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FigureEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_FigureEditor.offsetsAndSize,
    qt_meta_data_FigureEditor,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *FigureEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FigureEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FigureEditor.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int FigureEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
void FigureEditor::status(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FigureEditor::MousePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FigureEditor::MouseReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_Main_t {
    const uint offsetsAndSize[146];
    char stringdata0[906];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Main_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Main_t qt_meta_stringdata_Main = {
    {
QT_MOC_LITERAL(0, 4), // "Main"
QT_MOC_LITERAL(5, 14), // "SimulationDone"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 11), // "ParsChanged"
QT_MOC_LITERAL(33, 8), // "setAbout"
QT_MOC_LITERAL(42, 5), // "state"
QT_MOC_LITERAL(48, 5), // "about"
QT_MOC_LITERAL(54, 3), // "gpl"
QT_MOC_LITERAL(58, 12), // "TimeStepWrap"
QT_MOC_LITERAL(71, 12), // "togglePaused"
QT_MOC_LITERAL(84, 16), // "setFluxArrowSize"
QT_MOC_LITERAL(101, 4), // "size"
QT_MOC_LITERAL(106, 10), // "RestartSim"
QT_MOC_LITERAL(117, 21), // "toggleShowCellCenters"
QT_MOC_LITERAL(139, 15), // "toggleShowNodes"
QT_MOC_LITERAL(155, 21), // "toggleShowBorderCells"
QT_MOC_LITERAL(177, 16), // "toggleShowFluxes"
QT_MOC_LITERAL(194, 17), // "toggleNodeNumbers"
QT_MOC_LITERAL(212, 17), // "toggleCellNumbers"
QT_MOC_LITERAL(230, 14), // "toggleCellAxes"
QT_MOC_LITERAL(245, 16), // "toggleCellStrain"
QT_MOC_LITERAL(262, 15), // "toggleShowWalls"
QT_MOC_LITERAL(278, 19), // "toggleShowApoplasts"
QT_MOC_LITERAL(298, 14), // "toggleDynCells"
QT_MOC_LITERAL(313, 17), // "toggleMovieFrames"
QT_MOC_LITERAL(331, 18), // "toggleLeafBoundary"
QT_MOC_LITERAL(350, 15), // "toggleHideCells"
QT_MOC_LITERAL(366, 5), // "print"
QT_MOC_LITERAL(372, 15), // "startSimulation"
QT_MOC_LITERAL(388, 14), // "stopSimulation"
QT_MOC_LITERAL(403, 14), // "RefreshInfoBar"
QT_MOC_LITERAL(418, 12), // "readStateXML"
QT_MOC_LITERAL(431, 11), // "const char*"
QT_MOC_LITERAL(443, 8), // "filename"
QT_MOC_LITERAL(452, 8), // "geometry"
QT_MOC_LITERAL(461, 4), // "pars"
QT_MOC_LITERAL(466, 7), // "simtime"
QT_MOC_LITERAL(474, 17), // "EnterRotationMode"
QT_MOC_LITERAL(492, 16), // "ExitRotationMode"
QT_MOC_LITERAL(509, 11), // "UserMessage"
QT_MOC_LITERAL(521, 7), // "message"
QT_MOC_LITERAL(529, 7), // "timeout"
QT_MOC_LITERAL(537, 7), // "Refresh"
QT_MOC_LITERAL(545, 14), // "PauseIfRunning"
QT_MOC_LITERAL(560, 13), // "ContIfRunning"
QT_MOC_LITERAL(574, 15), // "XMLReadSettings"
QT_MOC_LITERAL(590, 12), // "QDomElement&"
QT_MOC_LITERAL(603, 8), // "settings"
QT_MOC_LITERAL(612, 7), // "aboutQt"
QT_MOC_LITERAL(620, 14), // "EditParameters"
QT_MOC_LITERAL(635, 10), // "GetLeafDir"
QT_MOC_LITERAL(646, 4), // "QDir"
QT_MOC_LITERAL(651, 16), // "readNextStateXML"
QT_MOC_LITERAL(668, 16), // "readPrevStateXML"
QT_MOC_LITERAL(685, 17), // "readFirstStateXML"
QT_MOC_LITERAL(703, 16), // "readLastStateXML"
QT_MOC_LITERAL(720, 14), // "exportCellData"
QT_MOC_LITERAL(735, 12), // "saveStateXML"
QT_MOC_LITERAL(748, 17), // "GenerateNewTissue"
QT_MOC_LITERAL(766, 8), // "snapshot"
QT_MOC_LITERAL(775, 8), // "savePars"
QT_MOC_LITERAL(784, 8), // "readPars"
QT_MOC_LITERAL(793, 5), // "clear"
QT_MOC_LITERAL(799, 4), // "init"
QT_MOC_LITERAL(804, 6), // "CutSAM"
QT_MOC_LITERAL(811, 7), // "enlarge"
QT_MOC_LITERAL(819, 6), // "shrink"
QT_MOC_LITERAL(826, 6), // "zoomIn"
QT_MOC_LITERAL(833, 7), // "zoomOut"
QT_MOC_LITERAL(841, 9), // "CleanMesh"
QT_MOC_LITERAL(851, 18), // "CleanMeshChemicals"
QT_MOC_LITERAL(870, 21), // "CleanMeshTransporters"
QT_MOC_LITERAL(892, 13) // "RandomizeMesh"

    },
    "Main\0SimulationDone\0\0ParsChanged\0"
    "setAbout\0state\0about\0gpl\0TimeStepWrap\0"
    "togglePaused\0setFluxArrowSize\0size\0"
    "RestartSim\0toggleShowCellCenters\0"
    "toggleShowNodes\0toggleShowBorderCells\0"
    "toggleShowFluxes\0toggleNodeNumbers\0"
    "toggleCellNumbers\0toggleCellAxes\0"
    "toggleCellStrain\0toggleShowWalls\0"
    "toggleShowApoplasts\0toggleDynCells\0"
    "toggleMovieFrames\0toggleLeafBoundary\0"
    "toggleHideCells\0print\0startSimulation\0"
    "stopSimulation\0RefreshInfoBar\0"
    "readStateXML\0const char*\0filename\0"
    "geometry\0pars\0simtime\0EnterRotationMode\0"
    "ExitRotationMode\0UserMessage\0message\0"
    "timeout\0Refresh\0PauseIfRunning\0"
    "ContIfRunning\0XMLReadSettings\0"
    "QDomElement&\0settings\0aboutQt\0"
    "EditParameters\0GetLeafDir\0QDir\0"
    "readNextStateXML\0readPrevStateXML\0"
    "readFirstStateXML\0readLastStateXML\0"
    "exportCellData\0saveStateXML\0"
    "GenerateNewTissue\0snapshot\0savePars\0"
    "readPars\0clear\0init\0CutSAM\0enlarge\0"
    "shrink\0zoomIn\0zoomOut\0CleanMesh\0"
    "CleanMeshChemicals\0CleanMeshTransporters\0"
    "RandomizeMesh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      65,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  339,    2, 0x06 /* Public */,
       3,    0,  340,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  341,    2, 0x0a /* Public */,
       6,    0,  344,    2, 0x0a /* Public */,
       7,    0,  345,    2, 0x0a /* Public */,
       8,    0,  346,    2, 0x0a /* Public */,
       9,    0,  347,    2, 0x0a /* Public */,
      10,    1,  348,    2, 0x0a /* Public */,
      12,    0,  351,    2, 0x0a /* Public */,
      13,    0,  352,    2, 0x0a /* Public */,
      14,    0,  353,    2, 0x0a /* Public */,
      15,    0,  354,    2, 0x0a /* Public */,
      16,    0,  355,    2, 0x0a /* Public */,
      17,    0,  356,    2, 0x0a /* Public */,
      18,    0,  357,    2, 0x0a /* Public */,
      19,    0,  358,    2, 0x0a /* Public */,
      20,    0,  359,    2, 0x0a /* Public */,
      21,    0,  360,    2, 0x0a /* Public */,
      22,    0,  361,    2, 0x0a /* Public */,
      23,    0,  362,    2, 0x0a /* Public */,
      24,    0,  363,    2, 0x0a /* Public */,
      25,    0,  364,    2, 0x0a /* Public */,
      26,    0,  365,    2, 0x0a /* Public */,
      27,    0,  366,    2, 0x0a /* Public */,
      28,    0,  367,    2, 0x0a /* Public */,
      29,    0,  368,    2, 0x0a /* Public */,
      30,    0,  369,    2, 0x0a /* Public */,
      31,    4,  370,    2, 0x0a /* Public */,
      31,    3,  379,    2, 0x2a /* Public | MethodCloned */,
      31,    2,  386,    2, 0x2a /* Public | MethodCloned */,
      31,    1,  391,    2, 0x2a /* Public | MethodCloned */,
      37,    0,  394,    2, 0x0a /* Public */,
      38,    0,  395,    2, 0x0a /* Public */,
      39,    2,  396,    2, 0x0a /* Public */,
      39,    1,  401,    2, 0x2a /* Public | MethodCloned */,
      42,    0,  404,    2, 0x0a /* Public */,
      43,    0,  405,    2, 0x0a /* Public */,
      44,    0,  406,    2, 0x0a /* Public */,
      45,    1,  407,    2, 0x0a /* Public */,
      48,    0,  410,    2, 0x08 /* Private */,
      49,    0,  411,    2, 0x08 /* Private */,
      50,    0,  412,    2, 0x08 /* Private */,
      31,    0,  413,    2, 0x08 /* Private */,
      52,    0,  414,    2, 0x08 /* Private */,
      53,    0,  415,    2, 0x08 /* Private */,
      54,    0,  416,    2, 0x08 /* Private */,
      55,    0,  417,    2, 0x08 /* Private */,
      56,    0,  418,    2, 0x08 /* Private */,
      56,    1,  419,    2, 0x08 /* Private */,
      57,    0,  422,    2, 0x08 /* Private */,
      58,    0,  423,    2, 0x08 /* Private */,
      59,    0,  424,    2, 0x08 /* Private */,
      60,    0,  425,    2, 0x08 /* Private */,
      61,    0,  426,    2, 0x08 /* Private */,
      62,    0,  427,    2, 0x08 /* Private */,
      63,    0,  428,    2, 0x08 /* Private */,
      64,    0,  429,    2, 0x08 /* Private */,
      65,    0,  430,    2, 0x08 /* Private */,
      66,    0,  431,    2, 0x08 /* Private */,
      67,    0,  432,    2, 0x08 /* Private */,
      68,    0,  433,    2, 0x08 /* Private */,
      69,    0,  434,    2, 0x08 /* Private */,
      70,    0,  435,    2, 0x08 /* Private */,
      71,    0,  436,    2, 0x08 /* Private */,
      72,    0,  437,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 32, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   33,   34,   35,   36,
    QMetaType::Int, 0x80000000 | 32, QMetaType::Bool, QMetaType::Bool,   33,   34,   35,
    QMetaType::Int, 0x80000000 | 32, QMetaType::Bool,   33,   34,
    QMetaType::Int, 0x80000000 | 32,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   40,   41,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Main::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Main *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SimulationDone(); break;
        case 1: _t->ParsChanged(); break;
        case 2: _t->setAbout((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->about(); break;
        case 4: _t->gpl(); break;
        case 5: _t->TimeStepWrap(); break;
        case 6: _t->togglePaused(); break;
        case 7: _t->setFluxArrowSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->RestartSim(); break;
        case 9: _t->toggleShowCellCenters(); break;
        case 10: _t->toggleShowNodes(); break;
        case 11: _t->toggleShowBorderCells(); break;
        case 12: _t->toggleShowFluxes(); break;
        case 13: _t->toggleNodeNumbers(); break;
        case 14: _t->toggleCellNumbers(); break;
        case 15: _t->toggleCellAxes(); break;
        case 16: _t->toggleCellStrain(); break;
        case 17: _t->toggleShowWalls(); break;
        case 18: _t->toggleShowApoplasts(); break;
        case 19: _t->toggleDynCells(); break;
        case 20: _t->toggleMovieFrames(); break;
        case 21: _t->toggleLeafBoundary(); break;
        case 22: _t->toggleHideCells(); break;
        case 23: _t->print(); break;
        case 24: _t->startSimulation(); break;
        case 25: _t->stopSimulation(); break;
        case 26: _t->RefreshInfoBar(); break;
        case 27: { int _r = _t->readStateXML((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 28: { int _r = _t->readStateXML((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 29: { int _r = _t->readStateXML((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 30: { int _r = _t->readStateXML((*reinterpret_cast< const char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 31: _t->EnterRotationMode(); break;
        case 32: _t->ExitRotationMode(); break;
        case 33: _t->UserMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->UserMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 35: _t->Refresh(); break;
        case 36: _t->PauseIfRunning(); break;
        case 37: _t->ContIfRunning(); break;
        case 38: _t->XMLReadSettings((*reinterpret_cast< QDomElement(*)>(_a[1]))); break;
        case 39: _t->aboutQt(); break;
        case 40: _t->EditParameters(); break;
        case 41: { QDir _r = _t->GetLeafDir();
            if (_a[0]) *reinterpret_cast< QDir*>(_a[0]) = std::move(_r); }  break;
        case 42: _t->readStateXML(); break;
        case 43: _t->readNextStateXML(); break;
        case 44: _t->readPrevStateXML(); break;
        case 45: _t->readFirstStateXML(); break;
        case 46: _t->readLastStateXML(); break;
        case 47: _t->exportCellData(); break;
        case 48: _t->exportCellData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 49: _t->saveStateXML(); break;
        case 50: _t->GenerateNewTissue(); break;
        case 51: _t->snapshot(); break;
        case 52: _t->savePars(); break;
        case 53: _t->readPars(); break;
        case 54: _t->clear(); break;
        case 55: _t->init(); break;
        case 56: _t->CutSAM(); break;
        case 57: _t->enlarge(); break;
        case 58: _t->shrink(); break;
        case 59: _t->zoomIn(); break;
        case 60: _t->zoomOut(); break;
        case 61: _t->CleanMesh(); break;
        case 62: _t->CleanMeshChemicals(); break;
        case 63: _t->CleanMeshTransporters(); break;
        case 64: _t->RandomizeMesh(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Main::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main::SimulationDone)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Main::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main::ParsChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Main::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Main.offsetsAndSize,
    qt_meta_data_Main,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *Main::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Main.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "MainBase"))
        return static_cast< MainBase*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Main::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 65)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 65)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 65;
    }
    return _id;
}

// SIGNAL 0
void Main::SimulationDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Main::ParsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
