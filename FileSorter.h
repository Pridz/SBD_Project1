#ifndef FILE_SORTER_H
#define FILE_SORTER_H

#include "BuforManager.h"
#include "InOutManager.h"
#include"BuforsHeapSort.h"

class FileSorter
{
	BuforManager buforManager;
	InOutManager ioManager;
	BuforsHeapSort heapSort;

	void sortingPhase();
	void mergingPhase();
public:
	FileSorter(Bufor *bufors, int amountOfBufors, Paths* paths);

	void sortFile();
};

#endif // FILE_SORTER_H