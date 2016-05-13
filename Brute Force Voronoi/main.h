//----------------------------------- HEADER FILES AND C PREPROCESSOR (MINUS #define)------------------------
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <jansson/jansson.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

//================================== CONSTANTS =============================

const static int SUCCESS = 0;
const static int FAIL = 1;
const static int MAX_COLOUR = 255;
const static double MACHINE_EPSILON = 0.00001;
const static int BIG_DISTANCE = 99999999;
const static int MAX_VERTEX = 100;
//================================== STRUCTURES ==============================

//optionsData : Holds all the options
typedef struct
{
	int SCREEN_WIDTH, SCREEN_HEIGHT, TILE_SIZE_X, TILE_SIZE_Y, NUMBER_VERTICES;
	char *WINDOW_TITLE;


}optionsData;


typedef struct//basically a duchy
{
	int x, y, linkedListSize;
	SDL_Texture *pointImg;
	SDL_Rect position;
	struct voronoiPointLinked *before,*after;
	char *duchyName;

}voronoiPointLinked;
typedef struct
{
	int duchyID, ownerID;
	SDL_Rect dimensions;
	int middleX, middleY, totalSize;
}acre;
typedef struct
{
	int noOfColours;
	SDL_Color **ownerColours;
}ownerColours;

//----------------------------------- FUNCTION PROTOTYPES ------------------------------------
//-----------INITIALISATION-----------
//loading libraries and the files themselves
char *loadTextFile(const char *filename, int *success);
int getFileSize(FILE *sizeToGet, int *success);
optionsData initOptions(char *fileContents, int *success);
SDL_Window *initSDL(optionsData *opt, int *success);
SDL_Renderer *createRenderer(SDL_Window *screen, int *success);
SDL_Texture *loadImage(const char *filename, SDL_Renderer *render, SDL_Rect *dimen, int *success);


voronoiPointLinked *createVoronoi(SDL_Texture *tex, SDL_Rect dimensions, int x, int y, int *success);
void addVoronoi(voronoiPointLinked *list,SDL_Texture *tex, SDL_Rect dimensions, int x, int y, int *success);
acre **createAcres(optionsData *opt, int *success);
ownerColours *createColours(int noColours, int *success);
void decideAcres(acre **acreArray, voronoiPointLinked *duchies);
int euclideanDistance(int x, int y, int dx, int dy);
void saveToBitmap(char *filename, SDL_Window *win, SDL_Renderer *rend, optionsData *opt);