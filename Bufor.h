#ifndef BUFOR_H
#define BUFOR_H

#include"Record.h"

class Bufor
{
	int index;
	int size;
	Record *records;

public:
	Bufor(int);
	int getSize();
	int getIndex();
	Record* getRecord(int indx);

	void setIndex(int);
	void setRecord(Record* rcrd, int indx);

	void nullify();

	bool isBuforFull();
};

#endif