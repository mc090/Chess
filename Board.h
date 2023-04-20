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

	void deleteBoard();

public:
	Board();
	~Board();

	Square* operator[](const std::string& key);

	std::map<std::string, Piece*>& getAllPiecesPosition();
	void setPiecePosition(const std::string& position, Piece* piece);

	void setDefaultColors() const;

	void move(const std::string& position);

	std::vector<std::string> availableSquares(const std::string& piece_position);
	std::vector<std::string> isMovePossible(const std::string& destination, Piece* piece);
	void showAvailableMoves(const std::string& piece_position);

	void draw(sf::RenderWindow* window) const;
};

