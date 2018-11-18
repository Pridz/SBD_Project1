#include "InOutManager.h"

InOutManager::InOutManager(Bufor *bufors, Paths *paths) : bufors(bufors), paths(paths) {}

void InOutManager::prepareFilesForSortingPhase()
{
	fileReader.openFileStream(paths->dataFile);
	fileWriter.openFileForWritting(paths->seriesFile);
	indxFileWriter.openFileStreamW(paths->seriesIndexFile);	
}

void InOutManager::closeFilesForSortingPhase()
{
	fileReader.closeFileStream();
	fileWriter.closeFileStream();
	indxFileWriter.closeFileStream();
}

void InOutManager::openIndexFileForReading() { indxFileReader.prepareForReading(paths->seriesIndexFile); }

void InOutManager::closeIndexFileForReading() { indxFileReader.closeFileStream(); }


void InOutManager::readPage( int buforNumber)
{
	Record record;
	Bufor *bufor = &bufors[buforNumber];
	int length = bufor->getSize();
	for (int i = 0; i < length; i++)
	{
		record = fileReader.readRecord();
		if (record.isNull())
		{
			return;
		}
		bufor->setRecord(&record, i);
	}
}

void InOutManager::readToBufors(const int amountOfBufors)
{
	for (int i = 0; i < amountOfBufors && !fileReader.isEOF(fileReader.getInputFileStream()); i++)
	{
		readPage(i);
	}
}

int InOutManager::readAmountOfSeries()
{
	return indxFileReader.readAmountOfSeries();
}

void InOutManager::writeSeriesPosition(int indx)
{
	int pos = fileWriter.getPositionIndicator();
	indxFileWriter.writeLine(indx, pos);
}

void InOutManager::writeBufor(int buforNumber)
{
	Bufor *bufor = &bufors[buforNumber];
	int length = bufor->getSize();
	for (int i = 0; i < length; i++)
	{
		fileWriter.writeRecord(bufors[buforNumber].getRecord(i));
	}
}

void InOutManager::writeFromBuforsToFile(int amountOfBufors)
{
	for (int i = 0; i < amountOfBufors; i++)
	{
		writeBufor(i);
	}
}

SeriesCharacteristics InOutManager::readSeriesCharacteristics(int indx)
{
	return indxFileReader.getTheSeriesCharacteristics(indx);
}

void InOutManager::writeAmountOfSeries(int amountOfSeries)
{
	indxFileWriter.writeAmountOfSeries(amountOfSeries);
}