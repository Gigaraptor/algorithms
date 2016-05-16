#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif

/*
	SDL_Window *initSDL(optionsData *opt, int *success):
	initialise SDL2 and associated library

*/

SDL_Window *initSDL( int *success )
{
	fprintf( stderr , "Initialising SDL2 and SDL2 Extension Libraries....\n" );
	SDL_Window *temp;
	int SDL_Flags, IMG_Flags;
	SDL_Flags = SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO;
	IMG_Flags = IMG_INIT_JPG | IMG_INIT_PNG;
	//Main SDL2 Library
	if( SDL_Init( SDL_Flags ) < 0 )
	{
		fprintf( stderr , "SDL_Init has failed : %s \n" , SDL_GetError() );
		*success = FAIL;
		return NULL;
	}
	//Image library
	if( !( IMG_Init( IMG_Flags ) & IMG_Flags ) )
	{
		fprintf( stderr , "IMG_Init has failed, %s \n" , IMG_GetError() );
		*success = FAIL;
		return NULL;
	
	}
	//initialise window
	temp = SDL_CreateWindow( "Black and White" , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , 1280 ,
	720 , SDL_WINDOW_SHOWN );
	if( !temp )
	{
		fprintf( stderr , "SDL_CreateWindow has failed : %s \n" , SDL_GetError() );
		*success = FAIL;
		return NULL;
	}
	
	return temp;
}
/*
	SDL_Renderer *createRenderer(SDL_Window *screen, int *success):
	initialise hardware renderer

*/

SDL_Renderer *createRenderer( SDL_Window *screen , int *success )
{
	fprintf( stderr , "Creating SDL2 Renderer....\n" );
	SDL_Renderer *temp;
	int Render_Flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;//Hardware acceleration and a frame rate capped by the refresh rate of the monitor
	temp = SDL_CreateRenderer( screen , -1 , Render_Flags );
	if( !temp )
	{
		fprintf( stderr , "SDL_CreateRenderer has failed : %s \n" , SDL_GetError() );
		*success = FAIL;
		return NULL;
	}

	return temp;

}
/*
	SDL_Surface *loadImage(char *filename, int *success):
	loads and returns a SDl_Surface

*/
SDL_Surface *loadImage(char *filename, int *success)
{
	fprintf( stderr , "Loading image and converting it to texture from %s....\n" , filename );
	SDL_Surface *temp;
	temp = IMG_Load( filename );//image library used to load things other than bitmaps
	if(!temp)
	{
		fprintf( stderr , "IMG_LoadBMP has failed: %s \n" , IMG_GetError() );
		*success = FAIL;
		return NULL;
	
	}
	return temp;

}