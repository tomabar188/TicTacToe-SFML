#ifndef M_H
#define M_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu {
public:
    Menu(int s);
    void draw(sf::RenderWindow& window);
    int click(float mouseX, float mouseY);
    void setMode(std::string mode);
    void setDifficulty(int difficulty);
    void setButtonVisibility(bool visible);
    enum MenuOptions {
        Start,
        Difficulty,
        Mode,
        Exit,
        None
    };

private:
    sf::RectangleShape startButton;
    sf::RectangleShape difficultyButton;
    sf::RectangleShape modeButton;
    sf::RectangleShape exitButton;
    sf::Font font;
    sf::Text startText;
    sf::Text difficultyText;
    sf::Text modeText;
    sf::Text exitText;
    sf::Text displayDifficulty;
    sf::Text displayMode;
    bool difficultyButtonVisible = true;


    void setupButton(sf::RectangleShape& button, sf::Text& text, const std::string& label, float x, float y, const sf::Color& color);
};

#endif