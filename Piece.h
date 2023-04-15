#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum Pieces { //typ wyliczeniowy reprezentuj�cy r�ne rodzaje bierek
	O = 0, //Brak

	P = 1, //Czarny pionek
	N, //Czarny skoczek
	B, //Czarny goniec
	R, //Czarna wie�a
	Q, //Czarny hetman
	K, //Czarny kr�l

	p = 11, //Bia�y pionek
	n, //Bia�y skoczek
	b, //Bia�y goniec
	r, //Bia�a wie�a
	q, //Bia�y hetman
	k, //Bia�y kr�l
};

enum Team { //typ wypliczeniowy definiuj�cy przynale�no�� bierki do danego gracza
	white = 0, //Bia�y
	black, //Czarny
};

class Piece
{
protected:

	//zmienne odpowiedzialne za nadanie tekstury
	sf::Texture texture;
	sf::Sprite sprite;

	//zmienne przechowuj�ce informacje o bierce
	Team side;
	double x;
	double y;

public:

	Piece(int x, int y, Team side) :x(x), y(y), side(side){};

	//metody dost�pu do zmiennych
	double GetPosition();

	//metody wp�ywaj�ce na bierk�
	void SetPosition(int x, int y); //metoda zmieniajaca po�o�enie bierki na szachownicy
	virtual void Move() = 0;

	//metody odpowidzialne za komunikacje z u�ytkownikiem
	void Draw(sf::RenderWindow* window); //metoda odpowiadaj�ca za narysowanie bierki w oknie aplikacji
};

