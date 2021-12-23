/*
* �ޱ߿򴰿ڴ���Ӱ����
* 
* v1.0:
* ֧��windows���Զ��崰�ڲ�������Ӱ�ͱ߿���ק��
* Ŀǰֻ֧�������˲��ֵĴ���
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
