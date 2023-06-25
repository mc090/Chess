#pragma once

#include <fstream>
#include <semaphore>
#include <thread>
#include <iostream>
#include <vector>
#include <filesystem>
#include <string>
#include <regex>

#include <SFML/Graphics.hpp>

class SaveGame
{
	sf::Texture _loading_last_game_texture;
	sf::Sprite _loading_last_game_sprite;
	std::binary_semaphore _saving_game{0};
	std::filesystem::path _file_directory;
	std::filesystem::path _file_path;
	std::filesystem::path _last_game_path;
	int _game_number;
	void initializeLoadingButton();

	void saveMovesToFile(const std::vector<std::pair<std::string, std::string>>* moves_made) const;

public:

	SaveGame();
	void saveGameToFile(const std::vector<std::pair<std::string, std::string>>* moves_made);
	std::vector<std::pair<std::string, std::string>> loadGameFromFile();
	void save();
	void incGameNumber();
	void drawLoadingButton(sf::RenderWindow* window) const;
	bool isLastGamePathAvaliable() const;
};