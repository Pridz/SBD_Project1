#include "FileReader.h"

FileReader::FileReader() { shr_ptr_in = std::make_shared<std::fstream>(); }

void FileReader::openFileStream(char* path) 
{	
	shr_ptr_in->open(path, std::fstream::in);
}

std::fstream &FileReader::getInputFileStream() { return *shr_ptr_in; }

void FileReader::closeFileStream() { shr_ptr_in->close(); }

std::string FileReader::readText()
{
	char str[20];
	std::string text;
	FileReadingOperations::detectSpaceAndSkip(*shr_ptr_in);
	if (!FileReadingOperations::isEOF(*shr_ptr_in))
	{
		shr_ptr_in->get(str, 20, ' ');
		int i = 0;
		for (i; str[i] != '\0'; i++);
		str[i] = '\0';
		text = str;
	}
	return text;
}

Pesel FileReader::readPesel()
{
	char str[12];
	Pesel pesel;
	FileReadingOperations::detectSpaceAndSkip(*shr_ptr_in);
	shr_ptr_in->get(str, 12, ' ');
	pesel.setPesel(str);
	return pesel;
}

Record FileReader::readRecord()
{
	Record record;
	if (!FileReadingOperations::isEOF(*shr_ptr_in))
	{
		record.setName(&readText());
		record.setSurname(&readText());
		record.setPesel(&readPesel());
	}
	return record;
}

//void FileReader::readPage(std::fstream *fileStream, int buforNumber)
//{
//	Record record;
//	Bufor *bufor = &bufors[buforNumber];
//	int length = bufor->getSize();
//	for (int i = 0; i < length; i++)
//	{
//		record = readRecord(fileStream);
//		if (record.isNull())
//		{
//			return;
//		}
//		bufor->setRecord(&readRecord(fileStream), i);
//	}
//}

void FileReader::readToBufors(std::fstream *fileStream, const int amountOfBufors)
{
	for (int i = 0; i < amountOfBufors && !FileReadingOperations::isEOF(*fileStream); i++)
	{
		//readPage(fileStream, i);
	}
}
//void FileReader::readPageOfOneSeries(std::fstream *fileStream, int buforNumber)
//{
//	Bufor *bufor = &bufors[buforNumber];
//	int length = bufor->getSize();
//	for (int i = 0; i < length && !seriesIndexOfBufors[buforNumber].isEndOfSeries(); i++)
//	{
//		bufor->setRecord(&readRecord(fileStream), i);
//	}
//}