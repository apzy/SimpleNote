#include "SimpleNoteControl.h"
#include <QMutex>

QMutex g_noteControlMutex;

SimpleNoteControl::SimpleNoteControl()
{
}

SimpleNoteControl* SimpleNoteControl::instance()
{
    g_noteControlMutex.lock();
    if (m_pControl == nullptr)
    {
        m_pControl = new SimpleNoteControl();
    }
    g_noteControlMutex.unlock();
    return m_pControl;
}
