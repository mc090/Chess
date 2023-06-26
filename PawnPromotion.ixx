module;
import Enum;
#include <string>
#include <SFML/Graphics.hpp>
export module PawnPromotion;


export class PawnPromotion
{
	sf::Texture _texture;
	sf::Sprite _sprite;

public:

	// Konstruktor
	explicit PawnPromotion(team turn);

	// Pokazuje menu wyboru figury na ekranie
	void draw(sf::RenderWindow* window) const;
};