#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "position.h"
#include "fight.c"




void reloadOverlay(){
	SDL_BlitSurface(gTextEmpty, NULL, gScreenSurface, &interfaceRect);

	//Areaabhängigkeit 
	if(fightstarted==false){
		if(portalused==false){
			SDL_BlitSurface(gBackground, NULL,gScreenSurface, NULL);
			SDL_BlitSurface(gPortal, NULL,gScreenSurface, &portalRect);
			//Chestabhängigkeit
			if(chestopen==false){
				SDL_BlitSurface(gChest, NULL,gScreenSurface, &chestRect);
				if(position[0]>116 && position[0]<119  && position[1]>128 && position[1]<131)
						SDL_BlitSurface(gTextPortal2, NULL, gScreenSurface, &interfaceRect);
			}
			else{
				if(swordtaken==true){
				SDL_BlitSurface(gOpenChest, NULL, gScreenSurface, &chestRect);
				SDL_BlitSurface(gTextSword, NULL, gScreenSurface, &interfaceRect);
				}
				else{
					SDL_BlitSurface(gOpenChest, NULL, gScreenSurface, &chestRect);
					SDL_BlitSurface(gTextChest, NULL, gScreenSurface, &interfaceRect);
					
					//Extrabedingung für stehen auf dem Portal ohne schwert
					if(position[0]>116 && position[0]<119  && position[1]>128 && position[1]<131)
						SDL_BlitSurface(gTextPortal2, NULL, gScreenSurface, &interfaceRect);
				}
			}
		}
		else{
			SDL_BlitSurface(gCave, NULL, gScreenSurface, NULL);
			
			if(position[0]==108 && bossalive==true)
				SDL_BlitSurface(gTextBlock, NULL, gScreenSurface, &interfaceRect);
			else
				SDL_BlitSurface(gTextPortal, NULL, gScreenSurface, &interfaceRect);
		
			if(bossalive==true)
				SDL_BlitSurface(gBossSprite, &fromBossRect, gScreenSurface, &bossRect);
			else
				SDL_BlitSurface(gTextVictory, NULL, gScreenSurface, &interfaceRect);
		}
		if(direction==true){
			if(portalused==true) SDL_BlitSurface(gSpriteFightLeft, NULL,gScreenSurface, &spriteRect);
			if(portalused==false) SDL_BlitSurface(gSpriteLeft, NULL, gScreenSurface, &spriteRect);
		}
		if(direction==false){
			if(portalused==true) SDL_BlitSurface(gSpriteFight, NULL, gScreenSurface, &spriteRect);
			if(portalused==false) SDL_BlitSurface(gSpriteRight, NULL, gScreenSurface, &spriteRect);
		}
	}
	else {
		SDL_BlitSurface(gFightScreen, NULL,gScreenSurface, NULL);
		SDL_BlitSurface(gSpriteFight, NULL, gScreenSurface, &spriteFightRect);
		SDL_BlitSurface(gBossSprite, &fromBossRect, gScreenSurface, &bossFightRect);
		SDL_BlitSurface(gTextStartFight, NULL, gScreenSurface, &interfaceRect);
	}
}          

                                         
void moveLeft(){
	//Bewegung nach links 
	if(fightstarted==false){
		if(portalused==false){
			if (position[0]>4)
				position[0]--;
			spriteRect.x=7*position[0];
			direction=true;
		}
		else{
			if (position[0]>0)
				position[0]--;
			spriteRect.x=7*position[0];
			direction=true;
		}
	}
}

void moveRight(){
	//Bewegung nach rechts
	if(fightstarted==false){
		if(portalused==false){	
			if(position[0]<136)
				position[0]++;
			spriteRect.x=7*position[0];
			direction=false;
		}
		else{
			if(position[0]==108 && bossalive==true){
				printf("Die Macht des boesen Erzmagiers Bangalunka blockiert den Weg.");
			}
			else {
				if(position[0]<139)
					position[0]++;
				else{
					printf("Sie haben gewonnen ! \n Credits : Markus Mutas & Felix Lorenz \n");
					close();
				}
			}
			spriteRect.x=7*position[0];
			direction=false;
		}
		
	}
}

void moveUp(){
	//Bewegung nach oben hat auf der oberen Ebene ein größeres Areal als im unteren.
	if(fightstarted==false){
		if(portalused==false){
			if(position[1]>8)
				position[1]--;
			spriteRect.y=3*position[1];
		}
		else{
			if(position[1]>165)
				position[1]--;
			spriteRect.y=3*position[1];
		}
	}
}

void moveDown(){
	//Bewegung nach unten
	if(fightstarted==false){
		if(portalused==false){
			if(position[1]<170)
				position[1]++;
			spriteRect.y=3*position[1];
		}
		else{
			if(position[1]<181)
				position[1]++;
			spriteRect.y=3*position[1];
		}
	}
}

void interact(){
	if(fightstarted==true){
		if(fight()){
			fightstarted=false;	
			bossalive=false;
		}
		else{
			printf("Game Over");
			close();
		}
	}
	else{
		if(portalused==false){
			if(position[0]>116 && position[0]<120 && position[1]>48 && position[1]<52){
				if(chestopen==true && swordtaken==false){ 
					swordtaken=true;
					player.AW_EQP+=weaponboost;
				}
				if(chestopen==false){
					printf("Truhe geoeffnet.\nDu siehst Elguni, das legendaere Schwert des Portalmeisters, was zufaelligerweise einen \nPortalstein in seine Klinge eingearbeitet hat ");
					printf("und zusaetzlich noch zufaelligerweise unbewacht in dieser Truhe liegt. Möchtest du Elguni an dich nehmen? Interagiere erneut mit der Truhe um es an dich zu nehmen.\n");
					chestopen=true;
				}
				
			}
			

			//Höhle betreten
			if(position[0]>116 && position[0]<119  && position[1]>128 && position[1]<131  ){
				if(swordtaken==true){
					portalused=true;
					position[0]=0;
					position[1]=173;
					spriteRect.y=3*position[1];
					spriteRect.x=7*position[0];
					reloadOverlay();
				}
			}				
		}
		else{
			//Kampf starten 
			if(position[0]==108 && bossalive==true){
				fightstarted=true;
				reloadFightOverlay();
			}
			
		}
	
	}
}






int main(int argc, char* args[]){
	//Start up SDL
	
	if (!init())
		printf("Failed to initialize!\n");
	else {
		
		 
	
			
		//Load Media
		if(!loadMedia(2))
			printf("Failed to load media!\n");
		else{
			//Apply the Image
			SDL_BlitSurface(gBackground, NULL,gScreenSurface, NULL);
		
		
		while(!quit){
		                          
		while( SDL_PollEvent( &e ) != 0 ){
                    //User requests quit
                    switch( e.type ){
						//User wants to quit
						case SDL_QUIT:
								close();
						case SDL_KEYDOWN:
							switch(e.key.keysym.sym){
								//Escape to quit 
								case SDLK_ESCAPE:
									close();
									break;
								case SDLK_LEFT:
									moveLeft();
									break;
								case SDLK_RIGHT:
									moveRight();
									break;
								case SDLK_UP:
									moveUp();
									break;
								case SDLK_DOWN:
									moveDown();
									break;
								case SDLK_f:
									interact();
									break;
								case SDLK_o:
									fightstarted=true;
									break;
							}

						default:
								break;
    }
			//Update the imageSurface
			reloadOverlay();
			SDL_UpdateWindowSurface(gWindow);

		}
		
		}
	}
	
	close();
	return 0;
}
}