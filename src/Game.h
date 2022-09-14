#include <SDL2/SDL.h>
#ifdef _WIN32
#undef main // Necessary
#endif

class Game
{
    public:
        Game();
        
        // Initialize the game
        bool Initialize();
        
        // Run the game loop until the game is over
        void RunLoop();

        // Shut down the game
        void Shutdown();
    
    private:
        // Helper functions for the game loop
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();

        // Window created by SDL
        SDL_Window* mWindow;

        // Member variables
        bool mIsRunning;
        SDL_Renderer* mRenderer;

};