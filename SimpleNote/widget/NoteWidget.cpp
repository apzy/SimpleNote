#include "NoteWidget.h"
#include "ui_NoteWidget.h"

#include <qevent.h>
#include "../control/SimpleNoteControl.h"

NoteWidget::NoteWidget(const QUuid& uuid, QWidget* parent)
	: FramelessWidget(parent)
	, m_uuid(uuid)
	, m_bDrag(false)
{
	ui = new Ui::NoteWidget();
	ui->setupUi(this);

	set_style_file(":/SimpleNote/qss/NoteWidget.qss");

	init_view();

	connect_all();
}

NoteWidget::~NoteWidget()
{
	delete ui;
}

QUuid NoteWidget::get_uuid()
{
	return m_uuid;
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
	SimpleNoteControl::instance()->close_note(m_uuid);
	close();
}

void NoteWidget::slot_new()
{
	QUuid uuid = SimpleNoteControl::instance()->add_note();
	int iPosX = this->pos().x() + this->width() + MARGIN_DEFAULT;
	int iPosY = this->pos().y();
	SimpleNoteControl::instance()->update_widget_pos(uuid, iPosX, iPosY);

	NoteWidget* note = new NoteWidget(uuid);
	note->setGeometry(iPosX, iPosY, NOTE_WIDTH, NOTE_HEIGHT);
	note->show();
}

void NoteWidget::slot_click_bold()
{
	if (ui->btn_bold->isChecked())
	{
		ui->editor->text_normal();
	}
	else
	{
		ui->editor->text_bold();
	}
}

void NoteWidget::slot_click_italic()
{
	ui->editor->text_italic(!ui->btn_italic->isChecked());
}

void NoteWidget::slot_click_under_line()
{
	ui->editor->text_under_line(!ui->btn_under_line->isChecked());
}

void NoteWidget::slot_click_del_line()
{
	ui->editor->text_del_line(!ui->btn_del_line->isChecked());
}

void NoteWidget::init_view()
{
	setWindowFlag(Qt::SubWindow);

	QIcon icon;
	icon.addPixmap(QPixmap(":/SimpleNote/img/top.png"), QIcon::Normal, QIcon::Off);
	icon.addPixmap(QPixmap(":/SimpleNote/img/cancle_top.png"), QIcon::Normal, QIcon::On);
	ui->btn_top->setIcon(icon);
}

void NoteWidget::connect_all()
{
    connect(ui->btn_close, SIGNAL(clicked()), this, SLOT(slot_close()));
    connect(ui->btn_add, SIGNAL(clicked()), this, SLOT(slot_new()));
    connect(ui->btn_bold, SIGNAL(pressed()), this, SLOT(slot_click_bold()));
    connect(ui->btn_italic, SIGNAL(pressed()), this, SLOT(slot_click_italic()));
    connect(ui->btn_under_line, SIGNAL(pressed()), this, SLOT(slot_click_under_line()));
    connect(ui->btn_del_line, SIGNAL(pressed()), this, SLOT(slot_click_del_line()));
}
