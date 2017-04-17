#include "FileSystem.h"
#include <boost/filesystem.hpp>
#define PATH_SEPARATOR "\\"

bool FileSystem::fileExists(std::string file)
{
	return boost::filesystem::is_regular_file(file) && boost::filesystem::exists(file);
}

bool FileSystem::directoryExists(std::string directory)
{
	return boost::filesystem::is_directory(directory) && boost::filesystem::exists(directory);
}

std::string FileSystem::getStartupPath()
{
	return boost::filesystem::current_path().string();
}

std::vector<std::string> FileSystem::getFiles(std::string directory)
{
	boost::filesystem::path p(directory);
	boost::filesystem::directory_iterator itr(p.make_preferred().native());
	boost::filesystem::directory_iterator end;
	std::vector<std::string> files;

	// Keep looping while the iterator is valid.
	while (itr != end)
	{
		// If the path is a valid file
		if (fileExists(itr->path().string())) {
			// extract the filename, and add it to the vector.
			std::string path = itr->path().string();
			path = path.substr(path.find_last_of(PATH_SEPARATOR) + 1);
			files.push_back(path);
		}
		itr++;
	}

	return files;
}

std::vector<std::string> FileSystem::getDirectories(std::string directory)
{
	boost::filesystem::path p(directory);
	boost::filesystem::directory_iterator itr(p.make_preferred().native());
	boost::filesystem::directory_iterator end;
	std::vector<std::string> directories;

	// Keep looping while the iterator is valid.
	while (itr != end)
	{
		// If the path is a valid directory
		if (directoryExists(itr->path().string())) {
			// extract the pathname, and add it to the vector.
			std::string path = itr->path().string();
			path = path.substr(path.find_last_of(PATH_SEPARATOR) + 1);
			directories.push_back(path);
		}
		itr++;
	}

	return directories;
}

void FileSystem::createDirectory(std::string directory)
{
	boost::filesystem::create_directories(directory);
}