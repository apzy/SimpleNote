#ifndef __NOTEWIDGET_H__
#define __NOTEWIDGET_H__ 

#include <FramelessWidget.h>
#include <QWidget>

namespace Ui { class NoteWidget; };

class NoteWidget : public FramelessWidget
{
	Q_OBJECT

public:
	NoteWidget(QWidget* parent = Q_NULLPTR);
	~NoteWidget();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private Q_SLOTS:
    void slot_close();
    void slot_new();
    
private:
    void connect_all();

private:
	Ui::NoteWidget* ui;

	bool m_bDrag;
	QPoint m_windowStartPos;
	QPoint m_mousePressPos;
};

#endif
