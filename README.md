# Tic-Tac-Toe game
Tic Tac Toe game in C++ using the SFML library for graphical rendering. The game includes a single-player mode with AI, a two-player mode, and adjustable difficulty levels for the AI.  

![2024-10-28 14 39 41](https://github.com/user-attachments/assets/fb05eb0a-ec6c-47f1-8153-f3a268f73353)

## Features
* Single Player (Player vs AI): Play against the computer with various difficulty levels.
* Multiplayer (Player vs Player): Play against another human player locally.
* Menu and Game States: Manage game settings and navigate through the menu.
* Graphical Interface: Simple interface.

## Project Structure
### Core Files
### 1.TicTacToe.cpp:
Main entry point of the application.
Manages the game loop and transitions between game states (Menu, Playing, Exit).

### 2.Menu System
Menu.h & Menu.cpp: Manages the main menu interface, including options for starting the game, adjusting difficulty, toggling between Player vs Player and Player vs AI modes, and exiting.

### 3.Game Logic
Game.h & Game.cpp: Handles the primary game logic, including player turns, interaction with the AI opponent, game updates, and rendering the board.

### 4.Board and Cells
Board.h & Board.cpp: Manages the Tic Tac Toe board, checking for wins, drawing cells, and handling marker placement.
Cell.h & Cell.cpp: Represents individual cells on the board, manages markers (X or O), and draws them on the screen.

### 5.AI Opponent
AiOpponent.h & AiOpponent.cpp: Implements an AI opponent with a minimax algorithm, allowing the computer to make optimal moves based on difficulty.

### 6. Player Enum
Player.h: Defines the player types (None, X, O) for easy reference throughout the game.

## How the Game Works

### 1.Menu:
Adjust game settings, select difficulty, and start the game from the main menu.

### 2.Gameplay:
Each player takes turns placing their marker (X or O) on the board.
In single-player mode, the AI opponent will respond after each player move.
The game checks for a win or draw condition after each move.

### 3.AI Opponent:
The AI uses the minimax algorithm to determine the best possible move.
Difficulty settings control the depth of the AI’s look-ahead, making it easier or harder to beat.

### 4.Game End:
Once a player wins or the board is full, the game will return to the main menu, where players can start a new game or adjust settings.
