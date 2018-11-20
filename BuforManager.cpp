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