#include "FileWriter.h"

FileWriter::FileWriter() { shr_ptr_out = std::make_shared<std::fstream>(); }

std::fstream &FileWriter::getFileStream() { return *shr_ptr_out; }

void FileWriter::openFileForWritting(char *path) { shr_ptr_out->open(path, std::fstream::out); }

void FileWriter::closeFileStream() { shr_ptr_out->close(); }

int FileWriter::getPositionIndicator() { return shr_ptr_out->tellp(); }

void FileWriter::writePesel(Pesel *ptr_pesel)
{
	char* ptr_str = ptr_pesel->toString();
	std::string str(&ptr_str[0]);
	*shr_ptr_out << str;
	shr_ptr_out->put(' ');
	delete[] ptr_str;
}

void FileWriter::writeName(std::string* string)
{
	int length = string->length();
	for (int i = 0; i < length; i++)
	{
		shr_ptr_out->put(string->at(i));
	}
	shr_ptr_out->put(' ');
}

void FileWriter::writeRecord(Record* record)
{
	writeName(record->getName());
	writeName(record->getSurname());
	writePesel(record->getPesel());
}