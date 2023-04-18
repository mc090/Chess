#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

enum team { //typ wyliczeniowy definiuj¹cy przynale¿noœæ bierki do danego gracza
	white = 0, //Bia³y
	black, //Czarny
};

/*
Klasa wirtualna 
*/
class Piece
{
protected:

	//zmienne odpowiedzialne za nadanie tekstury
	sf::Texture _texture;
	sf::Sprite _sprite;

	//zmienne przechowuj¹ce informacje o bierce
	team _side;
	std::string _position;

public:
	//konstruktor inicjalizuj¹cy zmienne domyœlne
	Piece(std::string position, const team side) :_side(side), _position(std::move(position)){}
	virtual ~Piece() = default;

	//metody dostêpu do zmiennych
	std::string getPosition();

	//metody wp³ywaj¹ce na bierkê
	void setPosition(const std::string& position); //metoda zmieniajaca po³o¿enie bierki na szachownicy
	virtual void move() = 0;

	//metody odpowidzialne za komunikacje z u¿ytkownikiem
	void draw(sf::RenderWindow* window) const; //metoda odpowiadaj¹ca za narysowanie bierki w oknie aplikacji
};

