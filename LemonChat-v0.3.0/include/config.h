#ifndef __CONFIG_H__
#define __CONFIG_H__

#include<iostream>
#include"console.h"

typedef int Color;

Color strToColor(std::string colorStr)
{
	if(colorStr.size()<8) return Color();
	bool s[8];
	for(int i=0;i<8;i++) s[i]=colorStr[i]!='0';
	return Color((mixColor(s[0],s[1],s[2],s[3]))|(mixColor(s[4],s[5],s[6],s[7])<<4));
}

struct ColorConfig
{
	Color usernameColor,userIDColor,dateColor,msgColor;
};

// write color config @config to @os
template<typename _Tp>
void writeColorConfig(_Tp &os,ColorConfig config)
{
	os<<config.usernameColor<<std::endl<<config.userIDColor<<std::endl<<config.dateColor<<std::endl<<config.msgColor<<std::endl;
}

// read color config @config from @is
template<typename _Tp>
void readColorConfig(_Tp &is,ColorConfig &config)
{
	is>>config.usernameColor>>config.userIDColor>>config.dateColor>>config.msgColor;
}

#endif // __CONFIG_H__
