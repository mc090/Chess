#pragma once

#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "SquareBlack.h"
#include "SquareWhite.h"
#include "Board.h"
#include "PawnPromotion.h"
#include "VictoryScreen.h"

#include <iostream>
#include <vector>
#include <set>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Game
{
	sf::RenderWindow* _window;
	sf::VideoMode _video_mode;
	sf::Event _event;
	sf::Vector2f _mouse_position;
	std::vector<Piece*> _pieces;
	Board _board;
	int _taken_black;
	int _taken_white;
	team _turn;
	Position _selected_piece_position;
	PawnPromotion* _pawn_promotion;
	Piece* _chosen_piece;
	bool _is_pawn_promotion;
	gameResult _game_result;
	VictoryScreen* _victory_screen;

	void initializeWindow();
	void initializePieces();
	void deletePieces();
	void predictCheck();
	void updateAvailableMoves();
	Position getClickedPosition() const;
	void promotePawn();

public:
	Game();
	~Game();

	bool getWindowIsOpen() const;

	void pollEvents();
	void update();
	void updateMousePositions();
	void render() const;
};