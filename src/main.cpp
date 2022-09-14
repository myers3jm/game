#include <iostream>
#include <fstream>
#include <vector>
#ifdef _WIN32
#include <SDL.h>
#undef main // Necessary
#else
#include <SDL2/SDL.h>
#endif

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
