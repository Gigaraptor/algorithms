#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif

/*
void drawVonoroi(voronoiPointLinked *points, SDL_Renderer *render)
what it says

*/
void drawVonoroi(voronoiPointLinked *points, SDL_Renderer *render)
{
	voronoiPointLinked *tempPoint = points;
	while(tempPoint)
	{
		SDL_RenderCopy(render, tempPoint->pointImg, NULL, &tempPoint->position);
		tempPoint = tempPoint->after;//travels down the linked list
	}
	
}
/*
void drawAcres(acre **acreArray, ownerColours *duchyColours,  SDL_Renderer *render)
what it says

*/
void drawAcres(acre **acreArray, ownerColours *duchyColours,  SDL_Renderer *render)
{
	int i, oldDuchy;
	oldDuchy = 0;
	for(i = 0; i < acreArray[0]->totalSize; i++)
	{
		if(acreArray[i]->duchyID != oldDuchy)//hopefully should speed up rendering a wee bit
		{
			oldDuchy = acreArray[i]->duchyID;
			SDL_SetRenderDrawColor(render, duchyColours->ownerColours[acreArray[i]->duchyID]->r,duchyColours->ownerColours[acreArray[i]->duchyID]->g,duchyColours->ownerColours[acreArray[i]->duchyID]->b,
			duchyColours->ownerColours[acreArray[i]->duchyID]->a);//changes to the valid duchy
		
		}
		SDL_RenderFillRect(render, &acreArray[i]->dimensions);
	
	}

}