#ifndef INDEX_FILE_WRITER_H
#define INDEX_FILE_WRITER_H

#include <memory>
#include <fstream>
#include <assert.h>

class IndexFileWriter
{
	std::shared_ptr<std::fstream> shr_ptr_out_indx;

	void writeInteger(int);	
	void putSpace();	
	void putEndOfLine();

	void setPositionIndicator(int);
	void setPositionIndicatorToEndOfStream();
	int getPositionIndicator();

public:
	IndexFileWriter();

	std::fstream &getFileStream();
	void openFileStreamW(char *);
	void openFileStreamA(char *);
	void closeFileStream();
	void writeLine(int, int);	
	void writeAmountOfSeries(int);
};

#endif // INDEX_FILE_WRITER_H