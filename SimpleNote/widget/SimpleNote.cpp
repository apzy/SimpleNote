#include "SimpleNote.h"

SimpleNote::SimpleNote(QWidget *parent)
    : FramelessWidget(parent)
{
    ui.setupUi(this);
    set_style_file(":/SimpleNote/qss/SimpleNote.qss");
}
