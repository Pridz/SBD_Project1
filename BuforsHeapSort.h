#ifndef BUFORS_HEAPSORT_H
#define BUFORS_HEAPSORT_H

#include "Bufor.h"

struct RecordPosition
{
	int buforIndex;
	int recordIndex;
	RecordPosition() : buforIndex(0), recordIndex(0) {}

	RecordPosition& operator=(RecordPosition& other)
	{
		buforIndex = other.buforIndex;
		recordIndex = other.recordIndex;
		return *this;
	}
};

class BuforsHeapSort
{
	Bufor *bufors;
	int size;
	int amountOfRecords;
	int buforSize;
	int heapSortIndex;

	RecordPosition getIndexOfRecord(int indx);
public:
	BuforsHeapSort(Bufor*, int);

	int getSize();
	int getAmountOfRecords();
	int getBuforSize();
	int getHeapSortIndex();
	Bufor *getBufors();

	RecordPosition indexOfRecord(int indx);

	void heapify(int indx);
	void correctEndOfHeap();
	void buildHeap();
	void heapSort();
};

#endif