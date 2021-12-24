#ifndef __NOTEWIDGET_H__
#define __NOTEWIDGET_H__ 

#include <FramelessWidget.h>
#include <QWidget>
#include <quuid.h>

namespace Ui { class NoteWidget; };

class NoteWidget : public FramelessWidget
{
	Q_OBJECT

public:
	NoteWidget(QWidget* parent = Q_NULLPTR);
	~NoteWidget();

	void set_uuid(const QUuid& uuid);

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
    
private:
    void connect_all();

private:
	Ui::NoteWidget* ui;

	bool m_bDrag;
	QPoint m_windowStartPos;
	QPoint m_mousePressPos;

	QUuid m_uuid;
};

#endif
