#include "Game.hpp"
#define FPS 15

const extern int SCREEN_HEIGHT; // initialization in Game.hpp
const extern int SCREEN_WIDTH;  // initialization in Game.hpp

int main(int argc, char const *argv[])
{
    Game* game = new Game();
    
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;

    game->init("SNAKE",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    
    while (game->isRunning())
    {
        frameStart = SDL_GetTicks();
        game->render();
        game->handleEvents();
        game->update();
        game->gameOver();
        frameTime = SDL_GetTicks()-frameStart;

        if (frameDelay > frameTime )
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    
    delete game;

    return 0;
}
