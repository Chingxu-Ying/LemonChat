#ifndef __LINKER_H__
#define __LINKER_H__

#include<fstream>
#include"funclib.h"

// for windows only

class Linker
{
private:
    std::string IP;
    std::string path;
public:
	Linker(){}
	Linker(std::string _IP,std::string _path)
	{
	    init(_IP,_path);
	}
	~Linker()=default;
	void init(std::string _IP,std::string _path)
	{
        IP=_IP,path=_path;
	}
    std::fstream openFile(std::string file)
    {
        return std::fstream("\\\\"+IP+path+file);
    }
    std::string getPath(std::string file)
    {
    	return std::string("\\\\"+IP+path+file);
	}
	void newFile(std::string file)
	{
		system("echo nul > \\\\"+IP+path+file);
	}
	void deleteFile(std::string file)
	{
		system("del \\\\"+IP+path+file);
	}
};

#endif // __LINKER_H__
