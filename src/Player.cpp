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