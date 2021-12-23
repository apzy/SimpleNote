/*
* 无边框窗口带阴影基类
* 
* v1.0:
* 支持windows下自定义窗口并设置阴影和边框拖拽。
* 目前只支持设置了布局的窗口
*
*/

#ifndef __FRAMELESSWIDGET_H__
#define __FRAMELESSWIDGET_H__ 1

#include <QtWidgets/QWidget>

class Q_DECL_EXPORT FramelessWidget : public QWidget
{
	Q_OBJECT
public:
	FramelessWidget(QWidget* parent = Q_NULLPTR);

	void set_resizable(const bool enable);

protected:
	bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

private:
	void set_widget_border();

	void drop_on_border_or_coner(const MSG* msg, qintptr* result);

private:
	bool m_resizable;
};

#endif
