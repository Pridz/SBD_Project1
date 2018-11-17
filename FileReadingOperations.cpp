#include "FileReadingOperations.h"

bool FileReadingOperations::isCharacterSpace(char* character) {	return *character == ' '; }

void FileReadingOperations::detectSpaceAndSkip(std::fstream &fileStream)
{
	int pos = fileStream.tellg();
	char character;
	fileStream.get(character);
	//bool state = fileStream.eof();
	if (isCharacterSpace(&character))
	{
		fileStream.seekg(pos + 1);
	}
	else
	{
		fileStream.seekg(pos);
	}
}


bool FileReadingOperations::isEOF(std::fstream &fileStream)
{
	int pos = fileStream.tellg();
	char character;
	fileStream.get(character);
	if (isCharacterSpace(&character))
	{
		fileStream.get(character);
		if (fileStream.eof())
		{
			fileStream.seekg(pos);
			return true;
		}
		fileStream.seekg(pos);
		return false;
	}
	if (fileStream.eof())
	{
		fileStream.seekg(pos);
		return true;
	}
	if (pos == EOF)
	{
		fileStream.seekg(pos);
		return true;
	}
	fileStream.seekg(pos);
	return false;
}