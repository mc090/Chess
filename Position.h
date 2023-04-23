#pragma once

#include <string>

class Position
{
	char _column;
	char _row;

public:
	explicit Position(const std::string& position);
	Position(char column, char row);

	friend bool operator<(const Position& l, const Position& r){ return l.get() < r.get(); }

	void set(const std::string& position);
	void set(char column, char row);
	void setColumn(const char& column);
	void setRow(const char& row);

	std::string get() const;
	char getColumn() const;
	char getRow() const;
};

