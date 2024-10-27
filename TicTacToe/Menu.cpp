#include "Menu.h"

Menu::Menu(int s) {
    if (!font.loadFromFile("res/arial.ttf")) {
        std::cout << "Nie uda³o siê za³adowaæ czcionki!" << std::endl;
        exit(EXIT_FAILURE);
    }

    displayDifficulty.setFont(font);
    displayDifficulty.setCharacterSize(20);
    displayDifficulty.setFillColor(sf::Color::Black);
    displayDifficulty.setPosition(20, 10);  

    
    displayMode.setFont(font);
    displayMode.setCharacterSize(20);
    displayMode.setFillColor(sf::Color::Black);
    displayMode.setPosition(20, 40);

    setDifficulty(1);  
    setMode("Gracz vs Gracz");

    setupButton(startButton,startText, "START", s / 2 - 100, s / 6, sf::Color::Green);
    setupButton(modeButton, modeText, "MODE", s / 2 - 100, 2 * s / 6, sf::Color::Yellow);
    setupButton(difficultyButton, difficultyText, "DIFFICULTY", s / 2 - 100, 3*s / 6, sf::Color::Blue);
    setupButton(exitButton, exitText, "EXIT", s / 2 - 100,  4 * s / 6, sf::Color::Red);
}

void Menu::setupButton(sf::RectangleShape& button, sf::Text& text, const std::string& label, float x, float y, const sf::Color& color) {
    button.setSize(sf::Vector2f(200.f, 50.f));
    button.setFillColor(color);
    button.setPosition(x, y);
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setPosition(
        x + button.getSize().x / 2 - text.getGlobalBounds().width / 2,
        y + button.getSize().y / 2 - text.getGlobalBounds().height / 2 - 10
    );
}

void Menu::setDifficulty(int difficulty) {
    displayDifficulty.setString("Difficulty: " + std::to_string(difficulty));
}

void Menu::setMode(std::string mode) {
    displayMode.setString("Mode: " + mode);
}


void Menu::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::White);

    
    window.draw(displayMode);

    window.draw(startButton);
    window.draw(modeButton);
    if (difficultyButtonVisible) {
        window.draw(displayDifficulty);
        window.draw(difficultyButton);
        window.draw(difficultyText);
    }
    window.draw(exitButton);
    window.draw(startText);
    window.draw(modeText);
    
    window.draw(exitText);
}

int Menu::click(float mouseX, float mouseY) {
    if (startButton.getGlobalBounds().contains(mouseX, mouseY)) {
        return MenuOptions::Start;
    }
    else if (difficultyButton.getGlobalBounds().contains(mouseX, mouseY)) {
        return MenuOptions::Difficulty;
    }
    else if (modeButton.getGlobalBounds().contains(mouseX, mouseY)) {
        return MenuOptions::Mode;
    }
    else if (exitButton.getGlobalBounds().contains(mouseX, mouseY)) {
        return MenuOptions::Exit;
    }
    return MenuOptions::None;
}


void Menu::setButtonVisibility( bool visible) {
    difficultyButtonVisible = visible;
    
}