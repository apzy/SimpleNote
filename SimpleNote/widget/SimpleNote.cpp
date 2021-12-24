#include "SimpleNote.h"
#include <qevent.h>

#include "NoteWidget.h"
#include "../control/SimpleNoteControl.h"

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
    if (SimpleNoteControl::instance()->exist_widget_show())
        this->hide();
    else
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

void SimpleNote::slot_new()
{
    QUuid uuid = SimpleNoteControl::instance()->add_note();
    int iPosX = this->pos().x() + this->width() + MARGIN_DEFAULT;
    int iPosY = this->pos().y();
    SimpleNoteControl::instance()->update_widget_size(uuid, NOTE_WIDTH, NOTE_HEIGHT);
    SimpleNoteControl::instance()->update_widget_pos(uuid, iPosX, iPosY);

    NoteWidget* note = new NoteWidget();
    note->setGeometry(iPosX, iPosY, NOTE_WIDTH, NOTE_HEIGHT);
    note->set_uuid(uuid);
    note->show();
}

void SimpleNote::connect_all()
{
    connect(ui.btn_close, SIGNAL(clicked()), this, SLOT(slot_close()));
    connect(ui.btn_new, SIGNAL(clicked()), this, SLOT(slot_new()));
}
