#include"BuforsHeapSort.h"

BuforsHeapSort::BuforsHeapSort(Bufor* bufors, int amountOfBufors) : bufors(bufors), size(amountOfBufors), heapSortIndex(0)
{
	for (int i = 0; i < amountOfBufors; i++)
	{
		heapSortIndex += bufors[i].getAmountOfRecords();
	}
	buforSize = bufors[0].getSize();		
	amountOfRecords = heapSortIndex;
}

int BuforsHeapSort::getSize() { return size; }

int BuforsHeapSort::getAmountOfRecords() { return amountOfRecords; }

int BuforsHeapSort::getBuforSize() { return buforSize; }

int BuforsHeapSort::getHeapSortIndex() { return heapSortIndex; }

Bufor *BuforsHeapSort::getBufors() { return bufors; }

RecordPosition BuforsHeapSort::getIndexOfRecord(int indx)
{
	assert(indx < size * buforSize);
	RecordPosition position;
	position.buforIndex = indx / buforSize;
	position.recordIndex = indx % buforSize;
	return position;
}

RecordPosition BuforsHeapSort::indexOfRecord(int indx) { return getIndexOfRecord(indx); }

void BuforsHeapSort::heapify(int indx)
{
	Record temporary;
	Record null;
	Record* parent, *leftSon, *rightSon;
	RecordPosition position;
	position = getIndexOfRecord(indx);
	parent = bufors[position.buforIndex].getRecord(position.recordIndex);
	position = getIndexOfRecord(2 * indx + 1);
	leftSon = bufors[position.buforIndex].getRecord(position.recordIndex);
	if (2*indx + 2 < heapSortIndex)
	{
		position = getIndexOfRecord(2 * indx + 2);
		rightSon = bufors[position.buforIndex].getRecord(position.recordIndex);
	}
	else
	{
		rightSon = &null;
	}
	// check if right exists
	if (rightSon->isNull())
	{
		temporary = *parent;
		if (*leftSon > *parent)
		{
			*parent = *leftSon;
			*leftSon = temporary;
			if (2 * indx + 1 <= (heapSortIndex - 2) / 2)
			{
				heapify(2 * indx + 1);
			}
		}
	}
	else
	{
		temporary = *parent;
		if (*leftSon > *rightSon && *leftSon > *parent)
		{
			*parent = *leftSon;
			*leftSon = temporary;
			if (2 * indx + 1 <= (heapSortIndex - 2) / 2)
			{
				heapify(2 * indx + 1);
			}
		}
		else if (*leftSon <= *rightSon && *rightSon > *parent)
		{
			*parent = *rightSon;
			*rightSon = temporary;
			if (2 * indx + 2 <= (heapSortIndex - 2) / 2)
			{
				heapify(2 * indx + 2);
			}
		}
	}
}

void BuforsHeapSort::correctEndOfHeap()
{
	Record temporary;
	Record* parent, *leftSon;
	RecordPosition position;
	position = getIndexOfRecord(0);
	parent = bufors[position.buforIndex].getRecord(position.recordIndex);
	position = getIndexOfRecord(1);
	leftSon = bufors[position.buforIndex].getRecord(position.recordIndex);
	temporary = *parent;
	if (*leftSon < *parent)
	{
		*parent = *leftSon;
		*leftSon = temporary;
	}
}

void BuforsHeapSort::buildHeap()
{
	for (int i = (heapSortIndex - 2) / 2; i >= 0; i--)
	{
		heapify(i);
	}
}

void BuforsHeapSort::heapSort()
{
	buildHeap();
	heapSortIndex = amountOfRecords - 1;
	Record temporary;
	Record *root, *last;
	RecordPosition position;
	position = getIndexOfRecord(0);
	root = bufors[position.buforIndex].getRecord(position.recordIndex);
	for (int i = heapSortIndex; i > 1; i--)
	{
		position = getIndexOfRecord(i);
		last = bufors[position.buforIndex].getRecord(position.recordIndex);
		temporary = *root;
		*root = *last;
		*last = temporary;
		heapify(0);
		heapSortIndex--;
	}
	correctEndOfHeap();
	heapSortIndex--;
}