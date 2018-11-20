#ifndef BUFOR_H
#define BUFOR_H

#include"Record.h"
#include<cassert>

class Bufor
{
	int index;
	int size;
	Record *records;

	void changeRecords();
	bool areRecordsInitialized();
public:
	Bufor();
	Bufor(int);
	~Bufor();
	int getSize();
	int getIndex();
	Record* getRecord(int indx);
	int getAmountOfRecords();

	void setIndex(int);
	void setRecord(Record* rcrd, int indx);
	void setRecord(Record* record);
	void setSize(int);

	void nullify();

	bool isBuforFull();
};

#endif