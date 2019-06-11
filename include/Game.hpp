#ifndef GAME_HPP
#define GAME_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Snake.hpp"
const int SCREEN_WIDTH  = 720;
const int SCREEN_HEIGHT = 560;
class Game
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Point* food;

    bool gameIsRunning;
    bool willRenderFood = false;

    
    
public:
    static int foodCount;
    static Snake* snake ;
  
    Game();
    ~Game();

    void init(const char*,int,int,int,int,int); // initializing sdl window and renderer
    void render();                              // general rendering for snake's moving and food's producing
    void render(SDL_Point*);                    // render a rectangle for specific coordinate (x,y)
    void handleEvents();                        // event management
    void update();                              // 
    void clean();                               // clean memory 
    bool isRunning();                           // Is game running ?
    void gameOver();                            // Game Over
    SDL_Point* randomCoordinate();              // produce a random coordinate
};


#endif