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

	// Ustala kolumnê oraz wiersz
	void set(const std::string& position);
	void set(char column, char row);

	// Ustala kolumnê
	void setColumn(const char& column);

	// Ustala wiersz
	void setRow(const char& row);

	// Zwraca ³añcuch znaków reprezetuj¹cy pozycjê
	std::string get() const;

	// Zwraca znak reprezentujacy kolumnê
	char getColumn() const;

	// Zwraca znak reprezentujacy wiersz
	char getRow() const;
};

