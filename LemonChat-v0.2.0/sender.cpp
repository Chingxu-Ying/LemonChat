#include<iostream>
#include"include/funclib.h"
#include"IOlinker.h"
#include"include/console.h"
int main(int argc,char **argv)
{
	if(argc<3)
	{
		std::cerr<<"invalid input\n";
		return 0;
	}

	std::cerr<<argv[1]<<std::endl<<argv[2]<<std::endl<<std::endl;
	IOLinker link(argv[1],argv[2]);

	int uid;
	std::cout<<"uid: ";
	std::cin>>uid;

	if(link.openUserFile(uid).good())
	{
		std::string name,password,code;
		std::fstream fin=link.openUserFile(uid);
		fin>>name>>code;
		do
		{
			std::cout<<"Password: ";
			std::cin>>password;
		}while(encode(password)!=code);
	}
	else
	{
		std::string name,password;
		std::cout<<"Name: ";
		std::cin>>name;
		std::cout<<"Password: ";
		std::cin>>password;
		link.newUserFile(uid,name,encode(password));
	}

	std::cout<<"Welcome!"<<std::endl;
	Sleep(2000);
	std::fflush(stdin);
	std::fflush(stdout);
	system("cls");

	while(1)
	{
		std::string msg;
		std::getline(std::cin,msg);

		if(!link.openUserFile(uid).good())
		{
			setColor(mixColor(1,0,0,1));
			std::cerr<<"Detected that your account has been deleted!"<<std::endl;
			Sleep(2000);
			return 0;
		}

		if(msg==""||msg=="\n"||msg=="\r\n") continue;

		SYSTEMTIME st;
		GetSystemTime(&st);

		link.sendMessage(message{
			uid,st,msg
		});

		Sleep(100);

		system("cls");
	}
}
