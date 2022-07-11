#include "Game.h"

Game::Game()
{
}

bool Game::Initialize()
{
    // Initialize SDL subsystems
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    // Create window
    mWindow = SDL_CreateWindow(
        "Moo", // Title
        100, // Top left x-coord
        100, // Top left y-coord
        1024, // Width
        768, // Height
        0 // Flags (0 for no flags set)
    );
    if (!mWindow)
    {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }
    mIsRunning = true;

    // Create renderer
    mRenderer = SDL_CreateRenderer(
        mWindow, // Window to create renderer for
        -1, // Usually -1
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC // Graphics hardware and VSYNC
    );
    return true;
}

void Game::Shutdown()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }

    // Get state of keyboard
    const Uint8* state = SDL_GetKeyboardState(NULL);

    // If ESCAPE is pressed, end loop
    if (state[SDL_SCANCODE_ESCAPE])
    {
        mIsRunning = false;
    }
}

void Game::UpdateGame()
{
    // stuff
}

void Game::GenerateOutput()
{
    // Clear back buffer
    SDL_SetRenderDrawColor(
        mRenderer,
        0,      // R
        0,      // G
        255,    // B
        255     // A
    );
    SDL_RenderClear(mRenderer);

    // Swap front and back buffers
    SDL_RenderPresent(mRenderer);
}