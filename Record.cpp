#include "Record.h"

Record::Record() { }

Pesel* Record::getPesel() { return &pesel; }

std::string *Record::getName() { return &name; }

std::string *Record::getSurname() { return &surname; }

void Record::nullify()
{
	name.clear();
	surname.clear();
	pesel.nullify();
}

bool Record::isNull() { return pesel.isNull() && name.empty() && surname.empty(); }

Record& Record::operator=(Record& other)
{
	if (this != &other)
	{
		name = *other.getName();
		surname = *other.getSurname();
		pesel = *other.getPesel();
	}
	return *this;
}

bool operator<(Record& left, Record& right) { return *(left.getPesel()) < *(right.getPesel()) || (*(left.getPesel()) == *(right.getPesel()) && *(left.getSurname()) < *(right.getSurname())) || (*(left.getPesel()) == *(right.getPesel()) && *(left.getSurname()) == *(right.getSurname()) && *(left.getName()) < *(right.getName())); }
bool operator>(Record& left, Record& right) { return *(left.getPesel()) > *(right.getPesel()) || (*(left.getPesel()) == *(right.getPesel()) && *(left.getSurname()) > *(right.getSurname())) || (*(left.getPesel()) == *(right.getPesel()) && *(left.getSurname()) == *(right.getSurname()) && *(left.getName()) > *(right.getName())); }
bool operator==(Record& left, Record& right) { return *(left.getPesel()) == *(right.getPesel()) && *(left.getSurname()) == *(right.getSurname()) && *(left.getName()) == *(right.getName()); }