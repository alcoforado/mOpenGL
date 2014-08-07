#ifndef PATH_H
#define PATH_H
#include <string>
class Path
{
private:
    std::string _path;
public:
    Path(std::string fileName);
    bool Exist();
    std::string ToString() {return _path;}
    std::string Suffix();
    std::string FileName();
    std::string FileNameWithoutSuffix();
    std::string FullPathWithoutSuffix();

};

#endif // PATH_H
