#include <string.h>
#include <SDL.h>
#include "rects.h"
#include "prop.h"

	
void reloadFightOverlay(){
	SDL_BlitSurface(gFightScreen, NULL, gScreenSurface, NULL);
	SDL_BlitSurface(gBossSprite, &fromBossRect, gScreenSurface, &bossFightRect);
	SDL_BlitSurface(gSpriteFight, NULL, gScreenSurface, &spriteFightRect);
	SDL_BlitSurface(gTextChoice, NULL, gScreenSurface, &interfaceRect);
	//SDL_BlitSurface(gHPbar, NULL, gScreenSurface, &playerHPbarRect);
	//SDL_BlitSurface(gHPbar, NULL, gScreenSurface, &enemyHPbarRect);
	SDL_UpdateWindowSurface(gWindow);
}
void reloadFightOverlayAttack(){
	SDL_BlitSurface(gFightScreen, NULL, gScreenSurface, NULL);
	SDL_BlitSurface(gBossSprite, &fromBossRect, gScreenSurface, &bossFightRect);
	SDL_BlitSurface(gSpriteFight, NULL, gScreenSurface, &spriteFightRect);
	SDL_BlitSurface(gTextAtk, NULL, gScreenSurface, &interfaceRect);
	//SDL_BlitSurface(gHPBar, NULL, gScreenSurface, &playerHPbarRect);
	//SDL_BlitSurface(gHPEBar, NULL, gScreenSurface, &enemyHPbarRect);
	SDL_UpdateWindowSurface(gWindow);
}

void reloadFightOverlaySpell(){
	SDL_BlitSurface(gFightScreen, NULL, gScreenSurface, NULL);
	SDL_BlitSurface(gBossSprite, &fromBossRect, gScreenSurface, &bossFightRect);
	SDL_BlitSurface(gSpriteFight, NULL, gScreenSurface, &spriteFightRect);
	SDL_BlitSurface(gTextSpz, NULL, gScreenSurface, &interfaceRect);
	SDL_BlitSurface(gFireBall, NULL, gScreenSurface, &fireBallRect);
	SDL_UpdateWindowSurface(gWindow);
}

void playerAttackMove(){
	for(int i=0; i<100; i++){
		spriteFightRect.x+=2;
		reloadFightOverlayAttack();
		SDL_Delay(5);
	}
	spriteFightRect.x=spriteFightRect.x-200;
	reloadFightOverlay();
	SDL_UpdateWindowSurface(gWindow);
	
}

void playerSpell(){
	for(int i=0; i<100; i++){
		fireBallRect.x+=2;
		reloadFightOverlaySpell();
		SDL_Delay(5);
	}
	fireBallRect.x=fireBallRect.x-200;
	reloadFightOverlay();
	SDL_UpdateWindowSurface(gWindow);
}