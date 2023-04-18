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
Klasa odpowiadaj¹ca za obs³ugê gry
*/
class Game
{
	//zmienne
	sf::RenderWindow* _window; //okno na którym wyœwietla siê aplikacja
	sf::VideoMode _video_mode; //definiuje wymiary okna
	sf::Event _event; //odpowiada za komunikacjê z u¿ytkownikiem i odbieranie od niego zdarzeñ
	sf::Vector2f _mouse_position; //lokalizacja myszki wzgledem okna aplikacji

	//obiekty
	std::vector<Piece*> _pieces;
	Board _board;

	//metody prywatne
	void initializeWindow(); //metoda tworz¹ca okno aplikacji
	void initializePieces(); //metoda tworz¹ca i zapisuj¹ca do wektora pionki
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

	//metody dostêpowe
	bool getWindowIsOpen() const; //zwraca informacjê o stanie otwarcia okna aplikacji

	//metody odpowidzialne za komunikacje z u¿ytkownikiem
	void pollEvents(); //metoda umo¿liwiaj¹ca dzia³anie zdarzeñ
	void update(); //metoda aktualizuj¹ca aktualny wygl¹d okna aplikacji
	void updateMousePositions(); //metoda aktualizuj¹ca dane o po³o¿eniu myszy wzglêdem okna
	void render() const; //metoda wyœwietlaj¹ca aktualny stan gry
};