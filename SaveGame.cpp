#include "SaveGame.h"

void SaveGame::initializeLoadingButton()
{
	_loading_last_game_texture.loadFromFile("Textures/LoadingButton.png");
	_loading_last_game_sprite.setTexture(_loading_last_game_texture);
	_loading_last_game_sprite.setPosition(875.f, 700.f);
}

void SaveGame::saveMovesToFile(const std::vector<std::pair<std::string, std::string>>* moves_made) const
{
	std::ofstream file_write(_file_path, std::ios::out);
	for (auto move : *moves_made) {
		file_write << move.first << " " << move.second << "\n";
	}
	file_write.close();
}

SaveGame::SaveGame() :_file_directory(std::filesystem::current_path() += "\\GameSaves\\"), _game_number(1)
{
	initializeLoadingButton();
	if (!std::filesystem::exists(_file_directory))
	{
		std::filesystem::create_directory(_file_directory);
	}
	do
	{
		_file_path = _file_directory;
		_file_path += "Gra" + std::to_string(_game_number) + ".txt";
		if (std::filesystem::exists(_file_path))
		{
			_game_number++;
		}
	} while (std::filesystem::exists(_file_path));
	_last_game_path = _file_directory;
	_last_game_path += "Gra" + std::to_string(_game_number - 1) + ".txt";
}

void SaveGame::saveGameToFile(const std::vector<std::pair<std::string, std::string>>* moves_made)
{
	while (true)
	{
		_saving_game.acquire();
		saveMovesToFile(moves_made);
	}
}

std::vector<std::pair<std::string, std::string>> SaveGame::loadGameFromFile()
{
	_file_path = _last_game_path;
	std::vector<std::pair<std::string, std::string>> moves;
	std::ifstream file_input(_last_game_path);
	std::regex regex("[A-H][1-8]|[0-9]{1,3}");
	std::string line;
	while (std::getline(file_input, line)) {
		auto temp = std::sregex_iterator(line.begin(), line.end(), regex);
		moves.push_back({ temp->str(), (++temp)->str() });
	}
	file_input.close();
	return moves;
}

void SaveGame::save()
{
	_saving_game.release();
}

void SaveGame::incGameNumber()
{
	_game_number++;
	_file_path = _file_directory;
	_file_path += "Gra" + std::to_string(_game_number) + ".txt";
}

void SaveGame::drawLoadingButton(sf::RenderWindow* window) const
{
	window->draw(_loading_last_game_sprite);
}

bool SaveGame::isLastGamePathAvaliable() const
{
	return std::filesystem::exists(_last_game_path) ? true : false;
}
