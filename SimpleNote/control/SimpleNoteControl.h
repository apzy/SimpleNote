#ifndef __SIMPLENOTECONTROL_H__
#define __SIMPLENOTECONTROL_H__ 

#include <QList>
#include "ComDefs.h"

class SimpleNoteControl
{
public:
	static SimpleNoteControl* instance();

	QUuid add_note();

	void remove_note(const QUuid& uuid);

	void update_widget_pos(const QUuid& uuid, const int& x, const int& y);

	void update_widget_size(const QUuid& uuid, const int& width, const int& height);

	bool exist_widget_show();

private:
	SimpleNoteControl();
	~SimpleNoteControl();

private:
	static SimpleNoteControl* m_pControl;

	QList<NOTE_INFO_STRUCT> m_noteList;

};

#endif
