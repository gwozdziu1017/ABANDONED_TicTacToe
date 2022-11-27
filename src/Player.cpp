#include "../include/Player.h"

/* Sets player name as given arg */
void Player::setName(const string _name)
{
    this->name = _name;
}

/* Adding new element to container holding all moves player have done in game */
void Player::addToMoveMatrix(const unsigned short move)
{
    this->moveMatrix.insert(move);
}

/* Returns player name */
string Player::getName()
{
    return this->name;
}

/* Returns whole moveMatrix*/
set<unsigned short> Player::getMoveMatrix()
{
    return this->moveMatrix;
}

/*  Returns true ig f in move matrix there is combination of fields that means winning.
    Possible winning combos:
        [1,2,3]
        [1,4,7]
        [1,5,9]
        [4,5,6]
        [7,8,9]
        [2,5,8]
        [3,6,9]
        [3,5,7]
*/
bool Player::getIsWinningComboInMoveMatrix()
{
    vector<set<int>> winningCombos {
        {1, 2, 3},
        {1, 4, 7},
        {1, 5, 9},
        {4, 5, 6},
        {7, 8, 9},
        {2, 5, 8},
        {3, 6, 9},
        {3, 5, 7}
    };
    auto result = false;

    for(const auto combo : winningCombos)
        if(std::search(this->moveMatrix.begin(), this->moveMatrix.end(),
                        combo.begin(), combo.end()) != this->moveMatrix.end())
            result = true;

    return result;
}