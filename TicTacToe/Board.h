#ifndef B_H
#define B_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Player.h"

class Board {
public:
    Board(int size, float cellSize);

    void initialize();
    void restart();
    void draw(sf::RenderWindow& window);
    bool placeMarker(int row, int col, Player player);
    Player checkWin() const;
    bool isFull() const;
    float getCellSize() const;
    void loadTextures(const sf::Texture& xTexture, const sf::Texture& oTexture);
    const std::vector<std::vector<Cell>>& getCells() const;

private:
    std::vector<std::vector<Cell>> cells;
    int size;
    float cellSize;
};

#endif
