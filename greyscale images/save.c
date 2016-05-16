#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif


/*
void saveToBitmap(char *filename, SDL_Surface *toSave, int x, int y)
Saves a bitmap

*/
void saveToBitmap(char *filename, SDL_Surface *toSave, int x, int y)
{
	if(!toSave)
	{
		fprintf(stderr, "NON FATAL ERROR : SDL_RenderReadPixels() has failed  : %s\n", SDL_GetError());
		return;
	
	}
	if(SDL_SaveBMP(toSave, filename) != 0)
	{
	
		fprintf(stderr, "NON FATAL ERROR : SDL_SaveBMP() has failed  : %s\n", SDL_GetError());
	
	}
}