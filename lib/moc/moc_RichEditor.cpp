/****************************************************************************
** Meta object code from reading C++ file 'RichEditor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../RichEditor.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RichEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RichEditor_t {
    const uint offsetsAndSize[28];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RichEditor_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RichEditor_t qt_meta_stringdata_RichEditor = {
    {
QT_MOC_LITERAL(0, 10), // "RichEditor"
QT_MOC_LITERAL(11, 9), // "open_file"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 8), // "filePath"
QT_MOC_LITERAL(31, 9), // "save_file"
QT_MOC_LITERAL(41, 11), // "text_normal"
QT_MOC_LITERAL(53, 9), // "text_bold"
QT_MOC_LITERAL(63, 11), // "text_italic"
QT_MOC_LITERAL(75, 7), // "bItalic"
QT_MOC_LITERAL(83, 15), // "text_under_line"
QT_MOC_LITERAL(99, 6), // "bUnder"
QT_MOC_LITERAL(106, 13), // "text_del_line"
QT_MOC_LITERAL(120, 4), // "bDel"
QT_MOC_LITERAL(125, 13) // "get_file_path"

    },
    "RichEditor\0open_file\0\0filePath\0save_file\0"
    "text_normal\0text_bold\0text_italic\0"
    "bItalic\0text_under_line\0bUnder\0"
    "text_del_line\0bDel\0get_file_path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RichEditor[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x0a,    1 /* Public */,
       4,    0,   71,    2, 0x0a,    3 /* Public */,
       4,    1,   72,    2, 0x0a,    4 /* Public */,
       5,    0,   75,    2, 0x0a,    6 /* Public */,
       6,    0,   76,    2, 0x0a,    7 /* Public */,
       7,    1,   77,    2, 0x0a,    8 /* Public */,
       9,    1,   80,    2, 0x0a,   10 /* Public */,
      11,    1,   83,    2, 0x0a,   12 /* Public */,
      13,    0,   86,    2, 0x0a,   14 /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::QString,

       0        // eod
};

void RichEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RichEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->open_file((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->save_file();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->save_file((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->text_normal(); break;
        case 4: _t->text_bold(); break;
        case 5: _t->text_italic((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 6: _t->text_under_line((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 7: _t->text_del_line((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 8: { QString _r = _t->get_file_path();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject RichEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QTextEdit::staticMetaObject>(),
    qt_meta_stringdata_RichEditor.offsetsAndSize,
    qt_meta_data_RichEditor,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RichEditor_t
, QtPrivate::TypeAndForceComplete<RichEditor, std::true_type>
, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const bool &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const bool &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const bool &, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *RichEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RichEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RichEditor.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int RichEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
