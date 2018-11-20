#ifndef BUFOR_MANAGER_H
#define BUFOR_MANAGER_H

#include "Bufor.h"
#include "InOutManager.h"
#include "BuforsHeapSort.h"

class BuforManager
{
	Bufor *bufors;
	int amountOfBufors;	
	SeriesCharacteristics *seriesData;

	
public:
	BuforManager();
	BuforManager(Bufor* bufors, int amountOfBufors);

	void setBufors(Bufor *bufors);
	void setAmountOfBufors(int amountOfBufors);

	Bufor *getBufors();
	int getAmountOfBufors();
	SeriesCharacteristics getDataAboutSeries(int ofIndex);
	
	void updateSeriesData(InOutManager *ioManager);	
};

#endif // BUFOR_MANAGER_H