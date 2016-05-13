#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif



//------------------------------ FUNCTIONS -----------------------------------
/*
	char *loadTextFile(const char *filename, int *success):
	Loads a file in a safe way and creates a string from it

*/

char *loadTextFile( const char *filename , int *success )
{

	fprintf( stderr , "Loading file %s... \n" , filename );
	int fileDescriptor, fileSize;
	char *fileContents;
	FILE *jsonFile;
	
	fileDescriptor = open( filename , O_RDONLY , 0600 );//avoids the race condition issues
	if( fileDescriptor == -1 )
	{
		fprintf( stderr , "open has failed on %s: %s \n" , filename , strerror( errno ) );
		*success = FAIL;
		return NULL;
	}
	
	jsonFile = fdopen( fileDescriptor , "rb" );
	if( !jsonFile )
	{
		fprintf( stderr , "fopen has failed : %s \n" , strerror( errno ) );
		*success = FAIL;
		return NULL;
	}
	fileSize = getFileSize( jsonFile , success );
	if( !fileSize )
	{
		return NULL;
	
	}
	fileContents = calloc( 1 , fileSize + 1 );
	if( !fileContents )
	{
		fprintf( stderr , "malloc has failed : %s" , strerror( errno ) );
		*success = FAIL;
		return NULL;
	
	}
	fread( fileContents , fileSize , 1 , jsonFile );
	fclose( jsonFile );
	if(strstr( fileContents , "%x" ) != NULL)
	{
		fprintf( stderr , "stack change formatter detected in file provided, nice try\n" );
		*success = FAIL;
		return NULL;
	
	}
	return fileContents;


}
/*
	int getFileSize(FILE *sizeToGet, int *success):
	Gets the size of a file

*/

int getFileSize( FILE *sizeToGet , int *success )
{
	fprintf( stderr , "Getting File size...\n" );
	int fileSize = 0;
	fseek( sizeToGet ,0 , SEEK_END );
	fileSize = ftell( sizeToGet );
	rewind( sizeToGet );//back to the start
	if(errno > 0)
	{
		fprintf( stderr , "ftell has failed : %s" , strerror( errno ) );
		*success = FAIL;
		return 0;
	}
	return fileSize;

}
/*
	optionsData *initOptions(char *fileContents, int *success):
	loads the options file in JSON to a optionsData structure

*/

optionsData initOptions( char *fileContents , int *success )
{
	fprintf( stderr , "Loading options... \n" );
	optionsData tempOpt;
	json_t *tempJsonHandle, *optionsData;
	json_error_t errorHandle;
	
	tempJsonHandle = json_loads( fileContents , 0 , &errorHandle );//loads the JSON file into Jansson 
	if( !tempJsonHandle )
	{
		fprintf( stderr , "json_loads has failed : %s \n" , errorHandle.text );
		*success = FAIL;
		return tempOpt;
	}
	
	optionsData = json_array_get( tempJsonHandle , 0 );
	if( !json_is_object(optionsData) )//makes sure that what is being opened is actually a JSON object
	{
		fprintf( stderr , "json_object_get failed, didn't get an object\n" );
		*success = FAIL;
		json_decref( tempJsonHandle );
		return tempOpt;
	
	}
	//gets the program options
	tempOpt.SCREEN_WIDTH = json_integer_value( json_object_get ( optionsData , "SCREEN_WIDTH" ) );
	tempOpt.SCREEN_HEIGHT = json_integer_value( json_object_get( optionsData , "SCREEN_HEIGHT" ) );
	tempOpt.TILE_SIZE_X = json_integer_value( json_object_get( optionsData , "TILE_SIZE_X" ) );
	tempOpt.TILE_SIZE_Y = json_integer_value( json_object_get( optionsData , "TILE_SIZE_Y" ) );
	tempOpt.NUMBER_VERTICES = json_integer_value( json_object_get( optionsData , "NUMBER_VERTICES" ) );
	tempOpt.WINDOW_TITLE = (char *)json_string_value( json_object_get( optionsData ,  "WINDOW_TITLE" ) );
	return tempOpt;
}

/*
	SDL_Window *initSDL(optionsData *opt, int *success):
	initialise SDL2 and associated library

*/

SDL_Window *initSDL( optionsData *opt , int *success )
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
	temp = SDL_CreateWindow( opt->WINDOW_TITLE , SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED , opt->SCREEN_WIDTH ,
	opt->SCREEN_HEIGHT , SDL_WINDOW_SHOWN );
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
	SDL_Texture *loadImage(const char *filename, SDL_Renderer *render, SDL_Rect *dimen, int *success):
	load an image, translates it to a hardware renderable texture and returns the original image's dimensions

