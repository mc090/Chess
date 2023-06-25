module;
import Enum;
#include <SFML/Graphics.hpp>
export module VictoryScreen;

export class VictoryScreen
{
	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	explicit VictoryScreen(const gameResult& game_result);
	void draw(sf::RenderWindow* window) const;
};