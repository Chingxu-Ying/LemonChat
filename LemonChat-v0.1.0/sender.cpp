#include<iostream>
#include"include/funclib.h"
#include"IOlinker.h"
int main(int argc,char **argv)
{
	IOLinker link("10.49.27.27","\\Users\\sbghj\\Desktop\\wangyizhi\\lab\\LemonChat");
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
		SYSTEMTIME st;
		GetSystemTime(&st);
		link.sendMessage(message{
			uid,st,msg
		});
	}
}
