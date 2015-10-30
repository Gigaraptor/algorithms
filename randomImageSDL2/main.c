#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif

int main(int argc, char *argv[])
{
	SDL_Window *wind;
	SDL_Renderer *rend;
	grad **gradients;
	SDL_Event end;
	int x,y,z;
	char filename[70];
	int success = SUCCESS;
	srand(time(NULL));
	wind = init(&success);
	rend = createRenderer(wind, &success);
	gradients = generateRandomGradients();
	z = 0;
	while(success == SUCCESS)
	{
		srand(time(NULL));
	
		
		for(x = 0; x < SCREEN_WIDTH - 2; x++)
		{
			for(y = 0; y < SCREEN_HEIGHT - 2; y++)
			{
				drawPlasma(x,y,gradients,rend);
				while(SDL_PollEvent(&end) != 0 )
				{
					if(end.type == SDL_QUIT)
					{
						success = FAIL;
						break;
					}	
		
				}
			}
			
			if(end.type == SDL_QUIT)
			{
					success = FAIL;
					break;
			}
		}
		SDL_RenderPresent(rend);
		free(gradients);
		gradients = generateRandomGradients();
		sprintf(filename, "Output %d.bmp", z);
		saveToBitmap(filename, wind, rend);
		z++;
	}
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(wind);
	free(gradients);
	SDL_Quit();
	return 0;
}