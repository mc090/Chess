#pragma once

#include <string>

class Position
{
	char _column;
	char _row;

public:

	// Konstruktor
	explicit Position(const std::string& position);
	Position(char column, char row);

	friend bool operator<(const Position& l, const Position& r){ return l.get() < r.get(); }

	// Ustala kolumn� oraz wiersz
	void set(const std::string& position);
	void set(char column, char row);

	// Ustala kolumn�
	void setColumn(const char& column);

	// Ustala wiersz
	void setRow(const char& row);

	// Zwraca �a�cuch znak�w reprezetuj�cy pozycj�
	std::string get() const;

	// Zwraca znak reprezentujacy kolumn�
	char getColumn() const;

	// Zwraca znak reprezentujacy wiersz
	char getRow() const;
};

