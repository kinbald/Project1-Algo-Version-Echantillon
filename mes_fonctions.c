#include "mes_fonctions.h"

void affiche_menu(void)
{
	ecrisChaine("\t Entrez un choix \n");
	ecrisChaine("\t1  --> Saisie des valeurs \n");
	ecrisChaine("\t0  --> Pour Quitter \n");
}


void affiche_menuResu(void)
{
	ecrisChaine("Quel resultat souhaitez-vous avoir ? \n");
	ecrisChaine("\t1  --> Point de chute seulement \n");
	ecrisChaine("\t2  --> Point de hauteur maximale seul \n");
	ecrisChaine("\t3  --> Point de chute et point de hauteur maximale \n");
}
//Saisie des valeurs
int saisieValeurs(tableau valeurs, int longeurValeurs){
	float masse;
	ecrisChaine("[ MASSE ] Entrez la valeur de la masse :");
	masse = lisFlottant();
	valeurs[0] = masse;

	float Xo;
	ecrisChaine("[ Xo ] Entrez la valeur de la Xo :");
	Xo = lisFlottant();
	valeurs[1] = Xo;

	float Yo;
	ecrisChaine("[ Yo ] Entrez la valeur de la Yo :");
	Yo = lisFlottant();
	valeurs[2] = Yo;

	float vinit;
	ecrisChaine("[ vinit ] Entrez la valeur de la vinit :");
	vinit = lisFlottant();
	valeurs[3] = vinit;

	float angle;
	ecrisChaine("[ angle ] Entrez la valeur de la angle :");
	angle = lisFlottant();
	valeurs[4] = angle;

	float gravite;
	gravite = 9.81;
	valeurs[5] = gravite;
	printf("\n");
	return 0;
}


//FONCTION AFFICHE TABLEAU

int afficheTableau(tableau valeurs, int longeurValeurs){

	int indice;
	//Cas d'erreur
	if((longeurValeurs <= 0) || (longeurValeurs>DIM)){
		return -1;
	}


	for (indice=0 ; indice < longeurValeurs ; indice++ )
	{
		ecrisChaine("Valeur ");
		ecrisEntier(indice + 1);
		ecrisChaine(" : ");
		tabulation();
		ecrisFlottant(valeurs[indice]);
		sautDeLigne();
	}
	return 0;
}

//Fonction qui convertit un angle "deg" en "rad"

float deg2Rad(float angle){

	return angle*(M_PI / 180.00);
}

//Fonction qui vérifie les valeurs du tableau de données
int verifValeurs(int l, tableau tab){
	//Taille tableau
	if((l <= 0) || (l > DIM)){
		return -1;
	}
	//Masse <0
	if(tab[0] < 0){
		return -2;
	}
	//Y < 0
	if(tab[2] < 0){
		return -3;
	}
	//V < 0
	if(tab[3] <= 0){

		return -4;
	}
	//Angle
	if((tab[4] < -90 ) || (tab[4] > 90)){

		return -5;
	}
	//Gravite < 0
	if(tab[5] < 0){

		return -6;
	}
	return 0;
}

//Fonction qui affiche les erreurs
void affiche_erreur(int e){
	if(e == -1){
		ecrisChaine("\t Erreur de taille tableau \n");
	}
	if(e == -2){
		ecrisChaine("\t Erreur masse negative \n");
	}
	if(e == -3){
		ecrisChaine("\t Erreur altitude negative \n");
	}
	if(e == -4){
		ecrisChaine("\t Erreur vitesse nulle ou negative \n");
	}
	if(e == -5){
		ecrisChaine("\t Erreur angle non compris entre -90 et 90 degres \n");
	}
	if(e == -6){
		ecrisChaine("\t Erreur valeur gravite negative \n");
	}
	if(e == -7){
		ecrisChaine("\t Erreur angle inferieur a zero pas possible pour ce mode de calcul\n");
	}
}

//Fonction qui affiche les resultats

void affiche_valeurs(int type, int l, tableau tab){
	if(type == 1){
		sautDeLigne();
		ecrisChaine("Le point de chute a pour coordonnées : X= ");
		ecrisFlottant(tab[0]);
		ecrisChaine(" et Y= 0");
		sautDeLigne();
		}
	if(type == 2){
		sautDeLigne();
		ecrisChaine("Le point maximal atteint vaut Y= ");
		ecrisFlottant(tab[1]);
		sautDeLigne();
	}
	if(type == 3){
		sautDeLigne();
		ecrisChaine("Le point de chute a pour coordonnées : X= ");
		ecrisFlottant(tab[0]);
		ecrisChaine(" et Y= 0");
		sautDeLigne();
		sautDeLigne();
		ecrisChaine("Le point de hauteur maximal a pour coordonnées : X= ");
		ecrisFlottant(tab[2]);
		ecrisChaine(" et Y= ");
		ecrisFlottant(tab[1]);
		sautDeLigne();
		sautDeLigne();
	}
}



//Calcul hauteur
int val2eq(tableau equation, tableau valeurs, int longueurValeurs){
	equation[2] = -(valeurs[5]*valeurs[0])/(2*valeurs[3]*valeurs[3]*cosf(valeurs[4])*cosf(valeurs[4]));
	equation[1] = tanf(valeurs[4]);
	equation[0] = valeurs[2];
	int longueurEquation;
	longueurEquation = 2;
	return longueurEquation;
}


int derivee(tableau equation, tableau derive, int longueurEquation){
	int i;
	for(i=0;i<longueurEquation;i++){
		derive[i] = equation[i+1]*(i+1);
	}
	return 0;
}


float zeroLongueur(tableau equation){
	float x=0.1;
	float pas=1;
	while((equation[2]*x*x+equation[1]*x+equation[0]) > 0.001){
		while((equation[2]*x*x+equation[1]*x+equation[0])>0){
			x = x + pas;
		}
	x = x - pas;
	pas = pas /10;
	}
	x = x + pas;
	return x;
}

float zeroHauteur(tableau equation, tableau derive, tableau resultats){
	float x=0.1;
	float y;
	float pas=1;
	while((derive[1]*x+derive[0]) > 0.001){
		while((derive[1]*x+derive[0])>0){
			x = x + pas;
		}
	x = x - pas;
	pas = pas /10;
	}
	x = x + pas;
	resultats[2]=x;
	y = equation[2]*x*x+equation[1]*x+equation[0];
	return y;
}