#pragma once

#include "SquareBlack.h"
#include "SquareWhite.h"
#include "Piece.h"

#include <map>


class Board
{
	std::map<std::string, Square*> _board;
	std::map<std::string, Piece*> _pieces_position;
	Piece* _chosen_piece;

	void initializeBoard();

	void deleteBoard();

public:
	Board();
	~Board();

	Square* operator[](const std::string& key);

	std::map<std::string, Piece*>& getAllPiecesPosition();
	void setPiecePosition(const std::string& position, Piece* piece);

	void setDefaultColors() const;

	void getMove(const std::string& position);
	void showAvailableMoves(const std::string& piece_position);
	std::vector<std::string> getAvailableMoves(const std::string& piece_position);
	std::vector<std::string> getMoves(const std::string& destination);
	void makeMove(const std::string& position, int& taken_black, int& taken_white);

	void draw(sf::RenderWindow* window) const;
};