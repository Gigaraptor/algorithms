#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif



/*
	void vampire(SDL_Surface *toConvert)
	
	generates a black image with red bits
*/
void vampire(SDL_Surface *toConvert)
{
	Uint32 componentVal;
	Uint32 i;
	Uint32 *pixels;
	Uint8 r,g,b;
	SDL_LockSurface(toConvert);
	pixels = toConvert->pixels;
	for(i = 0; i < toConvert->h * toConvert->w * toConvert->format->BytesPerPixel; i += toConvert->format->BytesPerPixel)
	{
		pixels = toConvert->pixels + i;
		SDL_GetRGB(*pixels, toConvert->format, &r, &g, &b);
		r = (R_COEFFICIENT * r) + (G_COEFFICIENT * g) + (B_COEFFICIENT * b);
		g = r;
		b = g;
		componentVal = r + ( g >> 8) + (b >> 16);
		*pixels = componentVal;
	}

	SDL_UnlockSurface(toConvert);
}
/*
void blackAndWhite(SDL_Surface *toConvert)
Gives a luminosity gradient of grayscale here

*/
void blackAndWhite(SDL_Surface *toConvert)
{
	Uint32 componentVal;
	Uint32 i;
	Uint32 *pixels;
	Uint8 r,g,b;
	SDL_LockSurface(toConvert);
	pixels = toConvert->pixels;
	for(i = 0; i < toConvert->h * toConvert->w * toConvert->format->BytesPerPixel; i += toConvert->format->BytesPerPixel)
	{
		pixels = toConvert->pixels + i;
		SDL_GetRGB(*pixels, toConvert->format, &r, &g, &b);
		r = (R_COEFFICIENT * r) + (G_COEFFICIENT * g) + (B_COEFFICIENT * b);
		g = r;
		b = g;
		componentVal = r + (g << 8) + (b << 16);
		*pixels = componentVal;
	}

	SDL_UnlockSurface(toConvert);
}