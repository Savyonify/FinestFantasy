#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "media.h"

//Properties of main screen
const int SCREEN_HEIGHT = 750;
const int SCREEN_WIDTH = 999;

// boolean variables
bool quit = false;
bool chestopen=false;
bool portalused=false;
bool direction=false;   // Left or Right, left = true, right=false;
bool fightstarted=false;
bool loadMedia();
bool bossalive=true;
bool swordtaken=false;



//Key event 

SDL_Event e;


bool init (){
	bool success= true;
	
	//SDL initialisieren
	if( SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not be initialized! SDL Error : \n %s", SDL_GetError());
		success=false;
	}
	else {
		
		//Create window
		gWindow = SDL_CreateWindow("Finest Fantasy",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
		if (gWindow==NULL){
			printf("Window could not be initialized! SDL Error : \n %s", SDL_GetError());
			success=false;
		}
		else{
			//Get window Surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}	
	
	
	
	return success;
}
void close(){
	SDL_FreeSurface(gBackground);
	gBackground =NULL;
	SDL_FreeSurface(gSpriteLeft);
	gSpriteLeft=NULL;
	SDL_FreeSurface(gSpriteRight);
	gSpriteRight=NULL;
	SDL_FreeSurface(gChest);
	gChest=NULL;
	SDL_FreeSurface(gOpenChest);
	gOpenChest=NULL;
	SDL_FreeSurface(gCave);
	gCave=NULL;
	SDL_FreeSurface(gPortal);
	gPortal=NULL;
	SDL_FreeSurface(gBossSprite);
	gBossSprite=NULL;
	SDL_FreeSurface(gFightScreen);
	gFightScreen=NULL;
	SDL_FreeSurface(gSpriteFight);
	gSpriteFight=NULL;
	SDL_DestroyWindow(gWindow);
	gWindow=NULL;
	SDL_FreeSurface(gFireBall);
	gFireBall=NULL;
	SDL_FreeSurface(gInterface);
	gInterface=NULL;
	SDL_FreeSurface(gTextChest);
	gTextChest=NULL;
	SDL_FreeSurface(gTextBlock);
	gTextBlock=NULL;
	SDL_FreeSurface(gTextBox);
	gTextBox=NULL;
	SDL_FreeSurface(gTextSword);
	gTextSword=NULL;
	SDL_FreeSurface(gTextStartFight);
	gTextStartFight=NULL;
	SDL_FreeSurface(gTextChoice);
	gTextChoice=NULL;
	SDL_FreeSurface(gTextPortal);
	gTextPortal=NULL;
	SDL_FreeSurface(gTextPortal2);
	gTextPortal2=NULL;
	SDL_FreeSurface(gTextEnemyAtk);
	gTextEnemyAtk=NULL;
	SDL_FreeSurface(gTextEnemySpz);
	gTextEnemySpz=NULL;
	SDL_FreeSurface(gTextEnemyHeal);
	gTextEnemyHeal=NULL;
	SDL_FreeSurface(gTextEmpty);
	gTextEmpty=NULL;
	SDL_FreeSurface(gTextVictory);
	gTextVictory=NULL;
	SDL_FreeSurface(gSpriteFightLeft);
	gSpriteFightLeft=NULL;
	SDL_FreeSurface(gTextAtk);
	gTextAtk=NULL;
	SDL_FreeSurface(gTextSpz);
	gTextSpz=NULL;
	SDL_FreeSurface(gTextMana);
	gTextMana=NULL;
	SDL_FreeSurface(gHPbar);
	gHPbar=NULL;
	SDL_Quit();
}