*/
SDL_Texture *loadImage( const char *filename , SDL_Renderer *render , SDL_Rect *dimen , int *success )
{
	fprintf( stderr , "Loading image and converting it to texture from %s....\n" , filename );
	SDL_Surface *temp;
	SDL_Texture *tempTex;
	
	temp = IMG_Load( filename );//image library used to load things other than bitmaps
	if(!temp)
	{
		fprintf( stderr , "IMG_LoadBMP has failed: %s \n" , IMG_GetError() );
		*success = FAIL;
		return NULL;
	
	}
	SDL_SetColorKey( temp , SDL_TRUE , SDL_MapRGB( temp->format , 255 , 0 ,255 ) );//makes the background colour transparent
	tempTex = SDL_CreateTextureFromSurface( render , temp );//converts to renderable type
	if( !tempTex )
	{
		fprintf( stderr , "SDL_CreateTextureFromSurface has failed : %s \n" , SDL_GetError() );
		*success = FAIL;
		return NULL;
	}
	dimen->w = temp->w;
	dimen->h = temp->h;
	SDL_FreeSurface( temp );
	return tempTex;
}
/*
voronoiPointLinked *createVoronoi(SDL_Texture *tex, SDL_Rect dimensions, int *success)
Initialises a voronoi point list with 1 element

*/
voronoiPointLinked *createVoronoi(SDL_Texture *tex, SDL_Rect dimensions, int x, int y, int *success)
{
	voronoiPointLinked *temp = malloc(sizeof(voronoiPointLinked));
	if(!temp)
	{
		fprintf( stderr , "createVoronoi() Failed %s\n", strerror(errno) );
		*success = FAIL;
		return NULL;
	
	}
	temp->x = x;
	temp->y = y;
	temp->position = dimensions;
	temp->position.x = x;
	temp->position.y = y;
	temp->pointImg = tex;
	temp->linkedListSize = 1;
	

	return temp;
}
/*
	void addVoronoi(voronoiPointLinked *list,SDL_Texture *tex, SDL_Rect dimensions, int x, int y, int *success):
	
	Adds a point to the linked list

*/
void addVoronoi(voronoiPointLinked *list,SDL_Texture *tex, SDL_Rect dimensions, int x, int y, int *success)
{
	voronoiPointLinked *pointPos = list;
	while(pointPos->after != NULL)
	{
		pointPos = pointPos->after;
	}
	list->linkedListSize += 1;
	pointPos->after = createVoronoi(tex, dimensions, x, y, success);

}
/*
	acre **createAcres(optionsData *opt, int *success)
	
	Generates a grid of squares covering the whole screen/map

*/
acre **createAcres(optionsData *opt, int *success)
{

	int xDimension, yDimension, i, totalAcres, tempX, tempY;
	xDimension = opt->SCREEN_WIDTH / opt->TILE_SIZE_X;
	yDimension = opt->SCREEN_HEIGHT / opt->TILE_SIZE_Y;
	totalAcres = xDimension * yDimension;
	acre **temp = malloc(sizeof(acre *) * totalAcres);
	if(!temp)
	{
		fprintf( stderr , "createAcres() Failed %s\n", strerror(errno) );
		*success = FAIL;
		return NULL;
	
	}
	tempX = 0;
	tempY = 0;
	for(i = 0; i < totalAcres; i++)
	{
		
		temp[i] = malloc(sizeof(acre));
		temp[i]->duchyID = 0;
		temp[i]->ownerID = 0;
		temp[i]->dimensions.x = tempX * opt->TILE_SIZE_X;//spaces out correctly by size
		temp[i]->dimensions.y = tempY * opt->TILE_SIZE_Y;
		temp[i]->dimensions.w = opt->TILE_SIZE_X;
		temp[i]->dimensions.h = opt->TILE_SIZE_Y;
		temp[i]->totalSize = totalAcres;
		temp[i]->middleX = temp[i]->dimensions.x +  (opt->TILE_SIZE_X / 2);//finds the middle of the square not the corner
		temp[i]->middleY = temp[i]->dimensions.y +  (opt->TILE_SIZE_Y / 2);
		//goes along the x axis then down
		if(tempX < xDimension)
		{
			tempX++;
		
		}
		else if(tempY < yDimension)
		{
			tempX = 0;
			tempY++;
		}
	}

	return temp;
}

/*
ownerColours *createColours(int noColours, int *success)

Randomly generates a colour for each voronoi point (duchy)

*/
ownerColours *createColours(int noColours, int *success)
{
	int i;
	ownerColours *temp = malloc(sizeof(ownerColours));
	if(!temp)
	{
		fprintf( stderr , "createColours() Failed %s\n", strerror(errno) );
		*success = FAIL;
		return NULL;
	
	}
	temp->noOfColours = noColours;
	temp->ownerColours = malloc(sizeof(SDL_Color *) * noColours);
	for(i = 0; i < noColours; i++)
	{
		temp->ownerColours[i] = malloc(sizeof(SDL_Color));
		temp->ownerColours[i]->r = rand() % MAX_COLOUR + 1;
		temp->ownerColours[i]->g = rand() % MAX_COLOUR + 1;
		temp->ownerColours[i]->b = rand() % MAX_COLOUR + 1;
		temp->ownerColours[i]->a = rand() % MAX_COLOUR + 1;
	
	}
	return temp;
}
/*
void decideAcres(acre **acreArray, voronoiPointLinked *duchies)

This code makes me cringe as the time efficiency is O(DN) D = duchies, N = acres

Decides the voronoi diagram based on the positions of the duchy capitals

*/

void decideAcres(acre **acreArray, voronoiPointLinked *duchies)
{
	voronoiPointLinked *tempPoint;
	int favouredOwner, favouredDistance, newDistance ,i, j;
	
	for(i = 0; i < acreArray[0]->totalSize; i++)
	{
		tempPoint = duchies;
		favouredDistance = BIG_DISTANCE;
		favouredOwner = 0;
		j = 0;
		while(tempPoint)
		{
			newDistance = euclideanDistance(acreArray[i]->middleX, acreArray[i]->middleY, tempPoint->x, tempPoint->y);
			if(newDistance <= favouredDistance)//basically search for the closest by euclidean distance
			{
				favouredOwner = j;
				favouredDistance = newDistance;
			}
			j++;
			tempPoint = tempPoint->after;
		}
		acreArray[i]->duchyID = favouredOwner;
	}
}
/*
int euclideanDistance(int x, int y, int dx, int dy)

Generates the euclidean distance

*/
int euclideanDistance(int x, int y, int dx, int dy)
{
	double xComponent, yComponent, totalDistance;
	xComponent = x - dx;
	yComponent = y - dy;
	
	xComponent *= xComponent;
	yComponent *= yComponent;
	totalDistance = floor(sqrt(xComponent + yComponent));
	
	return (int)totalDistance;
	
}