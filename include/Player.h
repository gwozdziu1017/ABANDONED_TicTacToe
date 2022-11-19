/*
*   Class responsible for Player
*   DG 11.2022
*/
#pragma once
#include <string>
#include <set>  // move matrix

using std::string;
using std::set;

class Player
{
public:
    Player() : name(""), moveMatrix(set<unsigned short>()) {};
    Player(string _name) : name(_name), moveMatrix(set<unsigned short>()) {};
    Player(Player&& p); // move
    Player(Player& p); // copy
    // consider if both above neccessary and if yes then apply rule of five

    void setName(const string _name);
    void addToMoveMatrix(const unsigned short move);

    string getName();
    set<unsigned short> getMoveMatrix();
private:
    string name;
    set<unsigned short> moveMatrix;
};