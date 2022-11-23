/*
*   Class resposible for gameplay handling
*   DG 11.2022
*/
#pragma once

#include "Table.h"
#include "Player.h"
#include "IO.h"
#include <utility>
#include <string>
#include <memory>

using std::pair;
using std::string;

class GameHandler
{
public:

private:
    void runGame();
    void handleGameplay();

    bool isTurnEven();
    pair<int, string> getPlayerMove();
    bool isValidMove(const short uint);
    bool isValidMoveField(const int);
    bool isValidMoveValue(const string);
    void updatePlayerMatrix(pair<Player, Player>&, const short uint);
    short getPlayerChoiceAtBeginning();
    bool isWinningCombo(const pair<Player, Player>&);

    pair<Player, Player> createPlayers();
    string getNameForPlayers();

private:
    short turn;
};
