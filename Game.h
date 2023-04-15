#pragma once

#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "SquareBlack.h"
#include "SquareWhite.h"

#include <iostream>
#include <vector>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
Klasa odpowiadaj�ca za obs�ug� gry
*/
class Game
{
	//zmienne
	sf::RenderWindow* window; //okno na kt�rym wy�wietla si� aplikacja
	sf::VideoMode videoMode; //definiuje wymiary okna
	sf::Event event; //odpowiada za komunikacj� z u�ytkownikiem i odbieranie od niego zdarze�
	sf::Vector2f mousePosition; //lokalizacja myszki wzgledem okna aplikacji

	//obiekty
	std::vector<Piece*> pieces;
	std::map<double, Square*> board;
	/*std::map<double, Piece*> piecesPosition;*/

	//metody prywatne
	void InitializeWindow(); //metoda tworz�ca okno aplikacji
	void InitializeBoard();
	void InitializePieces(); //metoda tworz�ca i zapisuj�ca do wektora pionki

	void ClearBoard();
	/*void UpdatePositions();*/

public:
	Game() :window(nullptr) {
		this->InitializeWindow();
		this->InitializeBoard();
		this->InitializePieces();
		/*this->UpdatePositions();*/
	};
	~Game() {
		delete this->window;
	};

	//metody dost�powe
	const bool GetWindowIsOpen() const; //zwraca informacj� o stanie otwarcia okna aplikacji

	//metody odpowidzialne za komunikacje z u�ytkownikiem
	void PollEvents(); //metoda umo�liwiaj�ca dzia�anie zdarze�
	void Update(); //metoda aktualizuj�ca aktualny wygl�d okna aplikacji
	void UpdateMousePositions(); //metoda aktualizuj�ca dane o po�o�eniu myszy wzgl�dem okna
	void Render(); //metoda wy�wietlaj�ca aktualny stan gry
};