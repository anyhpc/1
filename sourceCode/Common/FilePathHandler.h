#ifndef FILEPATHHANDLER_H
#define FILEPATHHANDLER_H
#include <string>

class FilePathHandler
{
public:
    FilePathHandler();
    static std::string getFileName(const std::string& fullPath);
    static std::string getFileDir(const std::string& fullPath);
};

#endif // FILEPATHHANDLER_H
