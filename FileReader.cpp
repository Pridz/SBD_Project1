#include "FileReader.h"

FileReader::FileReader(Bufor* bufors) : bufors(bufors) {}

std::string FileReader::readText(std::fstream *fileStream)
{
	char str[20];
	std::string text;
	detectSpaceAndSkip(*fileStream);
	if (!isEOF(*shr_ptr_in))
	{
		fileStream->get(str, 20, ' ');
		int i = 0;
		for (i; str[i] != '\0'; i++);
		str[i] = '\0';
		text = str;
	}
	return text;
}

Pesel FileReader::readPesel(std::fstream *fileStream)
{
	char str[12];
	Pesel pesel;
	detectSpaceAndSkip(*fileStream);
	fileStream->get(str, 12, ' ');
	pesel.setPesel(str);
	return pesel;
}

Record FileReader::readRecord(std::fstream *fileStream)
{
	Record record;
	if (!isEOF(*fileStream))
	{
		record.setName(&readText(fileStream));
		record.setSurname(&readText(fileStream));
		record.setPesel(&readPesel(fileStream));
	}
	return record;
}

void FileReader::readPage(std::fstream *fileStream, int buforNumber)
{
	Record record;
	Bufor *bufor = &bufors[buforNumber];
	int length = bufor->getSize();
	for (int i = 0; i < length; i++)
	{
		record = readRecord(fileStream);
		if (record.isNull())
		{
			return;
		}
		bufor->setRecord(&readRecord(fileStream), i);
	}
}

void FileReader::readToBufors(std::fstream *fileStream, const int amountOfBufors)
{
	for (int i = 0; i < amountOfBufors && !isEOF(*fileStream); i++)
	{
		readPage(fileStream, i);
	}
}
//void FileReader::readPageOfSeries(std::fstream *fileStream, int buforNumber)
//{
//	Bufor *bufor = &bufors[buforNumber];
//	int length = bufor->getSize();
//	for (int i = 0; i < length && !seriesIndexOfBufors[buforNumber].isEndOfSeries(); i++)
//	{
//		bufor->setRecord(&readRecord(fileStream), i);
//	}
//}