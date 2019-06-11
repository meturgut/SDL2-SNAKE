#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "Box.hpp"

class Snake
{
private:    
    std :: vector <Box*> tails;     // we can use a list instead vector
    int boxCount;
       
    int defaultLocationX;
    int defaultLocationY;
    bool dead = false;
    bool didEat = false;
public:
    static const int speed = 16;     // snake's move speed (this value must be equal box's width and height)
    Box* head;                      // snake's head piece
    
    Snake(/* args */);
    ~Snake();

    void render(SDL_Renderer*);
    void addBox();
    void move(int screenWidth,int screenHeight);
    bool eat(SDL_Point*);
    bool isDead();

};

