#include "../include/Menu.h"

void Menu::setAllMenus()
{
    this->setNewGameMenu();
    this->setPlayerNameMenu();
    this->setYourTurnMenu();
    this->setAskForMoveMenu();
    this->setGameOverMenu();
    this->setTieMenu();
    this->setMainMenu();
    this->setPostGameMenu();
    this->setRulesMenu();
    this->setCrashMenu();
    this->setAskForSignMenu();
}

void Menu::setNewGameMenu()
{
    this->NewGameMenu = "New game menu"; //todo
}

void Menu::setPlayerNameMenu()
{
    this->PlayerNameMenu = "What's your name: ";
}

void Menu::setYourTurnMenu()
{
    this->YourTurnMenu = "it's your turn!";
}

void Menu::setAskForMoveMenu()
{
    this->AskForMoveMenu = "Field: ";
}

void Menu::setGameOverMenu()
{
    this->GameOverMenu = "Game Over...";
}

void Menu::setTieMenu()
{
    this->TieMenu = "It's a tie!";
}

void Menu::setMainMenu()
{
    string tempString = "";
    tempString.append("*** Tic Tac Toe ***\n");
    tempString.append("Menu:\n");
    tempString.append("1. New Game");
    tempString.append("2. Rules\n");
    tempString.append("3. Exit");
}

void Menu::setPostGameMenu()
{
    this->PostGameMenu = "Post game menu"; //todo
}

void Menu::setRulesMenu()
{
    this->RulesMenu = "Rules menu"; //todo
}

void Menu::setCrashMenu()
{
    this->CrashMenu = "Sorry, something unexpected happend";
}

void Menu::setAskForSignMenu()
{
    this->AskForSignMenu = "What do you want to be your sign X or O?";
}