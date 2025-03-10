#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include<windows.h>

int mixColor(bool R,bool G,bool B,bool INTENSITY=0)
{
	return (R<<2)|(G<<1)|(B)|(INTENSITY<<3);
}

void setColor(int fColor,int bgColor=0)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),bgColor<<4|fColor);
}

#endif // __CONSOLE_H__
