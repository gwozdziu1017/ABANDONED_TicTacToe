#include "../include/App.h"

int main()
{
    std::unique_ptr<App> ticTacToe = std::make_unique<App>();
    ticTacToe->run();

    return 0;
}