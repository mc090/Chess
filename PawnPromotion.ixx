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
	explicit PawnPromotion(team turn);
	void draw(sf::RenderWindow* window) const;
};