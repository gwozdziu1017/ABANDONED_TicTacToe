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
    void setAllMenus();
    void setNewGameMenu();
    void setGetPlayerNameMenu();
    // etc

private:
    string NewGameMenu;
    string GetPlayerNameMenu;
    // etc

};