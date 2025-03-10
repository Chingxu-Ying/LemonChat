#ifndef __FUNCLIB_H__
#define __FUNCLIB_H__

#include<string>
#include<windows.h>

void system(std::string command)
{
    system(command.c_str());
}

template<typename _OS_Tp>
void printInt(_OS_Tp &os,int x,int len)
{
    if(!len) return;
    printInt(os,x/10,len-1);
    os<<x%10;
}

template<typename _OS_Tp>
void printChar(_OS_Tp &os,char ch)
{
    os<<ch;
}

template<typename _OS_Tp>
void printDate(_OS_Tp &os,SYSTEMTIME st)
{
    printInt(os,st.wYear,4),printChar(os,'-'),printInt(os,st.wMonth,2),printChar(os,'-'),printInt(os,st.wDay,2),printChar(os,' ');
    printInt(os,st.wHour,2),printChar(os,':'),printInt(os,st.wMinute,2),printChar(os,':'),printInt(os,st.wSecond,2);
}

// Notice : "num" must be positive
template<typename _Tp>
std::string numToStr(_Tp num)
{
    std::string res;
    while(num)
    {
        res=char('0'+num%10)+res;
        num/=10;
    }
    return res;
}

std::string encode(std::string s)
{
    std::string tb;
    while(tb.size()<128) tb+=s;
    for(char &c:s) c=tb[(int)c];
    return s;
}

#endif // __FUNCLIB_H__
