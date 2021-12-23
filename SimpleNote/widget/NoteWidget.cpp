#include "NoteWidget.h"
#include "ui_NoteWidget.h"

#include <qevent.h>

NoteWidget::NoteWidget(QWidget* parent)
	: FramelessWidget(parent)
	, m_bDrag(false)
{
	ui = new Ui::NoteWidget();
	ui->setupUi(this);

	set_style_file(":/SimpleNote/qss/NoteWidget.qss");

	connect_all();
}

NoteWidget::~NoteWidget()
{
	delete ui;
}

void NoteWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		if (ui->widget_title->geometry().contains(mapFromGlobal(QCursor::pos())))
		{
			m_bDrag = true;
			m_mousePressPos = event->globalPos();
			m_windowStartPos = frameGeometry().topLeft();
		}
	}
}

void NoteWidget::mouseReleaseEvent(QMouseEvent* event)
{
	m_bDrag = false;
}

void NoteWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bDrag)
	{
		QPoint distance = event->globalPos() - m_mousePressPos;
		move(m_windowStartPos + distance);
	}
}

void NoteWidget::slot_close()
{
	close();
}

void NoteWidget::slot_new()
{
    NoteWidget* note = new NoteWidget();
    note->show();
}

void NoteWidget::connect_all()
{
    connect(ui->btn_close, SIGNAL(clicked()), this, SLOT(slot_close()));
    connect(ui->btn_add, SIGNAL(clicked()), this, SLOT(slot_new()));
}
