#include "Game.h"

void Game::InitializeWindow()
{
	this->videoMode.width = 1200;
	this->videoMode.height = 800;
	this->window = new sf::RenderWindow(sf::VideoMode(this->videoMode), "Chess", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::InitializePieces()
{
	pieces.push_back(new Rook(0, 0, black));
	pieces.push_back(new Knight(1, 0, black));
	pieces.push_back(new Bishop(2, 0, black));
	pieces.push_back(new Queen(3, 0, black));
	pieces.push_back(new King(4, 0, black));
	pieces.push_back(new Bishop(5, 0, black));
	pieces.push_back(new Knight(6, 0, black));
	pieces.push_back(new Rook(7, 0, black));
	for (int i = 0; i < 8; i++) {
		pieces.push_back(new Pawn(i, 1, black));
	}

	pieces.push_back(new Rook(0, 7, white));
	pieces.push_back(new Knight(1, 7, white));
	pieces.push_back(new Bishop(2, 7, white));
	pieces.push_back(new Queen(3, 7, white));
	pieces.push_back(new King(4, 7, white));
	pieces.push_back(new Bishop(5, 7, white));
	pieces.push_back(new Knight(6, 7, white));
	pieces.push_back(new Rook(7, 7, white));
	for (int i = 0; i < 8; i++) {
		pieces.push_back(new Pawn(i, 6, white));
	}
}

void Game::ClearBoard()
{
	for (auto& square : board) {
		square.second->Default();
	}
}

void Game::InitializeBoard()
{
	for (double i = 0; i < 8; i++) {
		for (double j = 0; j < 8; j++) {
			if (int(j + i) % 2) {
				board[i + j / 10] = new SquareBlack(i, j);
			}
			else {
				board[i + j / 10] = new SquareWhite(i, j);
			}
		}
	}
}

//void Game::UpdatePositions()
//{
//	piecesPosition.clear();
//	for (double i = 0; i < 32; i++)
//		this->piecesPosition[pieces[i]->GetPosition()] = pieces[i];
//}



const bool Game::GetWindowIsOpen() const
{
	return this->window->isOpen();
}



void Game::PollEvents()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {

		case sf::Event::Closed: //jeœli zostanie wciœniety przycisk zamkniecia okna (w prawym górnym rogu) - zamknie sie okno
			this->window->close();
			break;

		case sf::Event::KeyPressed: //jeœli zostanie wciœniety przycisk "Escape" - zamknie siê okno
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		case sf::Event::MouseButtonPressed: //jeœli zostanie wciœniêty lewy przycisk myszy bierka na której jest kursor wykona .Move()
			if (this->event.mouseButton.button == sf::Mouse::Left)
				if (mousePosition.x >= 0 and mousePosition.x < 800 and mousePosition.y >= 0 and mousePosition.y < 800) {
					double position = int(mousePosition.x / 100) + (double)(int(mousePosition.y / 100)) / 10;
					/*if (piecesPosition.count(position)) {
						piecesPosition[position]->Move();
						UpdatePositions();
					}*/
					for (auto* piece : pieces) {
						if (position == piece->GetPosition()) {
							ClearBoard();
							board[position]->Position();
							piece->Move();
							board[piece->GetPosition()]->Position();
						}
					}
				}
			break;
		}
	}
}

void Game::UpdateMousePositions()
{
	this->mousePosition = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}



void Game::Update()
{
	this->PollEvents();
	this->UpdateMousePositions();
}

void Game::Render()
{
	this->window->clear(sf::Color(49, 46, 43)); //wyczyszczenie starej klatki oraz nadanie koloru t³a

	for (auto& square : board) {
		square.second->Draw(window);
	}
	for (auto* piece : pieces) {
		piece->Draw(window);
	}

	this->window->display();
}
