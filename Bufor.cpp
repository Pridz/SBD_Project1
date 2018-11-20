#include "Bufor.h"

Bufor::Bufor() : index(0), size(0), records(nullptr) {}

Bufor::Bufor(int size) : size(size), index(0)
{
	records = new Record[size];
}

Bufor::~Bufor()
{
	delete[] records;
}

int Bufor::getSize() { return size; }

int Bufor::getIndex() { return index; }

Record* Bufor::getRecord(int indx) { return &records[indx]; }

int Bufor::getAmountOfRecords() { return index; }

void Bufor::setIndex(int indx) 
{
	if (indx <= size)
	{
		index = indx; 
	}
	assert(indx <= size);
}

void Bufor::setRecord(Record* rcd, int indx)
{
	if (indx < size)
	{
		if (indx < index)
		{
			records[indx] = *rcd;	
		}
		if (index == indx)
		{	
			records[indx] = *rcd;
			index++;
		}
	}
	assert(indx < size);
}

bool Bufor::areRecordsInitialized() { return records; }

void Bufor::changeRecords()
{
	if (records)
	{
		delete[] records;
	}
	records = new Record[size];
}

void Bufor::setSize(int size)
{
	this->size = size;
	changeRecords();
}

void Bufor::nullify()
{
	for (int i = 0; i < index; i++)
	{
		records[i].nullify();
	}
	index = 0;
}

bool Bufor::isBuforFull() { return index == size; }