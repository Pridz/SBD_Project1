#include "IndexFileWriter.h"

IndexFileWriter::IndexFileWriter() { shr_ptr_out_indx = std::make_shared<std::fstream>(); }

std::fstream &IndexFileWriter::getFileStream() { return *shr_ptr_out_indx; }

void IndexFileWriter::openFileStreamW(char *path) { shr_ptr_out_indx->open(path, std::fstream::out); }

void IndexFileWriter::openFileStreamA(char *path) { shr_ptr_out_indx->open(path, std::fstream::app); }

void IndexFileWriter::closeFileStream() { shr_ptr_out_indx->close(); }

void IndexFileWriter::setPositionIndicator(int pos) { shr_ptr_out_indx->seekg(pos); }

int IndexFileWriter::getPositionIndicator() { return shr_ptr_out_indx->tellg(); }

void IndexFileWriter::writeInteger(int integer)
{
	if (shr_ptr_out_indx->is_open())
	{
		*shr_ptr_out_indx << integer;
	}
	assert(shr_ptr_out_indx->is_open());
}

void IndexFileWriter::putSpace()
{
	if (shr_ptr_out_indx->is_open())
	{
		shr_ptr_out_indx->put(' ');
	}
	assert(shr_ptr_out_indx->is_open());
}

void IndexFileWriter::putEndOfLine()
{
	if (shr_ptr_out_indx->is_open())
	{
		shr_ptr_out_indx->put('\n');
	}
	assert(shr_ptr_out_indx->is_open());
}

void IndexFileWriter::writeLine(int seriesIndex, int endPos)
{
	writeInteger(seriesIndex);
	putSpace();
	writeInteger(endPos);
	putEndOfLine();
	assert(shr_ptr_out_indx->is_open());
}

void IndexFileWriter::makeOrderInFile()
{
	putEndOfLine();
	putEndOfLine();
}

void IndexFileWriter::writeAmountOfSeries(int amountOfSeries)
{
	int pos = getPositionIndicator();
	setPositionIndicator(0);
	writeInteger(amountOfSeries);
	if (pos > 0)
	{
		setPositionIndicator(pos);
	}
}