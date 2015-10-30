#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

static const int SUCCESS = 0;
static const int FAIL = 1;
static const MAX = 255;
static const SCREEN_WIDTH = 1280;
static const SCREEN_HEIGHT = 720;
typedef struct
{
	float x, y;

}grad;
SDL_Window *init(int *isSuccess);
SDL_Renderer *createRenderer(SDL_Window *win, int *isSuccess);


float lerp(int x, int y, int t);
float perlin(int x, int y, grad **Gradients);
float getDotProduct(int x, int y, grad **Gradients);
grad **generateRandomGradients();

void saveToBitmap(char *filename, SDL_Window *win, SDL_Renderer *rend);
