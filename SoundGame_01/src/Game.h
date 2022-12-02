#pragma once

#include "rts.h"

class Game
{
public:
	Game();
	virtual ~Game();

protected:

	int m_PosX, m_PosY;
	std::vector<std::vector<int>> m_Piece;
	std::vector<std::vector<int>> m_Field;
};