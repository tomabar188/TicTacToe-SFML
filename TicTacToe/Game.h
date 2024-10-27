#ifndef G_H
#define G_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"
#include "AiOpponent.h"
#include<iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

class Game {
public:
    Game(int s, sf::RenderWindow& Window);
    void setOponent(bool isComputer, int difficulty);
    void handler(const sf::Event& event);
    void update();
    void render();
    bool isGameOn();
    void restartGame();
private:
   

    sf::RenderWindow& window;
    Board board;
    AiOpponent ai;
    Player currentPlayer;
    sf::Texture xTexture;
    sf::Texture oTexture;
    bool gameRunning;
    bool gameOn;
    bool AIon;
};

#endif
