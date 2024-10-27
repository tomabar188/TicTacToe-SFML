#include "AiOpponent.h"
#include<iostream>
AiOpponent::AiOpponent(Board& board) : origBoard(board) {}


int AiOpponent::minimaks(Board board, int depth, int maxDepth, bool isMaximizing) {
    if (depth >= maxDepth) return 0;

    Player winner = board.checkWin();
    if (winner == Player::O) return 1;     
    if (winner == Player::X) return -1;    
    if (board.isFull()) return 0;          

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.getCells()[i][j].getMarker() == Player::None) {
                    board.placeMarker(i, j, Player::O);
                    int score = minimaks(board, depth + 1, maxDepth, false);
                    board.placeMarker(i, j, Player::None);
                    bestScore = std::max(score, bestScore);
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.getCells()[i][j].getMarker() == Player::None) {
                    board.placeMarker(i, j, Player::X);
                    int score = minimaks(board, depth + 1, maxDepth, true);
                    board.placeMarker(i, j, Player::None);
                    bestScore = std::min(score, bestScore);
                }
            }
        }
        return bestScore;
    }

}

void AiOpponent::findBestMove() {
    int bestScore = -1000;
    int bestRow = -1, bestCol = -1;

    
    for (int i = 0; i < 3; i++) {
        for (int n = 0; n < 3; n++) {
            
            if (origBoard.getCells()[i][n].getMarker() == Player::None) { 
                
                origBoard.placeMarker(i, n, Player::O); 

                int score = minimaks(origBoard, 0, dificulty, false); 

                
                origBoard.placeMarker(i, n, Player::None);

                
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = n;
                }
            }
        }
    }

    
    if (bestRow != -1 && bestCol != -1) {
        origBoard.placeMarker(bestRow, bestCol, Player::O);
    }
}




void AiOpponent::setMap(Board& board) {

	origBoard = board;
	//BoardMap.push_back(origBoard);
	findBestMove();
}