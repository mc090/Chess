#pragma once

#include "SquareBlack.h"
#include "SquareWhite.h"
#include "Piece.h"

#include <map>


class Board
{
	std::map<std::string, Square*> _board;
	std::map<std::string, Piece*> _pieces_position;

	void initializeBoard();

	void deletePointers();

public:
	Board(){ initializeBoard();}
	~Board() { deletePointers(); }

	Square* operator[](const std::string& key) {
		return _board[key];
	}
	std::map<std::string, Piece*>& operator()() {
		return _pieces_position;
	}

	void setDefaultColors() const;
	void draw(sf::RenderWindow* window) const;
};

