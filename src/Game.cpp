#include "Snake.hpp"
#include "Game.hpp"

#include <iostream>
// static declarations
const int Snake :: speed; 
Snake* Game :: snake;
// static declarations
Game :: Game()
{
	snake = new Snake();
	food = randomCoordinate();
	foodCount++;
	std :: cout << food->x << " " << food->y << std :: endl;
}
Game ::~Game()
{
	delete snake;
	delete food;
}
void Game ::init(const char *title, int x, int y, int width, int height, int flags)
{
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("%s HATA \n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow(title, x, y, width, height, flags);

		if (window == NULL)
		{
			printf("%s \n", SDL_GetError());
		}
		else
		{
			SDL_Color fontColor = {0,0,0,0};
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			surface = SDL_GetWindowSurface(window);
			
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			if (renderer == NULL)
			{
				printf("%s \n", SDL_GetError());
				gameIsRunning = false;
			}
			else
			{
				gameIsRunning = true;
			}
		}
	}
}

void Game :: render()
{	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	snake->render(renderer);
	
	if(foodCount == 1) render(food);
	if (snake->eat(food) && foodCount == 0 ) {
		food = randomCoordinate();
		willRenderFood = true;
		foodCount++;
		std :: cout << food->x << " " << food->y << std :: endl;
	}
	if (willRenderFood)	render(food);
	
	
	SDL_RenderPresent(renderer);
	
}
void Game :: render(SDL_Point* point){
	SDL_Rect rect;
	rect = {point->x,point->y,16,16};

	SDL_SetRenderDrawColor(renderer,255,255,0,255);
	SDL_RenderFillRect(renderer,&rect);
	SDL_RenderPresent(renderer);

}
void Game :: update()
{	
	
	snake->move(SCREEN_WIDTH,SCREEN_HEIGHT);
	
}
void Game :: handleEvents()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != NULL)
	{
		switch (e.type)
		{
		case SDL_QUIT:
			gameIsRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
				case SDLK_DOWN:
				if (snake->head->dir == UP) break;
				snake->head->dir = DOWN;
				break;
			case SDLK_UP:
				if (snake->head->dir == DOWN) break;
				snake->head->dir = UP;
				break;
			case SDLK_RIGHT:
				if (snake->head->dir == LEFT) break;
				snake->head->dir = RIGHT;
				break;
			case SDLK_LEFT:
				if (snake->head->dir == RIGHT) break;
				snake->head->dir = LEFT;
				break;
			case SDLK_SPACE:
				break;
				}
		}
	}
}

SDL_Point* Game :: randomCoordinate(){
	SDL_Point* point = new SDL_Point();
	std :: srand(time(0));
	static const float screenScale = 0.80f; 
	int x = std :: rand() % (int)(SCREEN_WIDTH * screenScale);
	int y = std :: rand() % (int)(SCREEN_HEIGHT * screenScale);
	while (true)
	{
		if(x % Snake::speed != 0 ) x++;
		if(y % Snake::speed != 0 ) y++;

		if (x % Snake::speed == 0 && y % Snake::speed == 0 ) break;
	}
	
	point->x = x;
	point->y = y;
	return point;
}

void Game :: gameOver(){
	if (snake->isDead()) gameIsRunning = false;
	
}

void Game ::clean()
{
	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	
	food = NULL;
	snake = NULL;
	renderer = NULL;
	window = NULL;
	SDL_Quit();
}

bool Game ::isRunning()
{
	return gameIsRunning;
}
