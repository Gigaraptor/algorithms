#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

const static float R_COEFFICIENT = 0.21;
const static float G_COEFFICIENT = 0.72;
const static float B_COEFFICIENT = 0.07;
const static int SUCCESS = 0;
const static int FAIL = 1;

SDL_Surface *loadImage(char *filename, int *success);
void blackAndWhite(SDL_Surface *toConvert);
SDL_Window *initSDL( int *success);
SDL_Renderer *createRenderer(SDL_Window *screen, int *success);
void saveToBitmap(char *filename, SDL_Surface *toSave, int x, int y);