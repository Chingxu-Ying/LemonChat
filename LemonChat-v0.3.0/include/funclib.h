#ifndef __FUNCLIB_H__
#define __FUNCLIB_H__

#include<string>
#include<windows.h> // todo: windows.h need to be moved

/*system functions*/

void system(std::string command)
{
	system(command.c_str());
}

/*output functions*/

// print integer @x to @os with length @len
template<typename _OS_Tp,typename _Num_Tp>
void printInt(_OS_Tp &os,_Num_Tp x,int len)
{
	if(!len) return;
	printInt(os,x/10,len-1);
	os<<x%10;
}

// print char @ch to @os
template<typename _OS_Tp>
void printChar(_OS_Tp &os,char ch)
{
	os<<ch;
}

// print date @st to @os as yyyy-mm-dd hh:mm:ss
template<typename _OS_Tp>
void printDate(_OS_Tp &os,SYSTEMTIME st)
{
	printInt(os,st.wYear,4),printChar(os,'-'),printInt(os,st.wMonth,2),printChar(os,'-'),printInt(os,st.wDay,2),printChar(os,' ');
	printInt(os,st.wHour,2),printChar(os,':'),printInt(os,st.wMinute,2),printChar(os,':'),printInt(os,st.wSecond,2);
}

/*functions about string*/

// Turn Integer to String
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

// todo: enforce it
std::string encode(std::string s)
{
	const int Base=233;
	unsigned long long hsh=0;
	for(char c:s) hsh=hsh*Base+c;
	return numToStr(hsh);
}

// Check whether @s only contains '\n' or '\r'
bool checkStrEmpty(std::string s)
{
	if(s=="") return 1;
	for(char c:s) if(c!='\n'&&c!='\r'&&c!=' ') return 0;
	return 1;
}

#endif // __FUNCLIB_H__
