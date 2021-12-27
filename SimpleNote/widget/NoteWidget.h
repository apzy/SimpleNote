#ifndef __NOTEWIDGET_H__
#define __NOTEWIDGET_H__ 

#include <FramelessWidget.h>
#include <QWidget>
#include <quuid.h>
#include <QTextCharFormat>
#include "../control/ComDefs.h"

namespace Ui { class NoteWidget; };

class NoteWidget : public FramelessWidget
{
	Q_OBJECT

public:
	NoteWidget(const QUuid& uuid, QWidget* parent = Q_NULLPTR);
	~NoteWidget();

	QUuid get_uuid();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private Q_SLOTS:
    void slot_close();
    void slot_new();
	void slot_click_bold();
	void slot_click_italic();
	void slot_click_under_line();
	void slot_click_del_line();
	void slot_click_top();
	void slot_editor_text_changed();
	void slot_editor_format_changed(const QTextCharFormat& format);
	void slot_save_timer_update();
    
private:
	void init_view();
    void connect_all();

private:
	Ui::NoteWidget* ui;

	bool m_bDrag;
	QPoint m_windowStartPos;
	QPoint m_mousePressPos;

	QUuid m_uuid;

	QTimer* m_saveTimer;

	const NOTE_INFO_STRUCT& m_info;
};

#endif
