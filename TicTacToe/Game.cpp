#include "Game.h"
#include "AiOpponent.h"

Game::Game(int s, sf::RenderWindow& win) :
    window(win),
    board(3, s / 3),
    currentPlayer(Player::X),
    gameOn(true),
    ai(board),
    gameRunning(true) {

    if (!xTexture.loadFromFile("res/x.png") || !oTexture.loadFromFile("res/o.png")) {
        std::cerr << "Nie udalo sie zaladowac plikow" << std::endl;
        exit(EXIT_FAILURE);
    }

    board.loadTextures(xTexture, oTexture);
}

void Game::handler(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        int row = event.mouseButton.y / board.getCellSize();
        int col = event.mouseButton.x / board.getCellSize();

        if (gameOn && board.placeMarker(row, col, currentPlayer)) {
            currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
            if (currentPlayer == Player::O && AIon && gameOn) {
                ai.setMap(board);
                currentPlayer = Player::X;
            }
        }
    }
}

void Game::setOponent(bool isComputer, int dificulty) {
    AIon = isComputer;
    ai.dificulty = (8 >= dificulty > 0) ? dificulty : 8;
}

void Game::update() {
    if (board.checkWin() == Player::X) {
        gameOn = false;
    }
    if (board.checkWin() == Player::O) {
        gameOn = false;
    }
    if (board.isFull()) gameOn = false;
}

void Game::render() {
    board.draw(window);
}

bool Game::isGameOn() {
    return gameOn;
}

void Game::restartGame() {
    gameOn = true;
    currentPlayer = Player::X;
    board.restart(); 
    board.loadTextures(xTexture, oTexture);
}
