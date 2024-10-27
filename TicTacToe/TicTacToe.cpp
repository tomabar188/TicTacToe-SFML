#include "Game.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

enum class State {
    Menu,
    Playing,
    Exit
};


int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Tic Tac Toe");
    Menu menu(600);
    Game game(600, window);
    int difficulty=5;
    bool aiopponent=true;
    menu.setDifficulty(6);  
    menu.setMode("Player vs AI"); 
    

    State state = State::Menu;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (state == State::Menu) {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    int selectedOption = menu.click(event.mouseButton.x, event.mouseButton.y);
                    if (selectedOption == Menu::MenuOptions::Start) {
                        state = State::Playing;
                    }
                    if (selectedOption == Menu::MenuOptions::Difficulty) {
                        difficulty = (difficulty < 8) ? ++difficulty : 1;
                        menu.setDifficulty(difficulty);
                    }
                    if (selectedOption == Menu::MenuOptions::Mode) {
                        aiopponent = !aiopponent;
                        if (aiopponent) {
                            menu.setMode("Player vs AI");
                            menu.setButtonVisibility(true);
                        }
                        else {
                            menu.setButtonVisibility(false);
                            menu.setMode("Player vs Player");
                        }
                    }
                    else if (selectedOption == Menu::MenuOptions::Exit) {
                        state = State::Exit;
                        window.close();
                    }
                }
            }
            else if (state == State::Playing) {
                game.setOponent(aiopponent, difficulty);
                game.handler(event);
            }


            window.clear();

            if (state == State::Menu) {
                menu.draw(window);
            }


            else if (state == State::Playing) {
                game.update();
                game.render();
                if (!game.isGameOn()) {
                    state = State::Menu;
                    game.restartGame();
                    
                }
            }
            window.display();
        }
    }

    return 0;
}
