#include "Snake.hpp"
#include "Game.hpp"
#include <vector>
#include <iostream>
#include <list>

int Game :: foodCount;

Snake :: Snake(){
    boxCount = 5;

	for (int  i = 0; i < boxCount; i++)tails.push_back(new Box());
	
	
	int distance = tails[0]->getWidth();
	defaultLocationX+=boxCount*distance;
    for (int i = 0; i < boxCount; i++)
    {
        defaultLocationX-=distance;
        tails[i]->getRect()->x = defaultLocationX;
        tails[i]->getRect()->y = defaultLocationY;
        tails[i]->getRect()->w = tails[i]->getWidth();
        tails[i]->getRect()->h = tails[i]->getHeight();
        tails[i]->dir = RIGHT;
    }
    
    head = tails[0]; 

}
Snake :: ~Snake(){
    for (int i = 0; i < boxCount; i++) delete tails[i];
}

void Snake :: move(int width,int height){

	for (int i = 0; i < boxCount; i++) // tails are moving
	{
		switch (tails[i]->dir)
		{
			case RIGHT: // right
				tails[i]->getRect()->x+=speed;
				break;
			case LEFT: // left
				tails[i]->getRect()->x-=speed;
				break;
			case DOWN: // down
				tails[i]->getRect()->y+=speed;
				break;
			case UP: // up
				tails[i]->getRect()->y-=speed;
				break;
		}	
	}
	for (int i = 0; i < boxCount; i++) // control snake in window edges
	{
		if (tails[i]->getRect()->x >= width)			
		{
			tails[i]->getRect()->x -= width;
		}
		if (tails[i]->getRect()->x < 0)
		{
			tails[i]->getRect()->x += width;
		}
		if (tails[i]->getRect()->y >= height)
		{
			tails[i]->getRect()->y -= height;
		}
		if (tails[i]->getRect()->y < 0)
		{
			tails[i]->getRect()->y += height;
		}
		
	}
	
	
	for (int i = boxCount-1; i > 0; i--) // tails are following snake's head
	{
		tails[i]->dir = tails[i-1]->dir;
	}
	
}
void Snake :: addBox (){
	
	int x = tails[boxCount-1]->getRect()->x;
	int y = tails[boxCount-1]->getRect()->y;

	switch (tails[boxCount-1]->dir)
	{
		case RIGHT:
			x-=speed;
			break;
		case LEFT:
			x+=speed;
			break;
		case UP:
			y+=speed;
			break;
		case DOWN:
			y-=speed;
			break;
	default:
		break;
	}
	Box * temp = new Box();
	temp->getRect()->x = x;
	temp->getRect()->y = y;
	temp->dir = tails[boxCount-1]->dir;
	SDL_Color a = {255,255,0,0};
	temp->getColor()->r = a.r;
	tails.push_back(temp);
	
	boxCount++;
    
}
bool Snake :: eat(SDL_Point* food){
	if (food->x == head->getRect()->x && food->y == head->getRect()->y )
	{
		std :: cout << "eated" << std ::endl;
		Game :: foodCount--;

		addBox();
		std :: cout << "Food Count : " << Game::foodCount << std:: endl;
		delete food;
		didEat = true;
		
	}
	return didEat;
    
}

bool Snake :: isDead(){
	
    for (int i = 1; i < boxCount - 1; i++)
    {
        if (tails[i]->getRect()->x == head->getRect()->x && tails[i]->getRect()->y == head->getRect()->y )
        {
            dead = true;
        }
    }
    return dead;
}


void Snake :: render(SDL_Renderer* renderer){
    
    for (int i = 0; i < boxCount; i++)
    {   
        SDL_SetRenderDrawColor(renderer,tails[i]->getColor()->r,tails[i]->getColor()->g,tails[i]->getColor()->b,tails[i]->getColor()->a);
        SDL_RenderFillRect(renderer,tails[i]->getRect()); 
    }
}