#ifndef __COMDEFS_H__
#define __COMDEFS_H__ 

#include <QString>
#include <QDateTime>
#include <quuid.h>

#define NOTE_WIDTH 304
#define NOTE_HEIGHT 312
#define MARGIN_DEFAULT 12

struct NOTE_WIDGET_INFO_STRUCT
{
	bool bShow;
	int iPosX;
	int iPosY;
	int iWidth;
	int iHeight;
};

struct NOTE_INFO_STRUCT 
{
	QUuid uuid;
	QString filePath;
	QDateTime updateTime;
	NOTE_WIDGET_INFO_STRUCT widgetInfo;
};

#endif