#include "Pesel.h"

Pesel::Pesel()
{
	for (int i = 0; i < DATE_SIZE; i++)
	{
		year[i] = '\0';
		month[i] = '\0';
		day[i] = '\0';
		series[i] = '\0';
	}
	series[SERIES_SIZE - 1] = '\0';
	gender = '\0';
	sumCtrl = '\0';
}

char* Pesel::getYear() { return year; }

char* Pesel::getMonth() { return month; }

char* Pesel::getDay() { return day; }

int Pesel::getDateSize() { return DATE_SIZE; }

char* Pesel::getSeries() { return series; }

int Pesel::getSeriesSize() { return SERIES_SIZE; }

char Pesel::getGender() { return gender; }

char Pesel::getSumCtrol() { return sumCtrl; }

int Pesel::charToInt(char let) { return let - 0x30; }

void Pesel::setYear(char* year)
{
	this->year[0] = year[0];
	this->year[1] = year[1];
}

void Pesel::setMonth(char* month)
{
	this->month[0] = month[0];
	this->month[1] = month[1];
}

void Pesel::setDay(char* day)
{
	this->day[0] = day[0];
	this->day[1] = day[1];
}

void Pesel::setSeries(char* series)
{
	this->series[0] = series[0];
	this->series[1] = series[1];
	this->series[2] = series[2];
}

void Pesel::setGender(char gender) { this->gender = gender; }

void Pesel::setSumCtrl(char sumCtrl) { this->sumCtrl = sumCtrl; }

void Pesel::setPesel(char* pesel)
{
	char tmp[3];
	tmp[0] = pesel[0], tmp[1] = pesel[1];
	setYear(tmp);
	tmp[0] = pesel[2], tmp[1] = pesel[3];
	setMonth(tmp);
	tmp[0] = pesel[4], tmp[1] = pesel[3];
	setDay(tmp);
	tmp[0] = pesel[6], tmp[1] = pesel[7], tmp[2] = pesel[8];
	setSeries(tmp);
	setGender(pesel[9]);
	setSumCtrl(pesel[10]);
}

char* Pesel::toString()
{
	char* str = new char[SIZE+ 1];
	str[0] = year[0];
	str[1] = year[1];
	str[2] = month[0];
	str[3] = month[1];
	str[4] = day[0];
	str[5] = day[1];
	str[6] = series[0];
	str[7] = series[1];
	str[8] = series[2];
	str[9] = gender;
	str[10] = sumCtrl;
	str[11] = '\0';
	return str;
}

int Pesel::calculateYear() { return charToInt(year[1]) + charToInt(year[0]) * 10 + getCentury(); }

int Pesel::decipherMonth()
{
	int month = charToInt(this->month[1]);
	if (this->month[0] % 2 == 1)
	{
		month += (this->month[0] % 2) * 10;
	}
	return month;
}

int Pesel::calculateMonth() { return decipherMonth(); }

int Pesel::calculateDay() { return charToInt(day[1]) + charToInt(day[0]) * 10; }

void Pesel::nullify() { setPesel("\0\0\0\0\0\0\0\0\0\0\0"); }

bool Pesel::isNull()
{
	char *str = toString();
	for (int i = 0; i < 11; i++)
	{
		if (str[i] != '\0')
		{
			delete[] str;
			return false;
		}
	}
	delete[] str;
	return true;
}

Pesel& Pesel::operator=(Pesel& other)
{
	setYear(other.getYear());
	setMonth(other.getMonth());
	setDay(other.getDay());
	setSeries(other.getSeries());
	setGender(other.getGender());
	setSumCtrl(other.getSumCtrol());
	return *this;
}

bool operator<(Pesel& left, Pesel& right)
{
	if (left.calculateYear() < right.calculateYear())
	{
		return true;
	}
	if (left.calculateYear() == right.calculateYear() && left.calculateMonth() < right.calculateMonth())
	{
		return true;
	}
	if (left.calculateYear() == right.calculateYear() && left.calculateMonth() == right.calculateMonth() && left.calculateDay() < right.calculateDay())
	{
		return true;
	}
	if (left.calculateYear() == right.calculateYear() && left.calculateMonth() == right.calculateMonth() && left.calculateDay() == right.calculateDay() && left.getGender() < right.getGender())
	{
		return true;
	}
	return false;
}

bool operator>(Pesel& left, Pesel& right) { return right < left; }

bool operator==(Pesel& left, Pesel& right)
{
	std::string left_str = left.toString();
	std::string right_str = right.toString();
	return left_str == right_str;
}