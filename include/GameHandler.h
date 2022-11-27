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
    bool isValidMove(const pair<int, string>);
    bool isValidMoveField(const int);
    bool isValidMoveValue(const string);
    void updatePlayerMatrix(pair<Player, Player>&, const short unsigned int);
    short getPlayerChoiceAtBeginning();
    bool isWinningCombo(pair<Player, Player>&);

    pair<Player, Player> createPlayers();
    string getNameForPlayer();

private:
    short turn;
};
