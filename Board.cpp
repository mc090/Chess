#include "Board.h"


void Board::initializeBoard()
{
	for (char i = 'A'; i < 'I'; i++) {
		for (char j = '1'; j < '9'; j++) {
			std::string str;
			str.append(1, i).append(1, j);
			if (int(j + i) % 2) {
				_board[str] = new SquareBlack(str);
			}
			else {
				_board[str] = new SquareWhite(str);
			}
		}
	}
}


void Board::deletePointers()
{
	for (const auto& square : _board){
		delete square.second;
	}
	_board.clear();
	_pieces_position.clear();
}


void Board::setDefaultColors() const
{
	for (const auto& square : _board) {
		square.second->setDefaultColor();
	}
}


void Board::draw(sf::RenderWindow* window) const
{
	for (const auto& square : _board) {
		square.second->draw(window);
	}
}
