#pragma once
#include "Piece.h"

class GameBoardView;
class Player;

class GameController
{
private:
	GameBoardView* m_view;
	Player* m_blackPlayer;
	Player* m_whitePlayer;
public:
	GameController(GameBoardView* view, Player* blackPlayer, Player* whitePlayer)
		: m_view {view},
		m_blackPlayer {blackPlayer},
		m_whitePlayer {whitePlayer}
	{};
public:
	auto view() { return m_view; }
public:
	Piece::Color startGame();
};
