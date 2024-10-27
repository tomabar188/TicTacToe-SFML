#ifndef C_H
#define C_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Cell {
public:
    Cell(float size);
    void setPosition(float x, float y);
    void setMarker(Player player);
    Player getMarker() const;
    void draw(sf::RenderWindow& window);
    void loadTextures(const sf::Texture& xTexture, const sf::Texture& oTexture);  
    void deleteMarker();

private:
    Player marker;               
    sf::RectangleShape shape;    
    sf::Sprite sprite;
    const sf::Texture* xTexture;
    const sf::Texture* oTexture;
    void updateMarker();    


};

#endif
