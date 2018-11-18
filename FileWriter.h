#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include "Bufor.h"
#include <fstream>
#include <memory>

class FileWriter
{	
	std::shared_ptr<std::fstream> shr_ptr_out;

public:
	FileWriter();
		
	std::fstream &getFileStream();

	void openFileForWritting(char*);

	void writePesel(Pesel*);	
	void writeName(std::string*);	
	void writeRecord(Record*);	
	
	void writeRecord(int);
	void writeBufor(int);
	void writeBufor(Bufor*);
	void writeBufor(Bufor*, std::fstream &);
	void writeSeriesData();
	void writeSeriesData(std::fstream&, std::fstream&);
	void writeNumberOfSeriesToIndexFile(std::fstream&);
	void writeLastBufor();
	void writeLastBufor(std::fstream &);
};

#endif // FILE_WRITER_H