#include "mes_fonctions.h"

int main(void)
{
	float x;
	float y;
	int resul;
	int sortie;
	int valeur;
	int sousmenu;
	int tmp;
	int longueurValeurs;
	int longueurEquation;
	longueurValeurs = DIM;
	tableau valeurs;
	tableau resultats;
	tableau equation;
	tableau derive;
	do
	{
		affiche_menu();
		valeur = lisEntier();
		switch (valeur)
		{

			case 1:
			saisieValeurs(valeurs, longueurValeurs);
			resul = verifValeurs(longueurValeurs, valeurs);
			if(resul != 0){
				affiche_erreur(resul);
				break;
			}
			tmp = valeurs[4];
			valeurs[4] = deg2Rad(tmp);
			longueurEquation = val2eq(equation, valeurs, longueurValeurs);
			x = zeroLongueur(equation);
			derivee(equation, derive, longueurEquation);
			y = zeroHauteur(equation, derive, resultats);
			resultats[0] = x;
			resultats[1] = y;
			do
			{
				affiche_menuResu();
				sousmenu = lisEntier();
				switch (sousmenu)
				{

					case 1:
						affiche_valeurs(1, 2, resultats);
						sortie = 0;
					break;
					case 2:
						affiche_valeurs(2, 2, resultats);
						sortie = 0;
					break;
					case 3:
						affiche_valeurs(3, 2, resultats);
						sortie = 0;
					break;

					default:
					ecrisChaine( "  Valeur erronee \n") ;
				}
			}
			while ( sortie != 0 );

			break;

			case 0:
			valeur = 0 ;
			break;
			default:
			ecrisChaine( "  Valeur erronee \n") ;
		}
	}
	while ( valeur != 0 );


	exit(0);
}
