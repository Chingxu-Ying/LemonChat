#ifndef __IO_LLINKER_H__
#define __IO_LLINKER_H__

#include"include/funclib.h"
#include"include/linker.h"
#include<windows.h>

struct message
{
	int user;
	SYSTEMTIME time;
	std::string msg;
};

class IOLinker
{
	Linker link;
public:
	IOLinker(){}
	IOLinker(std::string _IP,std::string _path):link(_IP,_path){}
	~IOLinker()=default;
	int getCount()
	{
		std::fstream fin=link.openFile("\\data\\records\\#");
		int cnt=0;
		fin>>cnt;
		return cnt;
	}
	void updateCount(int x)
	{
		std::fstream fout=link.openFile("\\data\\records\\#");
		fout<<x<<std::endl;
	}
	message readRecord(int x)
	{
		std::fstream fin=link.openFile("\\data\\records\\"+numToStr(x));
		message record;
		fin>>record.user;
		fin>>record.time.wYear>>record.time.wMonth>>record.time.wDay>>record.time.wDayOfWeek;
		fin>>record.time.wHour>>record.time.wMinute>>record.time.wSecond;
		char ch=fin.get();
		while(ch=='\n'||ch=='\r') ch=fin.get();
		while(ch!=EOF) record.msg+=ch,ch=fin.get();
		return record;
	}
	void writeRecord(int x,message record)
	{
		link.newFile("\\data\\records\\"+numToStr(x));
		std::fstream fout=link.openFile("\\data\\records\\"+numToStr(x));
		fout<<record.user<<std::endl;
		fout<<record.time.wYear<<" "<<record.time.wMonth<<" "<<record.time.wDay<<" "<<record.time.wDayOfWeek<<" ";
		fout<<record.time.wHour<<" "<<record.time.wMinute<<" "<<record.time.wSecond<<std::endl;
		fout<<record.msg<<std::endl;
	}
	void sendMessage(message msg)
	{
		int x=getCount()+1;
		updateCount(x);
		writeRecord(x,msg);
	}
	std::fstream openUserFile(int id)
	{
	    return link.openFile("\\data\\users\\"+numToStr(id));
	}
	void newUserFile(int id,std::string name,std::string password)
	{
		link.newFile("\\data\\users\\"+numToStr(id));
		std::fstream fout=openUserFile(id);
		fout<<name<<std::endl<<password<<std::endl;
	}
	void deleteUserFile(int id)
	{
		link.deleteFile("\\data\\users\\"+numToStr(id));
	}
};

#endif // __IO_LLINKER_H__
