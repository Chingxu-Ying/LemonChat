#include<iostream>
#include<sstream>
#include"include/funclib.h"
#include"IOlinker.h"
#include"include/console.h"
int userMain(IOLinker link)
{
	system("title LemonChatV0.3.0-Sender");

	system("cls");

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

	system("title LemonChatV0.3.0-Sender (login as "+numToStr(uid)+")");
	std::cout<<"Welcome!"<<std::endl;
	Sleep(2000);
	std::fflush(stdin);
	std::fflush(stdout);
	system("cls");

	while(1)
	{
		system("cls");

		std::string msg;
		std::getline(std::cin,msg);

		if(!link.openUserFile(uid).good())
		{
			setColor(mixColor(1,0,0,1));
			std::cerr<<"Detected that your account has been deleted!"<<std::endl;
			Sleep(2000);
			return 0;
		}

		for(int i=0;i<(int)msg.size()-1;i++)
		{
			if(msg[i]=='\\'&&msg[i+1]=='\\')
				msg.erase(msg.begin()+i);
			else if(msg[i]=='\\'&&msg[i+1]=='n')
				msg[i]='\n',msg.erase(msg.begin()+i+1);
			else if(msg[i]=='\\'&&msg[i+1]=='t')
				msg[i]='\t',msg.erase(msg.begin()+i+1);
		}

		if(checkStrEmpty(msg)) continue;

		// if it's a command
		if(msg.size()>2&&msg[0]==':'&&msg[1]=='c'&&msg[2]=='>')
		{
			msg.erase(msg.begin(),msg.begin()+3);
			std::stringstream strin(msg);

			std::string cmd;
			strin>>cmd;

			// logout
			if(cmd=="logout")
			{
				return 0;
			}

			// exit
			if(cmd=="exit")
			{
				exit(0);
			}

			// quit sender and receiver
			if(cmd=="quit")
			{
				system("taskkill /im receiver.exe");
				exit(0);
			}

			if(cmd=="reopen")
			{
				system("taskkill /im receiver.exe");
				system("start LemonChat.exe");
				exit(0);
			}

			if(cmd=="delete")
			{
				link.deleteUserFile(uid);
				return 0;
			}

			continue;
		}

		// deal with message
		SYSTEMTIME st;
		GetSystemTime(&st);

		link.sendMessage(message{
			uid,st,msg
		});

		Sleep(100);
	}
	return 0;
}
int main(int argc,char **argv)
{
	if(argc<3)
	{
		std::cerr<<"invalid input\n";
		return 0;
	}

	std::cerr<<argv[1]<<std::endl<<argv[2]<<std::endl<<std::endl;
	IOLinker link(argv[1],argv[2]);

	while(1) userMain(link);

	return 0;
}
