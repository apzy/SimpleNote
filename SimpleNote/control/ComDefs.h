#ifndef __COMDEFS_H__
#define __COMDEFS_H__ 

#include <QString>

struct NOTE_INFO_STRUCT 
{
	QString filePath;
};

struct NOTE_WIDGET_INFO_STRUCT
{
	bool bShow;
	int iPosX;
	int iPosY;
	int iWidth;
	int iHeight;
	NOTE_INFO_STRUCT info;
};

#endif