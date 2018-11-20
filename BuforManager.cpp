#include "BuforManager.h"

BuforManager::BuforManager() : seriesData(nullptr) 
{
	bufors = nullptr;
	amountOfBufors = 0;
	amountOfRecords = 0;
	buforSize = 0;
}

BuforManager::BuforManager(Bufor* bufors, int amountOfBufors)
{
	this->bufors = bufors;
	this->amountOfBufors = amountOfBufors;
	setAmountOfRecords();
	setBuforSize();
	seriesData = nullptr;
}

SeriesCharacteristics BuforManager::getDataAboutSeries(int index)
{
	if (index < amountOfBufors)
	{
		return seriesData[index];
	}
	assert(index < amountOfBufors);
}

void BuforManager::updateSeriesData(InOutManager *ioManager)
{
	if (seriesData)
	{
		delete[] seriesData;
	}
	int amountOfSeries = ioManager->readAmountOfSeries();
	seriesData = new SeriesCharacteristics[amountOfSeries];
	for (int i = 0; i < amountOfSeries; i++)
	{
		seriesData[i] = ioManager->readSeriesCharacteristics(i);
	}
}

BuforManager::RecordPosition BuforManager::getClosestRecordsPosition(int buforsRange)
{
	Record *record;
	RecordPosition position;
	if (buforsRange > amountOfBufors)
	{
		assert(buforsRange <= amountOfBufors);
		return position;
	}
	for (int i = 0; i < buforSize * buforsRange; i++)
	{
		position = getPositionOfRecord(i);
		record = bufors[position.buforIndex].getRecord(position.recordIndex);
		if (!record->isNull())
		{
			return position;
		}
	}
	return position;
}

BuforManager::RecordPosition BuforManager::getLeastRecordPosition(int buforsRange)
{
	RecordPosition position = getClosestRecordsPosition(buforsRange);
	int length = amountOfBufors * buforSize;
	Record *ptr_record = bufors[position.buforIndex].getRecord(position.recordIndex);
	for (int i = 0; i < length; i++)
	{
		position = getPositionOfRecord(i);
		if (*ptr_record > *bufors[position.buforIndex].getRecord(position.recordIndex))
		{
			ptr_record = bufors[position.buforIndex].getRecord(position.recordIndex);
		}		
	}
	return position;
}