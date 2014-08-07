#include "Path.h"
#include <string>
#include <fstream>
Path::Path(std::string fileName)
{
    _path=fileName;
}

bool Path::Exist()
{
    std::ifstream file(_path.c_str());
    return (file.good());
}

std::string Path::Suffix()
{
    if(_path.find_last_of(".") != std::string::npos)
         return _path.substr(_path.find_last_of(".")+1);
    return "";

}


std::string Path::FileName()
{
    if(_path.find_last_of("/") != std::string::npos)
        return _path.substr(_path.find_last_of("/")+1);
    else
        return _path;
}


std::string Path::FileNameWithoutSuffix()
{
    std::string fileName = this->FileName();
    return fileName.substr(0,fileName.find_last_of("."));
}

std::string Path::FullPathWithoutSuffix()
{
   return _path.substr(0,_path.find_last_of("."));
}


