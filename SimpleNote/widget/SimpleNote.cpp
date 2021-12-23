#include "SimpleNote.h"

SimpleNote::SimpleNote(QWidget *parent)
    : FramelessWidget(parent)
{
    ui.setupUi(this);
    set_style_file(":/SimpleNote/qss/SimpleNote.qss");

    connect_all();
}

void SimpleNote::slot_close()
{
    this->close();
}

void SimpleNote::connect_all()
{
    connect(ui.btn_close, SIGNAL(clicked()), this, SLOT(slot_close()));
}
