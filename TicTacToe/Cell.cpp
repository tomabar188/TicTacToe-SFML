#include "Cell.h"

Cell::Cell(float size) : marker(Player::None), xTexture(nullptr), oTexture(nullptr) {
    shape.setSize(sf::Vector2f(size, size));
    shape.setFillColor(sf::Color::White);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(1.f);
}

void Cell::loadTextures(const sf::Texture& xTex, const sf::Texture& oTex) {
    xTexture = &xTex;
    oTexture = &oTex;
}

void Cell::setMarker(Player player) {
    marker = player;
    updateMarker();  
}



void Cell::setPosition(float x, float y) {
    shape.setPosition(x, y);
    sprite.setPosition(x+30, y+30); 
}

void Cell::draw(sf::RenderWindow& window) {
    window.draw(shape);       
    if (marker != Player::None) {
        window.draw(sprite);  
    }
}

void Cell::updateMarker() {
    if (marker == Player::X && xTexture != nullptr) {
        sprite.setTexture(*xTexture);
    }
    else if (marker == Player::O && oTexture != nullptr) {
        sprite.setTexture(*oTexture);
    }
}

void Cell::deleteMarker() {
    marker = Player::None;
    sprite.setTexture(sf::Texture());
    
}

Player Cell::getMarker() const {
    return marker;
}