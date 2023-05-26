#pragma once

#include "SquareBlack.h"
#include "SquareWhite.h"
#include "Piece.h"
#include "King.h"

#include <map>


class Board
{
	std::map<Position, Square*> _board;
	std::vector<Piece*> _pieces;
	std::map<Position, Piece*> _pieces_position;
	std::set<Position> _white_avaliable_moves;
	std::set<Position> _black_avaliable_moves;
	King* _black_king;
	King* _white_king;
	Piece* _chosen_piece;

	bool _en_passant;

	void initializeBoard();

	void hardColorReset() const;
	void softColorReset() const;

	void getAllAvaliableMoves();
	void updateAvailableMoves();

	void deleteBoard();

public:
	Board();
	~Board();

	void update();
	void updatePiecesPositions();
	void setPiecesVector(const std::vector<Piece*>& pieces);

	Square* operator[](const Position& key);

	std::map<Position, Piece*>& getAllPiecesPosition();
	void setPiecePosition(const Position& position, Piece* piece);

	void updateMoveMarkers();

	void checkForCheck();
	bool checkForCheck(team side);
	void predictCheck(const Position& position);

	void setBlackKing(King* king);
	void setWhiteKing(King* king);

	void getMove(const Position& position);
	void setAvailableMoves(Piece* piece);
	std::vector<Position> getMovesTowardsDestination(const Position& destination);
	void makeMove(const Position& position, int& taken_black, int& taken_white);

	bool enPassant(const Position& position);

	void draw(sf::RenderWindow* window) const;
};