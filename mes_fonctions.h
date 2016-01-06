// .h necessaires a l'application
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ESLib.h"
#include <math.h>
#define DIM 6
typedef float tableau[DIM];

void affiche_menu(void);

void affiche_menuResu(void);

float deg2Rad(float);

int verifValeurs(int, tableau);

void affiche_erreur(int);

void affiche_valeurs(int, int, float, tableau);

int saisieValeurs(tableau, int);

int afficheTableau(tableau, int);

void affiche_menuG(void);

int val2eq(tableau equation, tableau valeurs, int longueurValeurs);

float zeroLongueur(tableau);

float zeroHauteur(tableau, tableau, tableau);

int derivee(tableau equation, tableau derive, int longueurEquation);