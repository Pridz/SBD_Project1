#ifndef PESEL_H
#define PESEL_H

#include<string>

class Pesel
{
	static const int DATE_SIZE = 2;
	static const int SERIES_SIZE = 3;
	char year[DATE_SIZE];
	char month[DATE_SIZE];
	char day[DATE_SIZE];
	char series[SERIES_SIZE];
	char gender;
	char sumCtrl;
	static const int SIZE = 11;

	int getCentury();
	int charToInt(char);
	int decipherMonth();
public:
	Pesel();

	char* getYear();
	char* getMonth();
	char* getDay();
	int getDateSize();
	char* getSeries();
	int getSeriesSize();
	char getGender();
	char getSumCtrol();

	void setYear(char*);
	void setMonth(char*);
	void setDay(char*);
	void setSeries(char*);
	void setGender(char);
	void setSumCtrl(char);
	void setPesel(char*);

	int calculateYear();
	int calculateMonth();
	int calculateDay();

	char* toString();

	void nullify();
	bool isNull();

	Pesel& operator=(Pesel& other);

};

bool operator<(Pesel& left, Pesel& right);
bool operator>(Pesel& left, Pesel& right);
bool operator==(Pesel& left, Pesel& right);

#endif 