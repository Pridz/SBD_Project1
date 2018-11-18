#include "IndexFileReader.h"

IndexFileReader::IndexFileReader() : amount(0) { shr_ptr_in_indx = std::make_shared<std::fstream>(); }

std::fstream &IndexFileReader::getFileStream() { return *shr_ptr_in_indx; }

void IndexFileReader::openFileStream(char* path) { shr_ptr_in_indx->open(path, std::fstream::in); }

void IndexFileReader::closeFileStream() { shr_ptr_in_indx->close(); }

void IndexFileReader::setPositionIndicator(int pos) { shr_ptr_in_indx->seekg(pos); }

int IndexFileReader::getPositionIndicator() { return shr_ptr_in_indx->tellg(); }

int IndexFileReader::readInteger()
{
	int number;
	*shr_ptr_in_indx >> number;
	return number;
}

int IndexFileReader::readAmountOfSeries() 
{
	int pos = getPositionIndicator();
	setPositionIndicator(0);
	int amount = readInteger();
	setPositionIndicator(pos);
	return amount;
}

void IndexFileReader::prepareForReading(char* path) 
{
	openFileStream(path);
	amount = readAmountOfSeries();
}

bool IndexFileReader::isSuchSeries(int indx)
{
	return indx < amount;
}

void IndexFileReader::missLine()
{	
	shr_ptr_in_indx->ignore(20, '\n');
}

void IndexFileReader::missLines(int lines)
{
	for (int i = 0; i < lines; i++)
	{
		shr_ptr_in_indx->ignore(20, '\n');
	}
}

void IndexFileReader::missSpace() { shr_ptr_in_indx->ignore(2, ' '); }

void IndexFileReader::setPositionIndicatorOnTheSeriesLine(int indx)
{
	setPositionIndicator(0);	
	missLines(2);
	missLines(indx);
}

SeriesCharacteristics IndexFileReader::readSeriesLine()
{
	SeriesCharacteristics characteristics;
	characteristics.index = readInteger();
	missSpace();
	characteristics.endingPosition = readInteger();
	return characteristics;
}

SeriesCharacteristics IndexFileReader::getTheSeriesCharacteristics(int indx)
{
	SeriesCharacteristics characteristics;
	if (isSuchSeries(indx))
	{
		int pos = getPositionIndicator();
		setPositionIndicatorOnTheSeriesLine(indx);
		characteristics = readSeriesLine();
		setPositionIndicator(pos);
	}
	return characteristics;
}