#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

class FileSystem
{
public:
	static bool fileExists(std::string file);
	static bool directoryExists(std::string directory);
	static void createDirectory(std::string directory);

	static std::string getStartupPath();
	static std::vector<std::string> getFiles(std::string directory);
	static std::vector<std::string> getDirectories(std::string directory);

private:
	static std::string _startupPath;
	static std::vector<std::string> _getFolderContents(std::string directory, const int attribute);
};

