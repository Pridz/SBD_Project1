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
	Bufor *bufors;
	Paths *paths;
	FileReader fileReader;
	FileWriter fileWriter;
	IndexFileReader indxFileReader;
	IndexFileWriter indxFileWriter;

	void writeBufor(int);

public:
	InOutManager(Bufor*, Paths *);

	void prepareFilesForSortingPhase();
	void closeFilesForSortingPhase();

	void openIndexFileForReading();
	void closeIndexFileForReading();

	// test
	int getPositionIndicatorFromFileWriter() { return fileWriter.getPositionIndicator(); }

	void readPage(int);
	void readToBufors(const int);
	int readAmountOfSeries();
	void writeSeriesPosition(int);
	void writeFromBuforsToFile(int);
	SeriesCharacteristics readSeriesCharacteristics(int);
	void writeAmountOfSeries(int);
};

struct Paths
{
	char* dataFile;
	char* seriesFile;
	char* seriesIndexFile;
	char* tape1File;
	char* tape1IndexFile;
	char* tape2File;
	char* tape2IndexFile;
};

#endif