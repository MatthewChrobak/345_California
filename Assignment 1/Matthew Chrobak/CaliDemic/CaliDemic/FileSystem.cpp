#include "FileSystem.h"

std::string FileSystem::_startupPath = std::string();


bool FileSystem::fileExists(std::string file)
{
	// GetFileAttributes returns 0xFFFFFFFF if the path does not exist.
	DWORD attr = GetFileAttributes(file.c_str());
	return (attr != 0xFFFFFFFF && attr != FILE_ATTRIBUTE_DIRECTORY);
}

bool FileSystem::directoryExists(std::string directory)
{
	// GetFileAttributes returns 0xFFFFFFFF if the path does not exist.
	DWORD attr = GetFileAttributes(directory.c_str());
	return (attr != 0xFFFFFFFF && attr == FILE_ATTRIBUTE_DIRECTORY);
}

std::string FileSystem::getStartupPath()
{
	// Has the startup path been assigned?
	if (FileSystem::_startupPath.length() == 0) {
		// Stores the full application name into a TCHAR array.
		TCHAR path[MAX_PATH];
		GetModuleFileName(NULL, path, MAX_PATH);
		
		// Get the substring of the full path.
		FileSystem::_startupPath = std::string(path);
		FileSystem::_startupPath = FileSystem::_startupPath.substr(0, FileSystem::_startupPath.find_last_of('\\') + 1);
	}

	return FileSystem::_startupPath;
}

std::vector<std::string> FileSystem::getFiles(std::string directory)
{
	std::vector<std::string> files;
	WIN32_FIND_DATA searchData;
	HANDLE searchHandle;

	// Get the search handle based on the given string and ensure it's a valid handle.
	searchHandle = FindFirstFile(directory.c_str(), &searchData);
	if (searchHandle != INVALID_HANDLE_VALUE) {
		do {
			if (searchData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY) {
				files.push_back(searchData.cFileName);
			}
			// Search for the next file.
		} while (FindNextFile(searchHandle, &searchData));
	}
	else {
		std::cout << "Error" << std::endl;
		std::cout << searchHandle << std::endl;
		std::cout << GetLastError() << std::endl;
	}

	return files;
}

std::vector<std::string> FileSystem::getDirectories(std::string directory)
{
	std::vector<std::string> files;
	WIN32_FIND_DATA searchData;
	HANDLE searchHandle;

	// Get the search handle based on the given string and ensure it's a valid handle.
	searchHandle = FindFirstFile(directory.c_str(), &searchData);
	if (searchHandle != INVALID_HANDLE_VALUE) {
		do {
			if (searchData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY) {
				files.push_back(searchData.cFileName);

				// Make sure we're not referring to the .. or . folders.
				if (files.back() == ".." || files.back() == ".") {
					files.pop_back();
				}
			}
			// Search for the next file.
		} while (FindNextFile(searchHandle, &searchData));
	}
	else {
		std::cout << "Error" << std::endl;
		std::cout << searchHandle << std::endl;
		std::cout << GetLastError() << std::endl;
	}

	return files;
}

std::vector<std::string> FileSystem::_getFolderContents(std::string directory, const int attribute)
{
	// TODO:	Take in a comparison function, ideally something like isFile() or isDirectory()
	//			to purify the files.
	std::vector<std::string> x;
	return x;
}

void FileSystem::createDirectory(std::string directory)
{
	if (!CreateDirectory(directory.c_str(), NULL)) {
		std::cout << "[createLocalDirectory] FAILED" << std::endl;
	}
}