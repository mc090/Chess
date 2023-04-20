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

#include <iostream>
#include <vector>


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

	void initializeWindow();
	void initializePieces();
	void deletePieces();

	void updatePiecesPositions();
	std::string getClickedPiecePosition() const;

public:
	Game();
	~Game();

	bool getWindowIsOpen() const;

	void pollEvents();
	void update();
	void updateMousePositions();
	void render() const;
};