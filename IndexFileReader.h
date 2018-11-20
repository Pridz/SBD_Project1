#ifndef INDEX_FILE_READER_H
#define INDEX_FILE_READER_H

#include <fstream>
#include <memory>
#include <assert.h>
#include "FileReadingOperations.h"

struct SeriesCharacteristics;

class IndexFileReader : public FileReadingOperations
{
	int amount;
	std::shared_ptr<std::fstream> shr_ptr_in_indx;

	int readInteger();

	void missLine();
	void missLines(int);
	void missSpace();
		
	bool isSuchSeries(int);
	void setPositionIndicatorOnTheSeriesLine(int);

	void setPositionIndicator(int);
	int findPositionOfLastNumber();

	int getPositionIndicator();
	SeriesCharacteristics readSeriesLine();
	void openFileStream(char*);
public:
	IndexFileReader();

	std::fstream &getFileStream();

	void prepareForReading(char*);
	void closeFileStream();

	int readAmountOfSeries();
	SeriesCharacteristics getTheSeriesCharacteristics(int);
};

struct SeriesCharacteristics
{
	int index;
	int actualPosition;
	int endingPosition;

	SeriesCharacteristics() : index(0), endingPosition(0), actualPosition(0) {}
	SeriesCharacteristics& operator=(SeriesCharacteristics &other)
	{
		index = other.index;
		actualPosition = other.actualPosition;
		endingPosition = other.endingPosition;
		return *this;
	}
};

#endif