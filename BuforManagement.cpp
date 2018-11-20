#include "BuforManagement.h"

void BuforManagement::setBufors(Bufor* bufors) { this->bufors = bufors; }

void BuforManagement::setAmountOfBufors(int amountOfBufors) { this->amountOfBufors = amountOfBufors; }

void BuforManagement::setBuforSize() { buforSize = bufors[0].getSize(); }

void BuforManagement::setAmountOfRecords() 
{
	for (int i = 0; i < amountOfBufors; i++)
	{
		amountOfRecords += bufors[i].getAmountOfRecords();
	}	
}

int BuforManagement::getAmountOfBufors() { return amountOfBufors; }

int BuforManagement::getAmountOfRecords() { return amountOfRecords; }

int BuforManagement::getBuforSize() { return buforSize; }

Bufor *BuforManagement::getBufors() { return bufors; }

BuforManagement::RecordPosition BuforManagement::getIndexOfRecord(int indx)
{
	assert(indx < amountOfBufors * buforSize);
	RecordPosition position;
	position.buforIndex = indx / amountOfBufors;
	position.recordIndex = indx % buforSize;
	return position;
}