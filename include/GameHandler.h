/*
*   Class resposible for gameplay handling
*   DG 11.2022
*/
#pragma once

#include "Table.h"
#include "Player.h"
#include "IO.h"
#include "Menu.h"
#include <utility>
#include <string>
#include <memory>
#include <algorithm>

using std::pair;
using std::string;

class GameHandler
{
public:
    GameHandler() : turn(0), menuPtr(std::make_unique<Menu>()) {}
    void runGame();
private:
    void handleGameplay();

    bool isTurnEven();
    pair<int, string> getPlayerMove(const pair<Player, Player>);
    bool isValidMove(const pair<int, string>);
    bool isValidMoveField(const int);
    bool isValidMoveValue(const string);
    bool isValidSign(const string);
    void updatePlayerMatrix(pair<Player, Player>&, const short unsigned int);
    short getPlayerChoiceAtBeginning();
    bool isWinningCombo(pair<Player, Player>&);

    pair<Player, Player> createPlayers();
    string getNameForPlayer();
    string getSignForPlayer();
    string getPlayerSignBasedOnTurn(pair<Player, Player>);

private:
    short turn;
    std::unique_ptr<Menu> menuPtr;
};
