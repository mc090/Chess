export module Enum;

// Informuje czy bierka zosta³a zbita lub jaki ma kolor
export enum team {
	taken = -1,
	white,
	black
};

// Informuje o obecnym stanie rozgrywki
export enum gameResult
{
	tie = -1,
	nothing,
	white_won,
	black_won
};