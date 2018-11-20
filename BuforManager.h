#ifndef BUFOR_MANAGER_H
#define BUFOR_MANAGER_H

#include "Bufor.h"
#include "InOutManager.h"
#include "BuforManagement.h"

class BuforManager : public BuforManagement
{
	typedef BuforManagement super;
	SeriesCharacteristics *seriesData;
	
	RecordPosition getClosestRecordsPosition(int buforsRange);
public:
	BuforManager();
	BuforManager(Bufor* bufors, int amountOfBufors);

	SeriesCharacteristics getDataAboutSeries(int ofIndex);
	
	void updateSeriesData(InOutManager *ioManager);	
	RecordPosition getLeastRecordPosition(int buforsRange);
};

#endif // BUFOR_MANAGER_H