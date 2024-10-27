#ifndef AI_H
#define AI_H

#include <vector>
#include "Board.h"

class AiOpponent {
public:
	AiOpponent(Board& board);
	void setMap(Board& board );
	int dificulty;
private:
	Board& origBoard;
	
	std::vector<Board> BoardMap;
	int minimaks(Board board, int depth, int maxDepth, bool isMaximizing);
	void findBestMove();
	//std::vector<std::vector<std::vector<Cell>>> CellsMap;
};

#endif