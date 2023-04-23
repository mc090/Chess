#include "Position.h"

Position::Position(const std::string& position) :_column(position[0]), _row(position[1])
{
}

Position::Position(const char column, const char row) :_column(column), _row(row)
{
}

void Position::set(const std::string& position)
{
	_column = position[0];
	_row = position[1];
}

void Position::set(const char column,const char row)
{
	_column = column;
	_row = row;
}

void Position::setColumn(const char& column)
{
	_column = column;
}

void Position::setRow(const char& row)
{
	_row = row;
}

std::string Position::get() const
{
	std::string position;
	position += _column;
	position += _row;
	return position;
}

char Position::getColumn() const
{
	return _column;
}

char Position::getRow() const
{
	return _row;
}
