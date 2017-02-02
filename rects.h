#include <SDL.h>
//Charactersprite rectangle
SDL_Rect spriteRect={23*7,49*3,142,192};

//CaveEntry rectangle
SDL_Rect portalRect={116*7,128*3,100,100};

//Chest rectangle
SDL_Rect chestRect={117*7,49*3,150,150};

//Bosssprite rectangle
SDL_Rect bossRect={110*7, 172*3, 142,50};
SDL_Rect fromBossRect={225,50, 100,50};

//Interface rectangle 
SDL_Rect interfaceRect={0, 571, 999,179};

// Fight rectangles 
SDL_Rect spriteFightRect={53*7, 92*3, 142,50};

SDL_Rect fireBallRect={53*7, 92*3, 142,50};
SDL_Rect bossFightRect= {82*7, 92*3, 142,50};

SDL_Rect playerHPbarRect={320,300,2,5};
SDL_Rect enemyHPbarRect={600,300,200,5};