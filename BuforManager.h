#ifndef BUFOR_MANAGER_H
#define BUFOR_MANAGER_H

#include "Bufor.h"
#include "InOutManager.h"
#include "BuforManagement.h"

class BuforManager : public BuforManagement
{
	SeriesCharacteristics *seriesData;
	
public:
	BuforManager();
	BuforManager(Bufor* bufors, int amountOfBufors);

	SeriesCharacteristics getDataAboutSeries(int ofIndex);
	
	void updateSeriesData(InOutManager *ioManager);	
};

#endif // BUFOR_MANAGER_H