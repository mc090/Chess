#pragma once

#include "SquareBlack.h"
#include "SquareWhite.h"
#include "Piece.h"
#include "King.h"
#include "Clock.h"

#include <map>


class Board
{
	std::map<Position, Square*> _board;
	std::vector<Piece*> _pieces;
	std::map<Position, Piece*> _pieces_position;
	std::set<Position> _white_avaliable_moves;
	std::set<Position> _black_avaliable_moves;
	King* _black_king;
	King* _white_king;
	Piece* _chosen_piece;
	bool _en_passant;

	// Tworzy obiekty typu Square i zapisje je w _board
	void initializeBoard();

	// Ustawia domy�lny kolor wybranych p�l
	void softColorReset() const;

	// Zwraca true, gdy przynajmniej jeden z kr�li jest atakowany
	bool checkForCheck();

	// Aktualizuje wektor dost�pnych ruch�w dla ka�dej bierki
	void updateAvailableMoves();

	// Zwrata true, gdy wst�pne warunki do przeprowadzenia roszady dla danej pozycji s� spe�nione
	bool castling(const Position& position);

	// Usuwa obiekty typu Sqwuare zapisane w _board
	void deleteBoard();

public:

	// Konstruktor
	Board();

	// Destruktor
	~Board();

	// Aktualizuje zbiory zawieraj�ce pozycje wszystkich atakowanych p�l przez bierki danego koloru
	void updateAllAvaliableMoves();

	// Aktualizuje informacje o bierkach w oparciu o ich pozycje
	void update();

	// Aktualizuje pozycje dla ka�dej bierki
	void updatePiecesPositions();

	// Ustawa wektor dost�pnch bierek
	void setPiecesVector(const std::vector<Piece*>& pieces);

	// Zwraca dost�p do zmiennej _board
	Square* operator[](const Position& key);

	// Zwraca referencje do mapy pozycji bierek
	std::map<Position, Piece*>& getAllPiecesPosition();

	// Wstala now� pozycj� dla bierki w mapie
	void setPiecePosition(const Position& position, Piece* piece);

	// Ustala zmienn� _chosen_piece
	void setChosenPiece(Piece* piece);

	// Aktualizuje inforamcje o tym czy dane pole jest zaj�te
	void updateIsOccupied();

	// Zwraca true, gdy kr�l podanego koloru jest atakowany
	bool checkForCheck(team side);

	// Zwraca wektor mo�liwych ruch�w, po kt�rych wykonaniu kr�l koloru bierki nie b�dzie atakowany
	std::vector<Position> predictCheck(Piece* piece);

	// Ustala wska�nik na kr�la czarnych
	void setBlackKing(King* king);

	// Ustala wska�nik na kr�la bia�ych
	void setWhiteKing(King* king);

	// Pokazuje dost�pne do wykonania ruchy dla bierki o podanej pozycji 
	void getMove(const Position& position);

	// Ustala mo�liwe do wykanania ruchy dla podanej bierki
	void setAvailableMoves(Piece* piece);

	// Zwraca wektor ruch�w pomi�dzy bierka, a podan� pozycj�
	std::vector<Position> getMovesTowardsDestination(const Position& destination);

	// Wykonuje ruch bierk� z aktualnej pozycji na wskazan� i zwraca wska�nik na t� bierk�
	Piece* makeMove(Position& old_position, const Position& new_position,
	                int& taken_black, int& taken_white, bool read_mode);

	// Sprawdza czy jest mo�liwe wykonanie bicia w przelocie dla podanej pozycji
	bool checkForEnPassant(const Position& position);

	// Ustala mo�liwo�� zrobienia bicia w przelocie dla pola o podanej pozycji
	void setEnPassant(const Position& position);

	// Pokazuje szachowni� na ekranie
	void draw(sf::RenderWindow* window) const;

	// Zwraca informacj� o tym czy i w jaki spos�b gra zosta�a zako�czona 
	gameResult isGameFinished(team turn);

	// Sprawdza czy kr�lowie s� atakowani
	void isCheck() const;

	// Zwraca pole na kt�rym dost�pne jest bicie w przelocie
	Position enPassantPosition() const;

	// Sprawdza czy dost�pna jest roszada dla kr�la o podanym kolorze
	void upateCastling(team turn) const;

	// Ustawia domy�lny kolor wszystkich p�l
	void hardColorReset() const;
};