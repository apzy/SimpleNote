#pragma once

#include <QtWidgets/QWidget>
#include "ui_SimpleNote.h"

class SimpleNote : public QWidget
{
    Q_OBJECT

public:
    SimpleNote(QWidget *parent = Q_NULLPTR);

private:
    Ui::SimpleNoteClass ui;
};
