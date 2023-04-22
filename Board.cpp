#include "Board.h"
#include "Pawn.h"


void Board::initializeBoard()
{
	for (char column_char = 'A'; column_char < 'I'; column_char++) {
		for (char row_char = '1'; row_char < '9'; row_char++) {
			std::string position;
			position += column_char;
			position += row_char;
			if (int(column_char + row_char) % 2) {
				_board[position] = new SquareBlack(position);
			}
			else {
				_board[position] = new SquareWhite(position);
			}
		}
	}
}



void Board::deleteBoard()
{
	for (const auto& square : _board) {
		delete square.second;
	}
	_board.clear();
	_pieces_position.clear();
}



Board::Board() : _chosen_piece(nullptr)
{
	initializeBoard();
}

Board::~Board()
{
	deleteBoard();
}



Square* Board::operator[](const std::string& key)
{
	return _board[key];
}



std::map<std::string, Piece*>& Board::getAllPiecesPosition()
{
	return _pieces_position;
}

void Board::setPiecePosition(const std::string& position, Piece* piece)
{
	_pieces_position[position] = piece;
}



void Board::setDefaultColors() const
{
	for (const auto& square : _board) {
		square.second->setDefaultColor();
	}
}



void Board::getMove(const std::string& position)
{
	setDefaultColors();
	if (_pieces_position[position] and !_pieces_position[position]->isToDelete()) {
		_chosen_piece = _pieces_position[position];
		showAvailableMoves(position);
	}
}

void Board::showAvailableMoves(const std::string& piece_position)
{
	const std::vector<std::string> available_moves = getAvailableMoves(piece_position);
	for (const auto& position : available_moves)
	{
		_board[position]->setPotenitalMoveColor();
	}
}

std::vector<std::string> Board::getAvailableMoves(const std::string& piece_position)
{
	std::vector<std::string> positions;
	const std::vector<std::string> potential_destinations = _chosen_piece->getPotentialDestinations();
	for (const auto& potential_destination : potential_destinations)
	{
		const std::vector<std::string> checked_positions = getMoves(potential_destination);
		for (const auto& position : checked_positions)
		{
			positions.push_back(position);
		}
	}
	return positions;
}

std::vector<std::string> Board::getMoves(const std::string& destination)
{
	std::vector<std::string> positions;
	const std::string piece_position = _chosen_piece->getPosition();
	team piece_side = _chosen_piece->getSide();
	const std::vector<std::string> path = _chosen_piece->getPathTo(piece_position, destination); //D3 D4
	if (!dynamic_cast<Pawn*>(_chosen_piece))
	{
		for (auto& position : path)
		{
			if (_pieces_position[position] and !_pieces_position[position]->isToDelete())
			{
				if (_pieces_position[position]->getSide() != piece_side)
				{
					positions.push_back(position);
				}
				return positions;
			}
			else
			{
				positions.push_back(position);
			}
		}
	}
	else
	{
		for (auto& position : path)
		{
			if (position[0] == piece_position[0] + 1 or position[0] == piece_position[0] - 1)
			{
				if (_pieces_position[position] and !_pieces_position[position]->isToDelete() and _pieces_position[position]->getSide() != piece_side)
				{
					positions.push_back(position);
				}
			}
			else
			{
				if (_pieces_position[position] and !_pieces_position[position]->isToDelete())
				{
					return positions;
				}
				positions.push_back(position);
			}
		}
	}
	return positions;
}

void Board::makeMove(const std::string& position, int& taken_black, int& taken_white)
{
	setDefaultColors();
	const std::string old_position = _chosen_piece->getPosition();
	_board[old_position]->setPositionColor();
	if(_pieces_position[position] and !_pieces_position[position]->isToDelete())
	{
		_pieces_position[position]->setToDelete(taken_black, taken_white);
	}
	if(dynamic_cast<Pawn*>(_chosen_piece))
	{
		Pawn* pawn = dynamic_cast<Pawn*>(_chosen_piece);
		pawn->setIsStartingPosition(false);
	}
	_chosen_piece->setPosition(position);
	_board[position]->setPositionColor();
}


void Board::draw(sf::RenderWindow* window) const
{
	for (const auto& square : _board) {
		square.second->draw(window);
	}
}