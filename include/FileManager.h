#ifndef AMER_DELIC_FILEMANAGER_H
#define AMER_DELIC_FILEMANAGER_H


#include <fstream>

class FileManager {

public:

    static bool CanOpenFile(std::fstream &file, std::string fileName);

    static std::string ReadFile(std::fstream &file);

    static std::string ReadFile(std::fstream &file, char delimiter);

    static std::string ReadFile(std::fstream &file, unsigned int numberOfLines);

};


#endif //AMER_DELIC_FILEMANAGER_H
