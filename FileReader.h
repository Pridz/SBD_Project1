#ifndef FILE_READER_H
#define FILE_READER_H

#include <memory>
#include <fstream>
#include "Bufor.h"
#include "FileReadingOperations.h"

class FileReader : public FileReadingOperations
{	
	std::shared_ptr<std::fstream> shr_ptr_in;
		
public:
	FileReader();
		
	std::fstream &getInputFileStream();

	void openFileStream(char*);
	void closeFileStream();

	std::string readText();
	Pesel readPesel();	
	Record readRecord();
	//void readPage(std::fstream *stream, int);
	void readToBufors(std::fstream *, const int);

	void readPageOfOneSeries(std::fstream *stream, int);

	void readToAllButLastBuforsPartOfSeries();
	void readToAllButLastBuforsPartOfSeries(std::fstream&);
	void readSeries();
	void readPartOfSeries(std::fstream*, int);
	void readAllSeries();
	int readBeginningPositionOfSeries(std::fstream *, int seriesNumber);
	int readEndiningPositionOfSeries(std::fstream *, int seriesNumber);
	int readNumberOfSeries(std::fstream&);
};

#endif //FILE_READER_H