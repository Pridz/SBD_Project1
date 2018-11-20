#include "InOutManager.h"

InOutManager::InOutManager() : paths(nullptr) {}

InOutManager::InOutManager(Paths *paths) : paths(paths) {}

void InOutManager::setPaths(Paths *paths) { this->paths = paths; }

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

void InOutManager::clearIndexFile()
{
	indxFileWriter.openFileStreamW(paths->seriesIndexFile);
	indxFileWriter.closeFileStream();
}

void InOutManager::readPage(Bufor* bufor)
{
	Record record;	
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

void InOutManager::readToBufors(Bufor *bufors, const int amountOfBufors)
{
	for (int i = 0; i < amountOfBufors && !fileReader.isEOF(fileReader.getInputFileStream()); i++)
	{
		readPage(&bufors[i]);
	}
}

int InOutManager::readAmountOfSeries()
{
	return indxFileReader.readAmountOfSeries();
}

void InOutManager::writeRecord(Record *record)
{
	fileWriter.writeRecord(record);
}

void InOutManager::writeSeriesPosition(int indx)
{
	int pos = fileWriter.getPositionIndicator();
	indxFileWriter.writeLine(indx, pos);
}

void InOutManager::writeBufor(Bufor* bufor)
{	
	int length = bufor->getSize();
	for (int i = 0; i < length; i++)
	{
		fileWriter.writeRecord(bufor->getRecord(i));
	}
}

void InOutManager::writeFromBuforsToFile(Bufor *bufors, int amountOfBufors)
{
	for (int i = 0; i < amountOfBufors; i++)
	{
		writeBufor(&bufors[i]);
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

bool InOutManager::isEndOfFile()
{
	return fileReader.isEOF(fileReader.getInputFileStream());
}