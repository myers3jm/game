#include <iostream>
#include <fstream>
#include <vector>
#include <SDL2/SDL.h>

#include "Game.h"


int main()
{
    Game game;
    bool success = game.Initialize();
    if (success)
    {
        game.RunLoop();
    }
    game.Shutdown();
    return 0;
}