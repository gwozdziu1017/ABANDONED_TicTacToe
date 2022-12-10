#include "../include/GameHandler.h"

/*  Launching at the beggining of game.
    Handles the beggining choice of player what he wants to do
*/
void GameHandler::runGame()
{
    bool isGameOver = false;

    //while(!isGameOver)
    //{
        IO::print<string>(menuPtr->getMainMenu());
        const short userChoice = IO::get<short>(); //->getPlayerChoiceAtBeginning();   // get in loop and return only if valid value
    
        switch(userChoice)
        {
            case 2:
            {
                IO::print<string>(menuPtr->getRulesMenu());
                break;
            }
            case 1:
                this->handleGameplay();
            case 3:
            {
                isGameOver = true;
                break;
            }
            default:
                break;
                IO::print<string>(menuPtr->getCrashMenu());
        }
    //}
}

/*  Main method where gameplay core is handled.
    Turn for particular player is distinguished by odd and even numbers:
        Player 1 - odd
        Player 2 - even
    Every turn is finished by turn++
*/
void GameHandler::handleGameplay()
{
    // Initialization before start
    pair<Player, Player> players = std::move(this->createPlayers());
    this->turn = 1;
    pair<int, string> playerMove{};
    bool isGameOver = false;
    std::unique_ptr<Table> tablePtr = std::make_unique<Table>();

    // Print for user convenience
    IO::printContainer<std::vector<string>>(tablePtr->getTableWithFieldNumbers());
    IO::print<string>("\n"); //todo: make it nicer

    // As long as gameplay continue
    while (not isGameOver && this->turn < 10)
    {
        IO::printContainer<vector<string>>(tablePtr->getTable());
        if(this->isTurnEven())
            IO::print(players.second.getName() + menuPtr->getYourTurnMenu());
        else
            IO::print(players.first.getName() + menuPtr->getYourTurnMenu());

        IO::print(menuPtr->getAskForMoveMenu());
        playerMove = std::move(this->getPlayerMove(players));
        tablePtr -> updateTable(tablePtr, playerMove.first, playerMove.second);
        this->updatePlayerMatrix(players, playerMove.first);

        if(this->isWinningCombo(players))
        {
            IO::print(menuPtr->getGameOverMenu());
            isGameOver = true;
            break; // todo: check if it will break over while loop
        }
        this->turn++;
    }

    // Wining combo is secured so if you're here it means players are out of turns
    IO::print(menuPtr->getTieMenu());

    // todo:: handle new game right after ended
}

short GameHandler::getPlayerChoiceAtBeginning()
{
    return IO::get<short>();
}

bool GameHandler::isWinningCombo(pair<Player, Player>& players)
{
    if(this->isTurnEven())
        return players.second.getIsWinningComboInMoveMatrix();
    else
        return players.first.getIsWinningComboInMoveMatrix();
}

/*  Returns std::pair of two players */
std::pair<Player, Player> GameHandler::createPlayers()
{
    auto nameForFirstPlayer = this->getNameForPlayer();
    auto nameForSecondPlayer = this->getNameForPlayer();

    auto signForFirstPlayer = this->getSignForPlayer();
    auto signForSecondPlayer = this->getSignForPlayer();


    return std::make_pair(Player(nameForFirstPlayer, signForFirstPlayer),
                        Player(nameForSecondPlayer, signForSecondPlayer));
}

/*  Asks for player name and returns it */
string GameHandler::getNameForPlayer()
{
    IO::print(menuPtr->getPlayerNameMenu());
    return IO::get<string>();
}

string GameHandler::getSignForPlayer()
{
    string tempSign = "";
    do{
        IO::print(menuPtr->getAskForSignMenu());
        tempSign = IO::get<string>();
    } while(!isValidSign(tempSign));

    return tempSign;
}

/* Returns true if sign is valid (X or O) and false if other */
bool GameHandler::isValidSign(const string sign)
{
    if(sign == "X" || sign == "O" || sign == "x" || sign == "o")
        return true;
    else
        return false;
}
/* Returns true if turn is even number */
bool GameHandler::isTurnEven()
{
    return this->turn % 2 == 0;
}

/*  Returns only valid players move.
    Move is pair<field, value>.
    Checks if move is legal and returns only if legal
*/
pair<int, string> GameHandler::getPlayerMove(const pair<Player, Player> players)
{
    auto moveField = 0;
    string moveValue = "";
    pair<int, string> move{};

    do
    {
        IO::print(menuPtr->getAskForMoveMenu());
        moveField = IO::get<int>();
        moveValue = this->getPlayerSignBasedOnTurn(players);

        move.first = moveField;
        move.second = moveValue;
    } while (not this->isValidMove(move));

    return move;
}

string GameHandler::getPlayerSignBasedOnTurn(pair<Player, Player> players)
{
    if(isTurnEven())
        return players.first.getSign();
    else
        return players.second.getSign();
}

/*  Checks if whole move is valid.
    It means if field user choose is greater than 0 and less than 10
    and if value is either + or O
*/
bool GameHandler::isValidMove(const pair<int, string> move)
{
    return isValidMoveField(move.first) && isValidMoveValue(move.second);
}

/* Returns true if field is valid */
bool GameHandler::isValidMoveField(const int move)
{
    return move > 0 && move < 10;
}

/* Returns true if value is valid */
bool GameHandler::isValidMoveValue(const string value)
{
    return (value == "+" || value == "O");
}

/* Updates move matrix accordingly to first or second player based on given turn */
void GameHandler::updatePlayerMatrix(pair<Player, Player>& players, const short unsigned int move)
{
    if(this->isTurnEven())
        players.second.addToMoveMatrix(move);
    else
        players.first.addToMoveMatrix(move);
}
