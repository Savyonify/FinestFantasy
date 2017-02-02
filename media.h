#include <stdbool.h>

//ALL SDL DECLARATIONS 
// The Window we will render to
SDL_Window *gWindow=NULL;
// The surface of the window
SDL_Surface * gScreenSurface = NULL;
//The Image we will load 
SDL_Surface* gBackground = NULL;
SDL_Surface* gSpriteLeft = NULL;
SDL_Surface* gSpriteRight = NULL;
SDL_Surface* gCave= NULL;
SDL_Surface* gPortal= NULL;
SDL_Surface* gFireball= NULL;
SDL_Surface* gChest =NULL;
SDL_Surface* gOpenChest=NULL;
SDL_Surface* gBossSprite=NULL;
SDL_Surface* gFightScreen=NULL;
SDL_Surface* gSpriteFight=NULL;
SDL_Surface* gFireBall=NULL;
SDL_Surface* gInterface=NULL;
SDL_Surface* gTextChest=NULL;
SDL_Surface* gTextMana=NULL;
SDL_Surface* gTextBlock=NULL;
SDL_Surface* gTextSword=NULL;
SDL_Surface* gTextBox=NULL;
SDL_Surface* gTextPortal=NULL;
SDL_Surface* gTextPortal2=NULL;
SDL_Surface* gTextStartFight=NULL;
SDL_Surface* gTextEnemyAtk=NULL;
SDL_Surface* gTextEnemyHeal=NULL;
SDL_Surface* gTextEnemySpz=NULL;
SDL_Surface* gTextVictory=NULL;
SDL_Surface* gTextGO=NULL;
SDL_Surface* gTextEmpty=NULL;
SDL_Surface* gTextChoice=NULL;
SDL_Surface* gSpriteFightLeft=NULL;
SDL_Surface* gTextAtk=NULL;
SDL_Surface* gTextSpz=NULL;
SDL_Surface* gHPbar=NULL;
 

bool loadMedia(){
	
	bool success=true;
	
	
	gHPbar=SDL_LoadBMP("images/hpbar.bmp");
	if(gHPbar==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	//Backgroundsprite
	
	gBackground=SDL_LoadBMP("images/firstarea.bmp");
	if (gBackground == NULL){
				printf("Error : \n %s", SDL_GetError());
				success=false;
	}	
	//Cavesprite
	gCave=SDL_LoadBMP("images/cavesprite.bmp");
	if(gCave==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	//Charactersprite
	gSpriteLeft=SDL_LoadBMP("images/spriteleft.bmp");
	if(gSpriteLeft==NULL){
				printf("Error : \n %s", SDL_GetError());
				success=false;
	}
	gSpriteRight=SDL_LoadBMP("images/spriteright.bmp");
	if(gSpriteRight==NULL){
				printf("Error : \n %s", SDL_GetError());
				success=false;
	}
	
	gSpriteFight=SDL_LoadBMP("images/spritefight.bmp");
	if(gSpriteFight==NULL){
				printf("Error : \n %s", SDL_GetError());
				success=false;
	}
	
	//Chestsprite
	gChest=SDL_LoadBMP("images/chest.bmp");
	if(gChest==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gOpenChest=SDL_LoadBMP("images/openchest.bmp");
	if(gOpenChest==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	//Portalsprite
	gPortal=SDL_LoadBMP("images/portalsprite.bmp");
	if(gPortal==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	
	
	gBossSprite=SDL_LoadBMP("images/bosssprite.bmp");
	if(gBossSprite==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gFightScreen=SDL_LoadBMP("images/fightscreen.bmp");
	if(gFightScreen==NULL){
		printf("Error : \n &s", SDL_GetError());
		success=false;
	}
	
	
	gFireBall=SDL_LoadBMP("images/fireball.bmp");
	if(gFireBall==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gInterface=SDL_LoadBMP("images/interface.bmp");
	if(gInterface==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextChest=SDL_LoadBMP("images/textChest.bmp");
	if(gTextChest==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextBox=SDL_LoadBMP("images/textBox.bmp");
	if(gTextBox==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	gTextBlock=SDL_LoadBMP("images/textBlock.bmp");
	if(gTextBlock==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	gTextPortal=SDL_LoadBMP("images/textPortal.bmp");
	if(gTextPortal==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextPortal2=SDL_LoadBMP("images/textPortal2.bmp");
	if(gTextPortal2==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextSword=SDL_LoadBMP("images/textSword.bmp");
	if(gTextSword==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	gTextStartFight=SDL_LoadBMP("images/textStartFight.bmp");
	if(gTextStartFight==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	gTextChoice=SDL_LoadBMP("images/textChoice.bmp");
	if(gTextChoice==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextEnemyAtk=SDL_LoadBMP("images/textEnemyAtk.bmp");
	if(gTextEnemyAtk==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextEnemySpz=SDL_LoadBMP("images/textEnemySpz.bmp");
	if(gTextEnemySpz==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextEnemyHeal=SDL_LoadBMP("images/textEnemyHeal.bmp");
	if(gTextEnemyHeal==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextVictory=SDL_LoadBMP("images/textVictory.bmp");
	if(gTextVictory==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextGO=SDL_LoadBMP("images/textGO.bmp");
	if(gTextGO==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextEmpty=SDL_LoadBMP("images/textEmpty.bmp");
	if(gTextEmpty==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gSpriteFightLeft=SDL_LoadBMP("images/spriteFightLeft.bmp");
	if(gSpriteFightLeft==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextAtk=SDL_LoadBMP("images/textAtk.bmp");
	if(gTextAtk==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextSpz=SDL_LoadBMP("images/textSpz.bmp");
	if(gTextSpz==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	gTextMana=SDL_LoadBMP("images/textMana.bmp");
	if(gTextMana==NULL){
		printf("Error : \n %s", SDL_GetError());
		success=false;
	}
	
	
	return success;
}



