#include "Bufor.h"

Bufor::Bufor(int size) : size(size), index(0)
{
	records = new Record[size];
}

int Bufor::getSize() { return size; }

int Bufor::getIndex() { return index; }

Record* Bufor::getRecord(int indx) { return &records[indx]; }

void Bufor::setIndex(int indx) 
{
	if (indx <= size)
	{
		index = indx; 
	}
}

void Bufor::setRecord(Record* rcd, int indx)
{
	if (indx < size)
	{
		records[indx] = *rcd;
	}
}

void Bufor::nullify()
{
	for (int i = 0; i < index; i++)
	{
		records[i].nullify();
	}
}

bool Bufor::isBuforFull() { return index == size; }