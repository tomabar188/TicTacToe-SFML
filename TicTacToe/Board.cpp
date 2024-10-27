#include "Board.h"

Board::Board(int size, float cellSize) : size(size), cellSize(cellSize) {
    initialize();
}

void Board::initialize() {
    cells.clear();
    for (int i = 0; i < size; ++i) {
        std::vector<Cell> row;
        for (int j = 0; j < size; ++j) {
            Cell cell(cellSize);
            cell.setPosition(j * cellSize, i * cellSize); 
            row.push_back(cell);
        }
        cells.push_back(row);
    }
}

void Board::draw(sf::RenderWindow& window) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cells[i][j].draw(window);
        }
    }
}

float Board::getCellSize() const {
    return cellSize;
}

bool Board::placeMarker(int row, int col, Player player) {
    
    if (row >= 0 && row < size && col >= 0 && col < size) {
        
        if ( cells[row][col].getMarker() == Player::None || player == Player::None) {
            cells[row][col].setMarker(player);
            return true;
        }
    }
    return false;
}


Player Board::checkWin() const {
    for (int i = 0; i < 3; i++) {
        if (cells[i][0].getMarker() == cells[i][1].getMarker()
            && cells[i][0].getMarker() == cells[i][2].getMarker())
        {
            if(cells[i][0].getMarker()!=Player::None) return cells[i][0].getMarker();
        }

        if (cells[0][i].getMarker() == cells[1][i].getMarker()
            && cells[0][i].getMarker() == cells[2][i].getMarker())
        {
            if (cells[0][i].getMarker() != Player::None) return cells[0][i].getMarker();
        }

    }
    if ((cells[1][1].getMarker() != Player::None) 
        && (cells[0][0].getMarker() == cells[2][2].getMarker()
            && cells[0][0].getMarker() == cells[1][1].getMarker())
        || (cells[0][2].getMarker() == cells[2][0].getMarker()
            && cells[0][2].getMarker() == cells[1][1].getMarker())) {
         return cells[1][1].getMarker();
        }
    return Player::None;
}

bool Board::isFull() const {
    for (const auto& row : cells) {
        for (const auto& cell : row) {
            if (cell.getMarker() == Player::None) {
                return false;
            }
        }
    }
    return true;
}

void Board::loadTextures(const sf::Texture& xTexture, const sf::Texture& oTexture) {
    for (auto& row : cells) {
        for (auto& cell : row) {
            cell.loadTextures(xTexture, oTexture);
        }
    }
}

const std::vector<std::vector<Cell>>& Board::getCells() const {
    return cells;
}


void Board::restart() {

    for (auto& row : cells) {
        for (auto& cell : row) {
            cell.deleteMarker();
        }
    }
    initialize();
}
