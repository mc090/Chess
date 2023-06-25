module PawnPromotion;

PawnPromotion::PawnPromotion(const team turn)
{
	if (turn)
	{
		this->_texture.loadFromFile("Textures/BlackTransformation.png");
	}
	else
	{
		this->_texture.loadFromFile("Textures/WhiteTransformation.png");
	}
	_sprite.setTexture(_texture);
	_sprite.setPosition(150.f, 337.5);
}

void PawnPromotion::draw(sf::RenderWindow* window) const
{
	window->draw(_sprite);
}