#ifndef FILE_READING_OPERATIONS_H
#define FILE_READING_OPERATIONS_H

#include<fstream>

class FileReadingOperations
{
public:
	void detectSpaceAndSkip(std::fstream &);

	bool isCharacterSpace(char*);
	bool isEOF(std::fstream &fileStream);
};

#endif // FILE_READING_OPERATIONS_H