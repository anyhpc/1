#include "FilePathHandler.h"

#include <fstream>
#include <sstream>

FilePathHandler::FilePathHandler()
{

}

std::string FilePathHandler::getFileName(const std::string& fullPath)
{
    size_t pos = fullPath.rfind('/');
    if (pos == std::string::npos)
    {
        pos = fullPath.rfind('\\');
    }

    if (pos == std::string::npos)
    {
        return fullPath;
    }
    else
    {
        return fullPath.substr(pos);
    }
}

std::string FilePathHandler::getFileDir(const std::string& fullPath)
{
    size_t pos = fullPath.rfind('/');
    if (pos == std::string::npos)
    {
        pos = fullPath.rfind('\\');
    }

    if (pos == std::string::npos)
    {
        return fullPath;
    }
    else
    {
        return fullPath.substr(0, pos);
    }
}

 bool FilePathHandler::isFileExist(const std::string& fullPath)
 {
    std::fstream file;
    file.open(fullPath, std::ios::in);
    if (!file)
    {
        return false;
    }
    else
    {
        return true;
    }
 }

std::string FilePathHandler::generateUniqueFileName(const std::string& fullPath)
{
    std::string tempFileName = fullPath;
    unsigned int index = 1;
    while (isFileExist(tempFileName))
    {
       std::stringstream sstr;
       sstr << index;
       tempFileName = fullPath + "_" + sstr.str();
       ++index;
    }
    return tempFileName;
}
