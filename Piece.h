#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum Pieces { //typ wyliczeniowy reprezentuj¹cy ró¿ne rodzaje bierek
	O = 0, //Brak

	P = 1, //Czarny pionek
	N, //Czarny skoczek
	B, //Czarny goniec
	R, //Czarna wie¿a
	Q, //Czarny hetman
	K, //Czarny król

	p = 11, //Bia³y pionek
	n, //Bia³y skoczek
	b, //Bia³y goniec
	r, //Bia³a wie¿a
	q, //Bia³y hetman
	k, //Bia³y król
};

enum Team { //typ wypliczeniowy definiuj¹cy przynale¿noœæ bierki do danego gracza
	white = 0, //Bia³y
	black, //Czarny
};

class Piece
{
protected:

	//zmienne odpowiedzialne za nadanie tekstury
	sf::Texture texture;
	sf::Sprite sprite;

	//zmienne przechowuj¹ce informacje o bierce
	Team side;
	double x;
	double y;

public:

	Piece(int x, int y, Team side) :x(x), y(y), side(side){};

	//metody dostêpu do zmiennych
	double GetPosition();

	//metody wp³ywaj¹ce na bierkê
	void SetPosition(int x, int y); //metoda zmieniajaca po³o¿enie bierki na szachownicy
	virtual void Move() = 0;

	//metody odpowidzialne za komunikacje z u¿ytkownikiem
	void Draw(sf::RenderWindow* window); //metoda odpowiadaj¹ca za narysowanie bierki w oknie aplikacji
};

