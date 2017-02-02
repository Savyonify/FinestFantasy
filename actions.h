#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include "libBMP.h"

#define BLACK 0x00000000
#define GREEN 0x0000FF00
#define BLUE  0x000000FF

// Erstellt Spieler HP Anzeige

void HPbar(int HP) {

  int bmp_height = 30;
  int bmp_width = 5 * HP;

  uint32_t *data = (uint32_t*) malloc (bmp_height * bmp_width * sizeof(uint32_t)) ;

  for (int y = 0; y <= bmp_height; y++) {
    for (int x = 0; x <= bmp_width; x++) {
      if ( x == 0 || x == bmp_width || y == 0 || y == bmp_height ) bmp_set_pixel(data, bmp_width, bmp_height, x, y, BLACK);
	  else bmp_set_pixel(data, bmp_width, bmp_height, x, y, GREEN);
    }
  }

  bmp_create("images/HPbar.bmp", data, bmp_width, bmp_height); 


  free(data) ;

}

//Erstellt Mana Anzeige

void Manabar(int MA) {

  int bmp_height = 30;
  int bmp_width = 5 * MA;

  uint32_t *data = (uint32_t*) malloc (bmp_height * bmp_width * sizeof(uint32_t)) ;

  for (int y = 0; y < bmp_height; y++) {
    for (int x = 0; x < bmp_width; x++) {
      if ( x == 0 || x == bmp_width || y == 0 || y == bmp_height ) bmp_set_pixel(data, bmp_width, bmp_height, x, y, BLACK);
	  else bmp_set_pixel(data, bmp_width, bmp_height, x, y, BLUE);
    }
  }

  bmp_create("images/HPbar.bmp", data, bmp_width, bmp_height); 


  free(data) ;

}

// Erstellt Gegner HP Anzeige

void HPEbar(int HPE) {

  int bmp_height = 30;
  int bmp_width = 5 * HPE;

  uint32_t *data = (uint32_t*) malloc (bmp_height * bmp_width * sizeof(uint32_t)) ;

  for (int y = 0; y < bmp_height; y++) {
    for (int x = 0; x < bmp_width; x++) {
      if ( x == 0 || x == bmp_width || y == 0 || y == bmp_height ) bmp_set_pixel(data, bmp_width, bmp_height, x, y, BLACK);
	  else bmp_set_pixel(data, bmp_width, bmp_height, x, y, GREEN);
    }
  }

  bmp_create("images/HPEbar.bmp", data, bmp_width, bmp_height); 


  free(data) ;

}

//Berechnet Schaden einer Attacke
int atk(int AW,int AW_EQP,int A_DEFE) {
	srand(time(NULL));
	int luck = (rand()%50 + 75)/100;
	int dmg = (AW + AW_EQP) * 5 * luck / A_DEFE ;
return (dmg) ;
}

//Berechnet die Heilung 

int heal(int MW,int MW_EQP) {
	return ( 1.4*(MW+MW_EQP) ) ;
}

//Berechnet Schaden durch kamehameha

int kame(int MW,int MW_EQP,int M_DEFE) {
	return ( (MW+MW_EQP) * 15/ M_DEFE );
}