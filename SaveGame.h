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
	bool _is_game_open;

	// Tworzy przycisk odczytu ostatniej zapisanej gry
	void initializeLoadingButton();

	// Zapisuje ruchy do pliku
	void saveMovesToFile(const std::vector<std::pair<std::string, std::string>>* moves_made) const;

public:

	// Konstruktor
	SaveGame();

	// Zapisuje stan gry do pliku
	void saveGameToFile(const std::vector<std::pair<std::string, std::string>>* moves_made);

	// Zwraca wektor reprezentuj¹cego stan wczytanej gry
	std::vector<std::pair<std::string, std::string>> loadGameFromFile();

	// Umo¿liwia zapis do pliku
	void save();

	// Zwiêksza nazwê pliku o jeden
	void incGameNumber();

	// Pokazuje przycisk odczytu ostatniej zapisanej gry na ekranie
	void drawLoadingButton(sf::RenderWindow* window) const;

	// Zwraca true, gdy istnieje plik z zapisan¹ ostatni¹ rozgrywk¹
	bool isLastGamePathAvaliable() const;

	void closeGame();
};