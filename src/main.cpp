#include <iostream>
#include <fstream>
#include <vector>
#include <SDL.h>

#include "Game.h"

#ifdef _WIN32
int SDL_main(int argc, char** argv)
#else
int main(int argc, char** argv)
#endif
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