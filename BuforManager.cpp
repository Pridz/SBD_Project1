#include "BuforManager.h"

BuforManager::BuforManager() : bufors(nullptr), amountOfBufors(0), seriesData(nullptr) {}

BuforManager::BuforManager(Bufor* bufors, int amountOfBufors) : bufors(bufors), amountOfBufors(amountOfBufors)
{
	seriesData = nullptr;
}

void BuforManager::setBufors(Bufor *bufors) { this->bufors = bufors; }

void BuforManager::setAmountOfBufors(int amountOfBufors) { this->amountOfBufors = amountOfBufors; }

Bufor *BuforManager::getBufors() { return bufors; }

int BuforManager::getAmountOfBufors() { return amountOfBufors; }

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