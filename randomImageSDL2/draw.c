#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif



float lerp(int x, int y, int t)
{
	float lerpd;
	lerpd = (1-t)*x + t*y;
	return lerpd;


}

float perlin(int x, int y, grad **Gradients)
{
	int perld;
	int x1, y1;
	float prod0, prod1, final0, final1;
	x1 = x + 1;
	y1 = y + 1;
	
	prod0 = getDotProduct(x,y, Gradients);
	prod1 = getDotProduct(x1,y, Gradients);
	final0 = lerp(prod0, prod1, (float)x + (float)rand()/(float) RAND_MAX);
	prod0 = getDotProduct(x,y1, Gradients);
	prod1 = getDotProduct(x1,y1, Gradients);
	final1 = lerp(prod0, prod1, (float)x + (float)rand()/(float) RAND_MAX);
	
	perld = lerp(final0, final1, (float)rand()/(float) RAND_MAX);
	return perld;
}

float getDotProduct(int x, int y, grad **Gradients)
{
	float dy,dx;
	
	dy = y - ((float)rand()/(float) RAND_MAX);
	dx = x - ((float)rand()/(float) RAND_MAX);
	
	return (dx * Gradients[x][y].x + dy * Gradients[x][y].y);


}

void drawPlasma(int x, int y, grad **Gradients, SDL_Renderer *rend)
{
	Uint8 r,g,b;
	r = sin(perlin(x,y,Gradients)) * MAX;
	g = cos(perlin(x,y,Gradients)) * MAX;
	b = (1/ sin(perlin(x,y,Gradients))) * MAX;//cosec
	SDL_SetRenderDrawColor(rend,r,g,b,0);
	SDL_RenderDrawPoint(rend,x,y);
}
grad **generateRandomGradients()
{
	grad **temp = malloc(sizeof(grad *) * SCREEN_WIDTH);
	int looper, secondLooper;
	for(looper = 0; looper < SCREEN_WIDTH; looper++)
	{
		temp[looper] = malloc(sizeof(grad) * SCREEN_HEIGHT);
		for(secondLooper = 0; secondLooper < SCREEN_HEIGHT; secondLooper++)
		{
			temp[looper][secondLooper].x = (float)rand()/(float) RAND_MAX;
			temp[looper][secondLooper].y = (float)rand()/(float) RAND_MAX;
			
		}
	
	}

	return temp;

}