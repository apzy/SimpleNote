#include "NoteWidget.h"
#include "ui_NoteWidget.h"

#include <qevent.h>
#include <QTimer>
#include "../control/SimpleNoteControl.h"

NoteWidget::NoteWidget(const QUuid& uuid, QWidget* parent)
	: FramelessWidget(parent)
	, m_uuid(uuid)
	, m_bDrag(false)
	, m_info(SimpleNoteControl::instance()->get_note_info(m_uuid))
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
	if (ui->editor->toPlainText().isEmpty())
	{
		SimpleNoteControl::instance()->remove_note(m_uuid);
	}
	else
	{
		if (m_saveTimer->isActive())
		{
			m_saveTimer->stop();
			slot_save_timer_update();
		}
		SimpleNoteControl::instance()->close_note(m_uuid);
	}
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

void NoteWidget::slot_click_top()
{
	if (ui->btn_top->isChecked())
	{
		setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
		ui->btn_top->setChecked(false);
	}
	else
	{
		setWindowFlag(Qt::WindowStaysOnTopHint);
		ui->btn_top->setChecked(true);
	}
	// 设置窗口置顶后要重新调用show()显示窗口
	// 因为setWindowFlag是调用setParent设置窗口样式时
	show();
}

void NoteWidget::slot_editor_text_changed()
{
	m_saveTimer->stop();
	m_saveTimer->start();
}

void NoteWidget::slot_editor_format_changed(const QTextCharFormat &format)
{
	qDebug("format changed");
}

void NoteWidget::slot_save_timer_update()
{
	m_saveTimer->stop();
	ui->editor->save_file(m_info.filePath);
}

void NoteWidget::init_view()
{
	setWindowFlag(Qt::SubWindow);

	QIcon icon;
	icon.addPixmap(QPixmap(":/SimpleNote/img/top.png"), QIcon::Normal, QIcon::Off);
	icon.addPixmap(QPixmap(":/SimpleNote/img/cancel_top.png"), QIcon::Normal, QIcon::On);
	ui->btn_top->setIcon(icon);

	slot_click_top();
	ui->btn_top->setChecked(true);

	m_saveTimer = new QTimer();
	m_saveTimer->setInterval(2000);
}

void NoteWidget::connect_all()
{
    connect(ui->btn_close, SIGNAL(clicked()), this, SLOT(slot_close()));
    connect(ui->btn_add, SIGNAL(clicked()), this, SLOT(slot_new()));
    connect(ui->btn_bold, SIGNAL(pressed()), this, SLOT(slot_click_bold()));
    connect(ui->btn_italic, SIGNAL(pressed()), this, SLOT(slot_click_italic()));
    connect(ui->btn_under_line, SIGNAL(pressed()), this, SLOT(slot_click_under_line()));
    connect(ui->btn_del_line, SIGNAL(pressed()), this, SLOT(slot_click_del_line()));
    connect(ui->btn_top, SIGNAL(pressed()), this, SLOT(slot_click_top()));

	connect(ui->editor, &QTextEdit::textChanged, this, &NoteWidget::slot_editor_text_changed);
	connect(ui->editor, &QTextEdit::currentCharFormatChanged, this, &NoteWidget::slot_editor_format_changed);
	connect(m_saveTimer, &QTimer::timeout, this, &NoteWidget::slot_save_timer_update);
}
