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
Klasa odpowiadaj¹ca za obs³ugê gry
*/
class Game
{
	//zmienne
	sf::RenderWindow* window; //okno na którym wyœwietla siê aplikacja
	sf::VideoMode videoMode; //definiuje wymiary okna
	sf::Event event; //odpowiada za komunikacjê z u¿ytkownikiem i odbieranie od niego zdarzeñ
	sf::Vector2f mousePosition; //lokalizacja myszki wzgledem okna aplikacji

	//obiekty
	std::vector<Piece*> pieces;
	std::map<double, Square*> board;
	/*std::map<double, Piece*> piecesPosition;*/

	//metody prywatne
	void InitializeWindow(); //metoda tworz¹ca okno aplikacji
	void InitializeBoard();
	void InitializePieces(); //metoda tworz¹ca i zapisuj¹ca do wektora pionki

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

	//metody dostêpowe
	const bool GetWindowIsOpen() const; //zwraca informacjê o stanie otwarcia okna aplikacji

	//metody odpowidzialne za komunikacje z u¿ytkownikiem
	void PollEvents(); //metoda umo¿liwiaj¹ca dzia³anie zdarzeñ
	void Update(); //metoda aktualizuj¹ca aktualny wygl¹d okna aplikacji
	void UpdateMousePositions(); //metoda aktualizuj¹ca dane o po³o¿eniu myszy wzglêdem okna
	void Render(); //metoda wyœwietlaj¹ca aktualny stan gry
};