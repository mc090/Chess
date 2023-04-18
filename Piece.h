#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

enum team { //typ wyliczeniowy definiujący przynależność bierki do danego gracza
	white = 0, //Biały
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

	//zmienne przechowujące informacje o bierce
	team _side;
	std::string _position;

public:
	//konstruktor inicjalizujący zmienne domyślne
	Piece(std::string position, const team side) :_side(side), _position(std::move(position)){}
	virtual ~Piece() = default;

	//metody dostępu do zmiennych
	std::string getPosition();

	//metody wpływające na bierkę
	void setPosition(const std::string& position); //metoda zmieniajaca położenie bierki na szachownicy
	virtual void move() = 0;

	//metody odpowidzialne za komunikacje z użytkownikiem
	void draw(sf::RenderWindow* window) const; //metoda odpowiadająca za narysowanie bierki w oknie aplikacji
};

