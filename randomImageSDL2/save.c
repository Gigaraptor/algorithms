#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif



void saveToBitmap(char *filename, SDL_Window *win, SDL_Renderer *rend)
{
	SDL_Surface *temp = SDL_CreateRGBSurface(0,SCREEN_WIDTH, SCREEN_HEIGHT, 32, 0, 0, 0, 0);
	SDL_RenderReadPixels(rend, NULL, SDL_PIXELFORMAT_ARGB8888, temp->pixels, temp->pitch);
	if(!temp)
	{
		fprintf(stderr, "NON FATAL ERROR : SDL_RenderReadPixels() has failed  : %s\n", SDL_GetError());
		return;
	
	}
	if(SDL_SaveBMP(temp, filename) != 0)
	{
	
		fprintf(stderr, "NON FATAL ERROR : SDL_SaveBMP() has failed  : %s\n", SDL_GetError());
	
	}
	SDL_FreeSurface(temp);



}