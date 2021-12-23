#pragma once

#include <QtWidgets/QWidget>
#include "ui_SimpleNote.h"
#include <FramelessWidget.h>

class SimpleNote : public FramelessWidget 
{
    Q_OBJECT

public:
    SimpleNote(QWidget *parent = Q_NULLPTR);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private Q_SLOTS:
    void slot_close();
    
private:
    void connect_all();

private:
    Ui::SimpleNote ui;

    bool m_bDrag;
    QPoint m_windowStartPos;
    QPoint m_mousePressPos;
};
