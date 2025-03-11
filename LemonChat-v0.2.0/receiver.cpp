#include<iostream>
#include<map>
#include"IOlinker.h"
#include"include/console.h"
std::map<int,std::string> userName;
int main(int argc,char **argv)
{
	if(argc<3)
	{
		std::cerr<<"invalid input\n";
		return 0;
	}

	std::cerr<<argv[1]<<std::endl<<argv[2]<<std::endl<<std::endl;
	IOLinker link(argv[1],argv[2]);
	int cur=std::max(0,link.getCount()-100);
	while(1)
	{
		Sleep(10);
		if(link.getCount()>cur)
		{
			Sleep(100);

			cur++;
			message newmsg=link.readRecord(cur);

			if(!userName.count(newmsg.user))
			{
				std::fstream fin=link.openUserFile(newmsg.user);
				fin>>userName[newmsg.user];
			}

//			setColor(mixColor(0,0,0,1));
//			std::cout<<cur<<" ";

			setColor(mixColor(1,1,0));
			std::cout<<userName[newmsg.user]<<" ";

			setColor(mixColor(1,1,0,1));
			std::cout<<newmsg.user<<" ";

			setColor(mixColor(0,0,0,1));
			printDate(std::cout,newmsg.time);
			std::cout<<std::endl;

			setColor(mixColor(1,1,1,1));
			std::cout<<newmsg.msg<<std::endl;
		}
		if(cur!=0&&link.getCount()==0)
		{
			cur=0;
			setColor(mixColor(1,0,0,1));
			std::cerr<<"System: Detected that the Server has been restarted"<<std::endl;
			std::cerr<<"The records will be deleted in 2 seconds..."<<std::endl;
			Sleep(2000);
			system("cls");
		}
	}
}
