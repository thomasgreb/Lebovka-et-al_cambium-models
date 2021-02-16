/****************************************************************************
** Meta object code from reading C++ file 'canvas.h'
**
** Created: Fri Jun 30 20:19:29 2017
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../canvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FigureEditor[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      30,   13,   13,   13, 0x05,
      45,   13,   13,   13, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_FigureEditor[] = {
    "FigureEditor\0\0status(QString)\0"
    "MousePressed()\0MouseReleased()\0"
};

const QMetaObject FigureEditor::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_FigureEditor,
      qt_meta_data_FigureEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FigureEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FigureEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FigureEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FigureEditor))
        return static_cast<void*>(const_cast< FigureEditor*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int FigureEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: status((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: MousePressed(); break;
        case 2: MouseReleased(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FigureEditor::status(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FigureEditor::MousePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FigureEditor::MouseReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
static const uint qt_meta_data_Main[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      63,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      23,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,    5,    5,    5, 0x0a,
      45,    5,    5,    5, 0x0a,
      51,    5,    5,    5, 0x0a,
      66,    5,    5,    5, 0x0a,
      86,   81,    5,    5, 0x0a,
     108,    5,    5,    5, 0x0a,
     121,    5,    5,    5, 0x0a,
     145,    5,    5,    5, 0x0a,
     163,    5,    5,    5, 0x0a,
     187,    5,    5,    5, 0x0a,
     206,    5,    5,    5, 0x0a,
     226,    5,    5,    5, 0x0a,
     246,    5,    5,    5, 0x0a,
     263,    5,    5,    5, 0x0a,
     282,    5,    5,    5, 0x0a,
     300,    5,    5,    5, 0x0a,
     322,    5,    5,    5, 0x0a,
     339,    5,    5,    5, 0x0a,
     359,    5,    5,    5, 0x0a,
     380,    5,    5,    5, 0x0a,
     398,    5,    5,    5, 0x0a,
     406,    5,    5,    5, 0x0a,
     424,    5,    5,    5, 0x0a,
     441,    5,    5,    5, 0x0a,
     458,    5,    5,    5, 0x0a,
     478,    5,    5,    5, 0x0a,
     513,  497,    5,    5, 0x0a,
     546,  538,    5,    5, 0x2a,
     567,    5,    5,    5, 0x0a,
     577,    5,    5,    5, 0x0a,
     594,    5,    5,    5, 0x0a,
     619,  610,    5,    5, 0x0a,
     645,    5,    5,    5, 0x08,
     655,    5,    5,    5, 0x08,
     665,    5,    5,    5, 0x08,
     682,    5,    5,    5, 0x08,
     732,  701,  697,    5, 0x08,
     796,  773,  697,    5, 0x28,
     850,  832,  697,    5, 0x28,
     890,  881,  697,    5, 0x28,
     916,    5,    5,    5, 0x08,
     935,    5,    5,    5, 0x08,
     954,    5,    5,    5, 0x08,
     974,    5,    5,    5, 0x08,
     993,    5,    5,    5, 0x08,
    1010,    5,    5,    5, 0x08,
    1034,    5,    5,    5, 0x08,
    1049,    5,    5,    5, 0x08,
    1060,    5,    5,    5, 0x08,
    1071,    5,    5,    5, 0x08,
    1082,    5,    5,    5, 0x08,
    1090,    5,    5,    5, 0x08,
    1097,    5,    5,    5, 0x08,
    1106,    5,    5,    5, 0x08,
    1116,    5,    5,    5, 0x08,
    1125,    5,    5,    5, 0x08,
    1134,    5,    5,    5, 0x08,
    1144,    5,    5,    5, 0x08,
    1156,    5,    5,    5, 0x08,
    1177,    5,    5,    5, 0x08,
    1201,    5,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Main[] = {
    "Main\0\0SimulationDone()\0ParsChanged()\0"
    "about()\0gpl()\0TimeStepWrap()\0"
    "togglePaused()\0size\0setFluxArrowSize(int)\0"
    "RestartSim()\0toggleShowCellCenters()\0"
    "toggleShowNodes()\0toggleShowBorderCells()\0"
    "toggleShowFluxes()\0toggleNodeNumbers()\0"
    "toggleCellNumbers()\0toggleCellAxes()\0"
    "toggleCellStrain()\0toggleShowWalls()\0"
    "toggleShowApoplasts()\0toggleDynCells()\0"
    "toggleMovieFrames()\0toggleLeafBoundary()\0"
    "toggleHideCells()\0print()\0startSimulation()\0"
    "stopSimulation()\0RefreshInfoBar()\0"
    "EnterRotationMode()\0ExitRotationMode()\0"
    "message,timeout\0UserMessage(QString,int)\0"
    "message\0UserMessage(QString)\0Refresh()\0"
    "PauseIfRunning()\0ContIfRunning()\0"
    "settings\0XMLReadSettings(xmlNode*)\0"
    "aboutQt()\0newView()\0EditParameters()\0"
    "readStateXML()\0int\0filename,geometry,pars,simtime\0"
    "readStateXML(const char*,bool,bool,bool)\0"
    "filename,geometry,pars\0"
    "readStateXML(const char*,bool,bool)\0"
    "filename,geometry\0readStateXML(const char*,bool)\0"
    "filename\0readStateXML(const char*)\0"
    "readNextStateXML()\0readPrevStateXML()\0"
    "readFirstStateXML()\0readLastStateXML()\0"
    "exportCellData()\0exportCellData(QString)\0"
    "saveStateXML()\0snapshot()\0savePars()\0"
    "readPars()\0clear()\0init()\0CutSAM()\0"
    "enlarge()\0shrink()\0zoomIn()\0zoomOut()\0"
    "CleanMesh()\0CleanMeshChemicals()\0"
    "CleanMeshTransporters()\0RandomizeMesh()\0"
};

const QMetaObject Main::staticMetaObject = {
    { &Q3MainWindow::staticMetaObject, qt_meta_stringdata_Main,
      qt_meta_data_Main, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Main::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Main::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Main::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Main))
        return static_cast<void*>(const_cast< Main*>(this));
    if (!strcmp(_clname, "MainBase"))
        return static_cast< MainBase*>(const_cast< Main*>(this));
    return Q3MainWindow::qt_metacast(_clname);
}

int Main::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Q3MainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SimulationDone(); break;
        case 1: ParsChanged(); break;
        case 2: about(); break;
        case 3: gpl(); break;
        case 4: TimeStepWrap(); break;
        case 5: togglePaused(); break;
        case 6: setFluxArrowSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: RestartSim(); break;
        case 8: toggleShowCellCenters(); break;
        case 9: toggleShowNodes(); break;
        case 10: toggleShowBorderCells(); break;
        case 11: toggleShowFluxes(); break;
        case 12: toggleNodeNumbers(); break;
        case 13: toggleCellNumbers(); break;
        case 14: toggleCellAxes(); break;
        case 15: toggleCellStrain(); break;
        case 16: toggleShowWalls(); break;
        case 17: toggleShowApoplasts(); break;
        case 18: toggleDynCells(); break;
        case 19: toggleMovieFrames(); break;
        case 20: toggleLeafBoundary(); break;
        case 21: toggleHideCells(); break;
        case 22: print(); break;
        case 23: startSimulation(); break;
        case 24: stopSimulation(); break;
        case 25: RefreshInfoBar(); break;
        case 26: EnterRotationMode(); break;
        case 27: ExitRotationMode(); break;
        case 28: UserMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 29: UserMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: Refresh(); break;
        case 31: PauseIfRunning(); break;
        case 32: ContIfRunning(); break;
        case 33: XMLReadSettings((*reinterpret_cast< xmlNode*(*)>(_a[1]))); break;
        case 34: aboutQt(); break;
        case 35: newView(); break;
        case 36: EditParameters(); break;
        case 37: readStateXML(); break;
        case 38: { int _r = readStateXML((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 39: { int _r = readStateXML((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 40: { int _r = readStateXML((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 41: { int _r = readStateXML((*reinterpret_cast< const char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 42: readNextStateXML(); break;
        case 43: readPrevStateXML(); break;
        case 44: readFirstStateXML(); break;
        case 45: readLastStateXML(); break;
        case 46: exportCellData(); break;
        case 47: exportCellData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 48: saveStateXML(); break;
        case 49: snapshot(); break;
        case 50: savePars(); break;
        case 51: readPars(); break;
        case 52: clear(); break;
        case 53: init(); break;
        case 54: CutSAM(); break;
        case 55: enlarge(); break;
        case 56: shrink(); break;
        case 57: zoomIn(); break;
        case 58: zoomOut(); break;
        case 59: CleanMesh(); break;
        case 60: CleanMeshChemicals(); break;
        case 61: CleanMeshTransporters(); break;
        case 62: RandomizeMesh(); break;
        default: ;
        }
        _id -= 63;
    }
    return _id;
}

// SIGNAL 0
void Main::SimulationDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Main::ParsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
