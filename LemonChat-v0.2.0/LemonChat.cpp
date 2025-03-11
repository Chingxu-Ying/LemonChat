#include<iostream>
#include"include/funclib.h"
int main()
{
	std::string IP="\"10.49.27.27\"";
	std::string Path="\"\\Users\\sbghj\\Desktop\\wangyizhi\\lab\\LemonChat\"";
	system("start receiver.exe "+IP+" "+Path);
	system("start sender.exe "+IP+" "+Path);
	return 0;
}
