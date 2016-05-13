#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif


int main(int argc, char* argv [])
{
	char *optionsText;
	optionsData opt;
	SDL_Window *win;
	SDL_Renderer *render;
	int isSuccess = SUCCESS;
	int i;
	SDL_Texture *pointImage;
	SDL_Rect pointPosition;
	SDL_Event events;
	voronoiPointLinked *points;
	acre **acreData;
	ownerColours *duchyColours;
	
	//Creates windows
	srand(time(NULL));
	optionsText = loadTextFile("options.json", &isSuccess);
	opt = initOptions(optionsText, &isSuccess);
	win = initSDL(&opt, &isSuccess);
	render = createRenderer(win, &isSuccess);
	pointImage = loadImage("point.bmp", render, &pointPosition, &isSuccess);
	
	//Initialises the voronoi points
	points = createVoronoi(pointImage, pointPosition, 500, 500, &isSuccess);
	for(i = 0; i < opt.NUMBER_VERTICES; i++)
	{
		addVoronoi(points, pointImage, pointPosition, rand() % opt.SCREEN_WIDTH, rand() % opt.SCREEN_HEIGHT, &isSuccess);
	
	}
	
	//handling the other squares
	acreData = createAcres(&opt, &isSuccess);
	duchyColours = createColours(points->linkedListSize, &isSuccess);
	decideAcres(acreData, points);
	
	while(isSuccess == SUCCESS)
	{
		while(SDL_PollEvent(&events))//allows users to save the image and quit
		{
			if(events.type == SDL_QUIT)
			{
				isSuccess = FAIL;
			
			}
			else if(events.type = SDL_MOUSEBUTTONDOWN)
			{
				saveToBitmap("Output.bmp", win, render, &opt);
			
			}
		
		}
		drawAcres(acreData, duchyColours, render);//draws squares
		drawVonoroi(points, render);//draws points
		SDL_RenderPresent(render);
	
	}
	
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	
	return SUCCESS;
}