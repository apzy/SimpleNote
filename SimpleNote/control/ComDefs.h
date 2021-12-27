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
	bool bTop;
	int iPosX;
	int iPosY;
	int iWidth;
	int iHeight;

	NOTE_WIDGET_INFO_STRUCT()
	{
		bShow = true;
		bTop = true;
		iWidth = NOTE_WIDTH;
		iHeight = NOTE_HEIGHT;
		iPosX = 0;
		iPosY = 0;
	}
};

struct NOTE_INFO_STRUCT 
{
	QUuid uuid;
	QString filePath;
	QDateTime updateTime;
	NOTE_WIDGET_INFO_STRUCT widgetInfo;
};

#endif