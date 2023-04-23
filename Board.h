#pragma once

#include "SquareBlack.h"
#include "SquareWhite.h"
#include "Piece.h"

#include <map>


class Board
{
	std::map<Position, Square*> _board;
	std::map<Position, Piece*> _pieces_position;
	Piece* _chosen_piece;

	bool _en_passant;

	void initializeBoard();

	void deleteBoard();

public:
	Board();
	~Board();

	Square* operator[](const Position& key);

	std::map<Position, Piece*>& getAllPiecesPosition();
	void setPiecePosition(const Position& position, Piece* piece);

	void hardColorReset() const;
	void softColorReset() const;

	void getMove(const Position& position);
	void showAvailableMoves(const Position& piece_position);
	std::vector<Position> getAvaliableMoves(const Position& destination);
	void makeMove(const Position& position, int& taken_black, int& taken_white);

	bool enPassant(const Position& position);

	void draw(sf::RenderWindow* window) const;
};