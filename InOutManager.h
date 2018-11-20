#ifndef IN_OUT_MANAGER_H
#define IN_OUT_MANAGER_H

#include <memory>
#include <fstream>
#include "Bufor.h"
#include "FileReader.h"
#include "IndexFileReader.h"
#include "FileWriter.h"
#include "IndexFileWriter.h"

struct Paths;

class InOutManager
{	
	Paths *paths;
	FileReader fileReader;
	FileWriter fileWriter;
	IndexFileReader indxFileReader;
	IndexFileWriter indxFileWriter;


public:
	InOutManager();
	InOutManager(Paths *);

	void setPaths(Paths *paths);

	void prepareFilesForSortingPhase();
	void closeFilesForSortingPhase();

	void openIndexFileForReading();
	void closeIndexFileForReading();

	void clearIndexFile();

	// test
	int getPositionIndicatorFromFileWriter() { return fileWriter.getPositionIndicator(); }

	void readPage(Bufor* oneBufor);
	void readToBufors(Bufor* arrayOfBufors,const int lengthOfArrayOfBufors);
	int readAmountOfSeries();
	SeriesCharacteristics readSeriesCharacteristics(int ofIndex);
	void writeRecord(Record* oneRecord);
	void writeSeriesPosition(int indx);
	void writeBufor(Bufor *oneBufor);
	void writeFromBuforsToFile(Bufor *arrayOfBufors, int range);	
	void writeAmountOfSeries(int amountOfSeries);

	bool isEndOfFile();
};

struct Paths
{
	char* dataFile;
	char* seriesFile;
	char* seriesIndexFile;
	char* tape1File;
};

#endif