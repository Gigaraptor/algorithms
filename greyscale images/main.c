#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif


int main(int argc, char *argv [])
{
	SDL_Surface *conversion;
	SDL_Window *win;
	SDL_Renderer *rend;
	int isSuccess = SUCCESS;

	if(argv[1] && argv[2])
	{
		win = initSDL(&isSuccess);
		rend = createRenderer(win, &isSuccess);
		conversion = loadImage(argv[1], &isSuccess);
		blackAndWhite(conversion);
		saveToBitmap(argv[2], conversion, conversion->w, conversion->h);
	}
	else
	{
		printf("You need to give a file input and output!\n");
	
	}
	return 0;
}