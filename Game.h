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
#include "Clock.h"
#include "SaveGame.h"
import PawnPromotion;
import VictoryScreen;
#include <thread>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <ranges>
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
	Clock* _black_clock;
	Clock* _white_clock;
	bool _is_game_started;
	std::vector<std::pair<std::string, std::string>>* _moves_made;
	SaveGame _file_manager;

	// Tworzy okno
	void initializeWindow();

	// Tworzy bierki i zapisuje je w _pieces
	void initializePieces();

	// Tworzy w¹tek zapisuj¹cy stan rozgrywki do pliku
	void initializeGameSaving();

	// Usuwa wszyskie bierki
	void deletePieces();

	// Dla ka¿dej bierki ustala wektor ruchów bierki uwzglêdniaj¹c informacjê czy,
	// po ich wykonaniu król koloru bierki nie bêdzie atakowany
	void predictCheck();

	// Aktualizuje wektor dostêpnych ruchów dla ka¿dej bierki
	void updateAvailableMoves();

	// Zwraca pozycjê myszki, gdy zosta³o wykonane klikniêcie
	Position getClickedPosition() const;

	// Wykonuje promocjê piona
	void promotePawn();

	// Zwraca informacjê o tym gra zakonczy³a siê przez brak czasu,
	// a jeœli tak to który zawodnik wygra³
	gameResult isGameFinishedByTime();

	// Zapisuje ruch do pliku
	void saveMove(const Position& old_position, const Position& new_position);

	// Zapisuje stan zegarów do pliku
	void saveTime();

	// Tworzy nowy plik do zapisu stanu gry
	void resetGameSaving();

public:

	// Konstruktor
	Game();

	// Destruktor
	~Game();

	// Zwraca true, gry okno jest otwarte
	bool getWindowIsOpen() const;

	// 
	void pollEvents();

	// Aktualizje informacje o grze
	void update();

	// Aktualizuje pozycjê myszki
	void updateMousePositions();

	// Wyœwietla obiekty na ekranie
	void render() const;
};