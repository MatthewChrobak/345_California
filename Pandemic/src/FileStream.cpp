#include "FileStream.h"
#ifdef DEBUG
#include <assert.h>
#endif

FileStream* FileStream::Open(std::string filename, FileMode mode)
{ 
	// Initialize the appropriate filestream object depending on the mode.
	FileStream* fs = new FileStream();

	switch (mode) {
		case FileMode::Read:
			fs->_inputFileStream = new std::ifstream(filename, std::ios::binary);
			break;
		case FileMode::Write:
			fs->_outputFileStream = new std::ofstream(filename, std::ios::binary);
			break;
	}

	return fs;
}

FileStream::FileStream()
{

}

FileStream::~FileStream()
{
	if (this->_inputFileStream != nullptr) {
		if (this->_inputFileStream->is_open()) {
			this->_inputFileStream->close();
		}
		delete this->_inputFileStream;
		this->_inputFileStream = nullptr;
	}

	if (this->_outputFileStream != nullptr) {
		if (this->_outputFileStream->is_open()) {
			this->_outputFileStream->close();
		}
		delete this->_outputFileStream;
		this->_outputFileStream = nullptr;
	}
}


void FileStream::write(int value)
{
#ifdef DEBUG
	assert(this->_outputFileStream != nullptr);
	assert(this->_outputFileStream->is_open());
#endif
	*this->_outputFileStream << value << "\n";
}

void FileStream::write(std::string value)
{
#ifdef DEBUG
	assert(this->_outputFileStream != nullptr);
	assert(this->_outputFileStream->is_open());
#endif
	*this->_outputFileStream << value << "\n";
}

std::string FileStream::readString()
{
#ifdef DEBUG
	assert(this->_inputFileStream != nullptr);
	assert(this->_inputFileStream->is_open());
#endif
	std::string line;
	std::getline(*this->_inputFileStream, line);
	line = line.erase(line.find_last_not_of(" \n\r\t") + 1);
	return line;
}

int FileStream::readInt()
{
	// Assertions not made here because they are already made
	// in the this->readString() function call.
	return std::stoi(this->readString());
}

bool FileStream::readBool()
{
	// Assertions not made here because they are already made
	// in the this->readString() function call.
	return std::stoi(this->readString());
}