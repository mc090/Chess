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

/*
Klasa odpowiadaj�ca za obs�ug� gry
*/
class Game
{
	//zmienne
	sf::RenderWindow* _window; //okno na kt�rym wy�wietla si� aplikacja
	sf::VideoMode _video_mode; //definiuje wymiary okna
	sf::Event _event; //odpowiada za komunikacj� z u�ytkownikiem i odbieranie od niego zdarze�
	sf::Vector2f _mouse_position; //lokalizacja myszki wzgledem okna aplikacji

	//obiekty
	std::vector<Piece*> _pieces;
	Board _board;

	//metody prywatne
	void initializeWindow(); //metoda tworz�ca okno aplikacji
	void initializePieces(); //metoda tworz�ca i zapisuj�ca do wektora pionki
	void deletePieces();

	void updatePiecesPositions();

public:
	Game() :_window(nullptr), _event(){
		initializeWindow();
		initializePieces();
		updatePiecesPositions();
	}
	~Game() {
		delete _window;
		deletePieces();
	}

	//metody dost�powe
	bool getWindowIsOpen() const; //zwraca informacj� o stanie otwarcia okna aplikacji

	//metody odpowidzialne za komunikacje z u�ytkownikiem
	void pollEvents(); //metoda umo�liwiaj�ca dzia�anie zdarze�
	void update(); //metoda aktualizuj�ca aktualny wygl�d okna aplikacji
	void updateMousePositions(); //metoda aktualizuj�ca dane o po�o�eniu myszy wzgl�dem okna
	void render() const; //metoda wy�wietlaj�ca aktualny stan gry
};