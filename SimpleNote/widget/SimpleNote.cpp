#include "SimpleNote.h"
#include <qevent.h>

SimpleNote::SimpleNote(QWidget* parent)
    : FramelessWidget(parent)
    , m_bDrag(false)
{
    ui.setupUi(this);
    set_style_file(":/SimpleNote/qss/SimpleNote.qss");

    connect_all();
}

void SimpleNote::slot_close()
{
    this->close();
}

void SimpleNote::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (ui.widget_title->geometry().contains(mapFromGlobal(QCursor::pos())))
        {
            m_bDrag = true;
            m_mousePressPos = event->globalPos();
            m_windowStartPos = frameGeometry().topLeft();
        }
    }
}

void SimpleNote::mouseReleaseEvent(QMouseEvent* event)
{
    m_bDrag = false;
}

void SimpleNote::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bDrag)
    {
        QPoint distance = event->globalPos() - m_mousePressPos;
        move(m_windowStartPos + distance);
    }
}

void SimpleNote::connect_all()
{
    connect(ui.btn_close, SIGNAL(clicked()), this, SLOT(slot_close()));
}
