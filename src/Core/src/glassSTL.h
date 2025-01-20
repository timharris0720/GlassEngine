#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
namespace Utils  {
    enum WriteType {
		Append = 0,
		Overwrite = 1,
	};
    
    std::string readFile(std::string filePath) {
        std::string FileContents = "";

        std::string line;

        std::ifstream myfile(filePath);
        if (myfile.is_open())
        {
            std::string content((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());
            FileContents = content;
            myfile.close();
        }

        return FileContents;
    }
    std::vector<std::string> readFileLines(std::string filePath) {
        std::vector<std::string> FileContents;

        std::string line;

        std::ifstream myfile(filePath);
        if (myfile.is_open())
        {
            while (getline(myfile, line)) {
                FileContents.push_back(line);
                //Logging::InfoLog("%s", line.c_str());
            }
            myfile.close();
        }


        return FileContents;
    }
    void writeFile(std::string fileData, std::string path, WriteType type) {			
        if (type == WriteType::Append) {
            std::ofstream file(path, std::ios::app);

            file << fileData + "\n";
            file.close();
        }
        else if(type == WriteType::Overwrite) { // Overwrite the file
            std::ofstream file(path);
            file << fileData;
            file.close();
        }
        
    }
}