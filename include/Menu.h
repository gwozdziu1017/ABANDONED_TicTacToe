/*
*   Class responsible for handling different menus
*   DG 11.2022
*/
#pragma once
#include <string>

using std::string;

class Menu
{
public:
    Menu() { setAllMenus(); };
private:
// --- setters
    void setAllMenus();
    void setNewGameMenu();
    void setPlayerNameMenu();
    void setYourTurnMenu();
    void setAskForMoveMenu();
    void setGameOverMenu();
    void setTieMenu();
    void setMainMenu();
    void setPostGameMenu();
    void setRulesMenu();
    void setCrashMenu();
    void setAskForMoveFieldMenu();
    void setAskForSignMenu();

public:
// --- getters
    string getNewGameMenu() { return this->NewGameMenu; };
    string getPlayerNameMenu() { return this-> PlayerNameMenu; }
    string getYourTurnMenu() { return this-> YourTurnMenu; }
    string getAskForMoveMenu() { return this-> AskForMoveMenu; }
    string getGameOverMenu() { return this-> GameOverMenu; }
    string getTieMenu() { return this-> TieMenu; }
    string getMainMenu() { return this->MainMenu; }
    string getPostGameMenu() { return this->PostGameMenu; }
    string getRulesMenu() { return this->RulesMenu; }
    string getCrashMenu() { return this->CrashMenu; }
    string getAskForSignMenu() { return this->AskForSignMenu; }

private:
    string NewGameMenu;
    string PlayerNameMenu;
    string YourTurnMenu;
    string AskForMoveMenu;
    string GameOverMenu;
    string TieMenu;
    string MainMenu;
    string PostGameMenu;
    string RulesMenu;
    string CrashMenu;
    string AskForMoveFieldMenu;
    string AskForSignMenu;

};