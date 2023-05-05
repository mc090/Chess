#include "MoveMarker.h"

MoveMarker::MoveMarker(const int x, const int y, const float radius)
{
	if (radius == 20.f)
	{
		_sprite.setPosition(x * 100.f + 30.f, y * 100.f + 30.f);
	}
	else
	{
		_sprite.setPosition(x * 100.f, y * 100.f);
	}
	_sprite.setRadius(radius);
	_sprite.setFillColor(sf::Color(78, 199, 161));
}

void MoveMarker::draw(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}