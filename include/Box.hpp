#ifndef BOX_HPP
#define BOX_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
enum DIRECTION{RIGHT = 1,LEFT = 2,DOWN = 4,UP = 8};
class Box
{
private:
    const int mWidth  = 16;      
    const int mHeight = 16;     
    
    SDL_Rect* boxRect;
    SDL_Color* boxColor;

public:
    DIRECTION dir;
    Box(/* args */);
    ~Box();
    SDL_Color* getColor();
    SDL_Rect* getRect();
    int getWidth();
    int getHeight();
};

#endif