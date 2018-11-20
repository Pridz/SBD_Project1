#include "FileSorter.h"

FileSorter::FileSorter(Bufor* bufors, int amountOfBufors, Paths* paths)
{
	buforManager.setBufors(bufors);
	buforManager.setAmountOfBufors(amountOfBufors);
	heapSort.setBufors(bufors);
	heapSort.setBuforSize();
	heapSort.setHeapSortIndex(amountOfBufors);
	heapSort.setAmountOfRecords();
	ioManager.setPaths(paths);;

}

void FileSorter::sortingPhase()
{
	ioManager.prepareFilesForSortingPhase();
	int amountOfSeries = 0;
	while (!ioManager.isEndOfFile())
	{
		ioManager.readToBufors(buforManager.getBufors(), buforManager.getAmountOfBufors());
		heapSort.heapSort();
		ioManager.writeFromBuforsToFile(buforManager.getBufors(), buforManager.getAmountOfBufors());
		ioManager.writeSeriesPosition(amountOfSeries);
		amountOfSeries++;
	}
	ioManager.writeAmountOfSeries(amountOfSeries);
	ioManager.closeFilesForSortingPhase();
}

void FileSorter::sortFile()
{
	sortingPhase();
	ioManager.openIndexFileForReading();
	buforManager.updateSeriesData(&ioManager);
	ioManager.closeIndexFileForReading();
	ioManager.clearIndexFile();
}