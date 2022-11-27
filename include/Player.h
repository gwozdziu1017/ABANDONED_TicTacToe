/*
*   Class responsible for Player
*   DG 11.2022
*/
#pragma once
#include <string>
#include <set>  // moveMatrix
#include <vector> // winningCombos

using std::string;
using std::set;
using std::vector;

class Player
{
public:
    Player() : name(""), moveMatrix(set<unsigned short>()) {};
    Player(string _name) : name(_name), moveMatrix(set<unsigned short>()) {};

    void setName(const string _name);
    void addToMoveMatrix(const unsigned short move);
    string getName();
    set<unsigned short> getMoveMatrix();
    bool getIsWinningComboInMoveMatrix();

private:
    string name;
    set<unsigned short> moveMatrix;
};