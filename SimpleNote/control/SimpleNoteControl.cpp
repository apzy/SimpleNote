#include "SimpleNoteControl.h"
#include <QMutex>

QMutex g_noteControlMutex;

SimpleNoteControl* SimpleNoteControl::m_pControl = nullptr;

SimpleNoteControl::SimpleNoteControl()
{
}

SimpleNoteControl::~SimpleNoteControl()
{
    if (m_pControl != nullptr)
    {
        delete m_pControl;
    }
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

QUuid SimpleNoteControl::add_note()
{
    NOTE_INFO_STRUCT info;
    info.uuid = QUuid::createUuid();
    info.widgetInfo.bShow = true;
    m_noteList.push_back(info);
    return info.uuid;
}

void SimpleNoteControl::remove_note(const QUuid& uuid)
{
    int i;
    for (i = 0; i < m_noteList.size(); ++i)
    {
        if (m_noteList.at(i).uuid == uuid)
        {
            m_noteList.removeAt(i);
            break;
        }
    }
}

void SimpleNoteControl::update_widget_pos(const QUuid& uuid, const int& x, const int& y)
{
    for (auto& item : m_noteList)
    {
        if (item.uuid == uuid)
        {
            item.widgetInfo.iPosX = x;
            item.widgetInfo.iPosY = y;
            break;
        }
    }
}

void SimpleNoteControl::update_widget_size(const QUuid& uuid, const int& width, const int& height)
{ 
    for (auto& item : m_noteList)
    {
        if (item.uuid == uuid)
        {
            item.widgetInfo.iWidth = width;
            item.widgetInfo.iHeight = height;
            break;
        }
    }
}

bool SimpleNoteControl::exist_widget_show()
{
    bool bRet = false;
    for (auto& item : m_noteList)
    {
        if (item.widgetInfo.bShow)
        {
            bRet = true;
            break;
        }
    }
    return bRet;
}
