#include "../include/App.h"

void App::run()
{
    try
    {
        std::unique_ptr<GameHandler> game = std::make_unique<GameHandler>();
        game->runGame();
    }
    catch(...)
    {
        IO::print<string>("Sorry, something unexpected happend.\n");
    }
}