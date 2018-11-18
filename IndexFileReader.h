#ifndef INDEX_FILE_READER_H
#define INDEX_FILE_READER_H

#include <fstream>
#include <memory>
#include <assert.h>

struct SeriesCharacteristics;

class IndexFileReader
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
	int getPositionIndicator();
	SeriesCharacteristics readSeriesLine();
public:
	IndexFileReader();

	std::fstream &getFileStream();

	void openFileStream(char*);
	void prepareForReading(char*);
	void closeFileStream();

	int readAmountOfSeries();
	SeriesCharacteristics getTheSeriesCharacteristics(int);
};

struct SeriesCharacteristics
{
	int index;
	int endingPosition;

	SeriesCharacteristics() : index(0), endingPosition(0) {}
	SeriesCharacteristics& operator=(SeriesCharacteristics &other)
	{
		index = other.index;
		endingPosition = other.endingPosition;
		return *this;
	}
};

#endif