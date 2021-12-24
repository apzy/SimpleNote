#ifndef __SIMPLENOTECONTROL_H__
#define __SIMPLENOTECONTROL_H__ 

class SimpleNoteControl
{
public:
	static SimpleNoteControl* instance();

private:
	SimpleNoteControl();

private:
	static SimpleNoteControl* m_pControl;

};

#endif
