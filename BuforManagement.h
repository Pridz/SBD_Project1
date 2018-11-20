#ifndef BUFOR_MANAGEMENT_H
#define BUFOR_MANAGEMENT_H

#include "Bufor.h"

class BuforManagement
{
protected:
	Bufor *bufors;
	int amountOfBufors;
	int amountOfRecords;
	int buforSize;

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

	RecordPosition getPositionOfRecord(int indx);
public:
	void setAmountOfBufors(int amountOfBufors);
	void setBufors(Bufor* bufors);	
	void setAmountOfRecords();
	void setBuforSize();
	
	int getAmountOfBufors();
	int getAmountOfRecords();
	int getBuforSize();	
	Bufor *getBufors();
};

#endif // BUFOR_MANAGEMENT_H