#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Actions.h"
#include <stdbool.h>
#include "fightanimations.h"

//Character stats
struct character{
	int HP;
	int AW;
	int AW_EQP;
	int MW;
	int MW_EQP;
	int A_DEF;
	int M_DEF;
	int MAX_MANA;
	int MANA; 
};

int weaponboost=6;

 struct character player={100,22,2,16,0,11,6,8,8};
 struct character enemy={130,20,1,7,3,15,8,0,0};

int dmg, AI, reg;
bool win=false;
// zufallsgenerator initialisieren
	SDL_Event event;
int choice;
bool choicemade=false;
 void choice1 (){ 
			dmg = atk(player.AW,player.AW_EQP,enemy.A_DEF) ;
			playerAttackMove();
			printf("\n Ihr brutaler Schlag verursachte %d Schaden\n",dmg) ;
			enemy.HP -= dmg ;	
		}
		
		void choice2() { 
			if(player.HP<100 && player.MANA >= 3){
			reg = heal(player.MW,player.MW_EQP)	;
			player.HP += reg ;
			printf("\n Du klebst dir ein Pflaster auf die Backe und heilst dich um %d Leben\n", reg) ;
			player.MANA = player.MANA - 3 ;
		}
			// NICHT GENUG MANA ODER LEBEN
			else {
			if (player.HP >= 100) printf("\n Dein Leben ist schon voll, du Nimmersatt!!! \n") ;
			else {
				SDL_BlitSurface(gTextMana, NULL, gScreenSurface, &interfaceRect);
				SDL_UpdateWindowSurface(gWindow);
				SDL_Delay(2000);
				SDL_BlitSurface(gTextChoice, NULL, gScreenSurface, &interfaceRect);
				SDL_UpdateWindowSurface(gWindow);
			}
		}
		}
		
		
		void choice3(){
			if(player.MANA>=5){
			dmg = kame(player.MW,player.MW_EQP,enemy.M_DEF) ;
			playerSpell();
			printf("\n Du fokussierst dein Chi und verursachst %d Schaden \n", dmg) ; 
			enemy.HP-=dmg ;
			player.MANA-= 5 ;
			}
			
			// NICHT GENUG MANA 
			
			else{
				SDL_BlitSurface(gTextMana, NULL, gScreenSurface, &interfaceRect);
				SDL_UpdateWindowSurface(gWindow);
				SDL_Delay(2000);
				SDL_BlitSurface(gTextChoice, NULL, gScreenSurface, &interfaceRect);
				SDL_UpdateWindowSurface(gWindow);
			}		
		}
		
		void  surrender(){
			close();
			printf("Du hast aufgegeben.");
		}
		
bool fight(){
	srand(time(NULL));

	printf("Deine Leben : %d\n", player.HP);
	printf("Leben deines Gegners : %d\n", enemy.HP);
	
	printf("Dein Mana : %d\n", player.MANA);
	while ((player.HP || enemy.HP) > 0) {
	
		
		SDL_BlitSurface(gTextChoice, NULL, gScreenSurface, &interfaceRect);
		reloadFightOverlay();
		// Spieleraktionen
		
	
		while(choicemade==false){
			while( SDL_PollEvent( &event )){
					if((player.HP || enemy.HP) <1)
						break;
						//User requests quit
						switch( event.type ){
							//User wants to quit
							case SDL_QUIT:
									close();
							case SDL_KEYDOWN:
								switch(event.key.keysym.sym){
									case SDLK_ESCAPE:
										close();
										printf("Game closed by User");
										break;
									case SDLK_c:
										choice1();
										choicemade=true;
										break;
									case SDLK_v:
										choice2();
										choicemade=true;
										break;
									case SDLK_b:
										choice3();
										choicemade=true;
										break;
									case SDLK_n:
										surrender();
										break;
								}

							default:
									break;
			}
		}
			
			
			
		
			//Sieg Check
			if (enemy.HP<0) {
				printf("\n \t \t Sie haben gewonnen!\n") ;
				win=true;
				return(win) ;
				bossalive=false;
			}
			if(choicemade==true){
				//NPC-Aktionen
				AI = rand() %100 +1 ;
				
				if (AI<=70) { 
					dmg = atk(enemy.AW,enemy.AW_EQP,player.A_DEF) ;
					printf("\n Du kassierst durch einen fiesen Hieb %d Schaden o.O\n",dmg) ;
					player.HP -= dmg ;	
				}
				
				if (70<AI && AI<=90) { 
					if(enemy.HP<100){
					reg = heal(enemy.MW,enemy.MW_EQP)	;
					enemy.HP += reg ;
					printf("\n Dein Gegner versorgt seine Wunden und heilt sich um %d\n", reg) ;
					}
					else {
					dmg = atk(enemy.AW,enemy.AW_EQP,player.A_DEF) ;
					printf("\n Du kassierst durch einen fiesen Hieb %d Schaden o.O\n",dmg) ;
					player.HP -= dmg ;
					}
				}
						
			
				
				
				if (90<AI && AI<=100){
					dmg = kame(enemy.MW,enemy.MW_EQP,player.M_DEF) ;
					player.HP -= dmg ; 
					printf("\n Der heftige Energieangriff des Gegners entzieht dir %d Lebenspunkte \n", dmg) ;
				}	
				
				//Niederlagencheck
				if (player.HP<0) {
				printf("\n \t \t Sie haben verloren!\n") ;
				return(win);
				}
				//Manaregeneration
				if(player.MANA<player.MAX_MANA)
					player.MANA++;
				
				printf("Deine Leben : %d\n", player.HP);
				printf("Leben deines Gegners : %d\n", enemy.HP);
				printf("Dein Mana : %d\n", player.MANA);
				
				playerHPbarRect.w=player.HP*2;
				enemyHPbarRect.w=enemy.HP*2;
				
			}
			
			choicemade=false;
		}
		}
}



