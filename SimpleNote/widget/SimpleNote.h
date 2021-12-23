#pragma once

#include <QtWidgets/QWidget>
#include "ui_SimpleNote.h"
#include <FramelessWidget.h>

class SimpleNote : public FramelessWidget 
{
    Q_OBJECT

public:
    SimpleNote(QWidget *parent = Q_NULLPTR);

private Q_SLOTS:
    void slot_close();
    
private:
    void connect_all();

private:
    Ui::SimpleNote ui;
};
