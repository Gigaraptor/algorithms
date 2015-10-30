#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif



SDL_Window *init(int *isSuccess)
{
	SDL_Window *temp;
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "SDL_Init() has failed : %s\n", SDL_GetError());
		*isSuccess = FAIL;
		return NULL;
	
	}
	temp = SDL_CreateWindow("Random Image Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(temp == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow() has failed : %s\n", SDL_GetError());
		*isSuccess = FAIL;
		return NULL;
	
	}
	
	return temp;

}

SDL_Renderer *createRenderer(SDL_Window *win, int *isSuccess)
{
	int flags = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;
	SDL_Renderer *temp = SDL_CreateRenderer(win, -1, flags);
	if(!temp)
	{
		fprintf(stderr, "SDL_CreateRenderer() has failed : %s\n", SDL_GetError());
		*isSuccess = FAIL;
		return NULL;
	
	}


	return temp;
}