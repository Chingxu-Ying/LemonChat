#include<iostream>
#include<fstream>
#include"include/funclib.h"
#include"include/config.h"
int main()
{
	std::string IP="\"10.49.27.27\"";
	std::string Path="\"\\Users\\sbghj\\Desktop\\wangyizhi\\lab\\ChatData\"";

	// If color config file does not exist, then create one
	std::fstream colorConfigStream("config\\color");
	if(!colorConfigStream.good())
	{
		// default config:
		// (color: <R><G><B><INTENSITY>)
		// (example: <frColor> <bgColor>)
		// user name:	1100 0000 (6)
		// user id:		1101 0000 (14)
		// date:		0001 0000 (8)
		// message:		1111 0000 (15)
		system("echo > config\\color");
		colorConfigStream.open("config\\color");
		ColorConfig defaultConfig;
		defaultConfig.usernameColor=6;
		defaultConfig.userIDColor=14;
		defaultConfig.dateColor=8;
		defaultConfig.msgColor=15;
		writeColorConfig(colorConfigStream,defaultConfig);
	}
	colorConfigStream.close();

	std::cout<<"You can input commands here..."<<std::endl;

	std::string cmd;
	std::getline(std::cin,cmd);

	if(!checkStrEmpty(cmd))
	{
		if(cmd=="changecolor")
		{
			std::cout<<"To input color, use <R><G><B><INTENSITY>"<<std::endl;
			std::cout<<"Input front color first, then background color"<<std::endl;
			std::cout<<"Example(default setting):"<<std::endl;
			std::cout<<"user name:\t11000000"<<std::endl;
			std::cout<<"user id:\t11010000"<<std::endl;
			std::cout<<"date:\t\t00010000"<<std::endl;
			std::cout<<"message:\t11110000"<<std::endl;
			std::cout<<std::endl;

			ColorConfig newconfig;
			std::string tmp;
			std::cout<<"user name:";
			std::cin>>tmp,newconfig.usernameColor=strToColor(tmp);
			std::cout<<"user id:";
			std::cin>>tmp,newconfig.userIDColor=strToColor(tmp);
			std::cout<<"date:";
			std::cin>>tmp,newconfig.dateColor=strToColor(tmp);
			std::cout<<"message:";
			std::cin>>tmp,newconfig.msgColor=strToColor(tmp);

			std::fstream fout("config\\color");
			writeColorConfig(fout,newconfig);
		}
	}

	system("start receiver.exe "+IP+" "+Path);
	system("start sender.exe "+IP+" "+Path);
	return 0;
}
