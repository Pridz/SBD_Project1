#ifndef BUFORS_HEAPSORT_H
#define BUFORS_HEAPSORT_H

#include "Bufor.h"
#include "BuforManagement.h"

class BuforsHeapSort : public BuforManagement
{	
	typedef BuforManagement super;	
	int heapSortIndex;

public:
	BuforsHeapSort();
	BuforsHeapSort(Bufor* bufors, int amountOfBufors);
		
	void setHeapSortIndex(int amountOfBufors);
		
	int getHeapSortIndex();		

	void heapify(int indx);
	void correctEndOfHeap();
	void buildHeap();
	void heapSort();
};

#endif