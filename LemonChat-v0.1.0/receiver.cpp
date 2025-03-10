#include<iostream>
#include<map>
#include"IOlinker.h"
#include"include/console.h"
std::map<int,std::string> userName;
int main(int argc,char **argv)
{
	IOLinker link("10.49.27.27","\\Users\\sbghj\\Desktop\\wangyizhi\\lab\\LemonChat");
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

			setColor(mixColor(1,1,0));
            std::cout<<userName[newmsg.user]<<" ";

            setColor(mixColor(1,1,0,1));
            printDate(std::cout,newmsg.time);
            std::cout<<std::endl;

			setColor(mixColor(1,1,1));
			std::cout<<newmsg.msg<<std::endl;
		}
	}
}
