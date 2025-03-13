#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include<windows.h>

// for windows only

/*functions to control the console*/

// mix color with @R, @G, @B and @INTENSITY
int mixColor(bool R,bool G,bool B,bool INTENSITY=0)
{
	return (R<<2)|(G<<1)|(B)|(INTENSITY<<3);
}

// set output front color as @fColor and background color as @bgColor
void setColor(int fColor,int bgColor=0)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),bgColor<<4|fColor);
}

#endif // __CONSOLE_H__
