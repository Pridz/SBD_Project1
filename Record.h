#ifndef RECORD_H
#define RECORD_H

#include "Pesel.h"

class Record
{
	std::string name;
	std::string surname;
	Pesel pesel;

public:
	Record();
	std::string *getName();
	std::string *getSurname();
	Pesel *getPesel();

	void setName(std::string*);
	void setSurname(std::string*);
	void setPesel(Pesel*);

	void nullify();
	bool isNull();

	Record& operator=(Record& other);
};

bool operator<(Record& left, Record& right);
bool operator>(Record& left, Record& right);
bool operator==(Record& left, Record& right);
bool operator!=(Record& left, Record& right);
bool operator<=(Record& left, Record& right);

#endif