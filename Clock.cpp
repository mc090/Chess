#include "Clock.h"

Clock::Clock(const sf::Vector2f position) : _is_clock_started(false), _time_when_stopped(900)
{
	_font.loadFromFile("Fonts/RobotoMono-VariableFont_wght.ttf");
	_text.setFont(_font);
	_text.setCharacterSize(56);
	_text.setPosition(position);
}

void Clock::start()
{
	_clock.restart();
	_is_clock_started = true;
}

void Clock::pause()
{
	_time_when_stopped -= (int)_clock.getElapsedTime().asSeconds();
	_is_clock_started = false;
}

void Clock::restart()
{
	_time_when_stopped = 900;
	_is_clock_started = false;
	_clock.restart();
}

int Clock::getRemainigTime() const
{
	return _is_clock_started ? _time_when_stopped - (int)_clock.getElapsedTime().asSeconds() : _time_when_stopped;
}

void Clock::draw(sf::RenderWindow* window)
{
	const int time = _time_when_stopped - _is_clock_started * (int)_clock.getElapsedTime().asSeconds();
	std::string zero = time % 60 < 10 ? "0" : "";
	_text.setString(std::to_string(time / 60) + ":" + zero + std::to_string(time % 60));
	window->draw(_text);
}
