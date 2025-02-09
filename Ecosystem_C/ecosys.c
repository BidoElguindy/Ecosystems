#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ecosys.h"

/* PARTIE 1*/
float p_ch_dir=0.01;
float p_reproduce_proie=0.4;
float p_reproduce_predateur=0.5;
int temps_repousse_herbe=-15;
/* Fourni: Part 1, exercice 3, question 2 */
Animal *creer_animal(int x, int y, float energie) {
//fonction qui crée un animal
  Animal *na = (Animal *)malloc(sizeof(Animal));
  assert(na);
  na->x = x;
  na->y = y;
  na->energie = energie;
  na->dir[0] = rand() % 3 - 1;
  na->dir[1] = rand() % 3 - 1;
  na->suivant = NULL;
  return na;
}


/* Fourni: Part 1, exercice 3, question 3 */
Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal) {
//fonction qui ajoute en tête un animal dans une liste d'animal
  assert(animal);
  assert(!animal->suivant);
  animal->suivant = liste;
  return animal;
}

/* A faire. Part 1, exercice 5, question 1 */
void ajouter_animal(int x, int y,  float energie, Animal **liste_animal) {
//fonction qui crée un animal puis l'ajoute à une liste d'animal
  assert(x<=SIZE_X);
  assert(y<=SIZE_Y);
  Animal *m=creer_animal(x,y,energie);
  *liste_animal=ajouter_en_tete_animal(*liste_animal,m);
}

/* A Faire. Part 1, exercice 5, question 5 */
void enlever_animal(Animal **liste, Animal *animal) {
    //fonction qui enleve un animal
    Animal* na=*liste;
    Animal* prec=na;
    Animal*suiv=na->suivant;
    if(na==animal){
        *liste=(*liste)->suivant;
        free(na);
        
    }else{
        while((suiv->suivant!=NULL)&&(na!=animal)){
            prec=na;
            na=na->suivant;
            suiv=suiv->suivant;
            
        }if (na==animal){
            free(na);
            prec->suivant=suiv;
        }else if(suiv==animal){
            na->suivant=NULL;
            free(suiv);
        }
    }


 
}

/* A Faire. Part 1, exercice 5, question 2 */
Animal* liberer_liste_animaux(Animal *liste) {
    //libere une liste
  Animal *tmp=NULL;
  while(liste){
    tmp=liste->suivant;
    free(liste);
    liste=tmp;
    
  }
 

  return NULL;
}

/* Fourni: part 1, exercice 3, question 4 */
unsigned int compte_animal_rec(Animal *la) {
  if (!la) return 0;
  return 1 + compte_animal_rec(la->suivant);
}

/* Fourni: part 1, exercice 3, question 4 */
unsigned int compte_animal_it(Animal *la) {
  int cpt=0;
  Animal *tmp=la;
  while (tmp) {
    cpt++;
    tmp=tmp->suivant;
  }
  return cpt;
}



/* Part 1. Exercice 4, question 1, ATTENTION, ce code est susceptible de contenir des erreurs... */
void afficher_ecosys(Animal *liste_proie, Animal *liste_predateur) {

  unsigned int i, j;
  char ecosys[SIZE_X][SIZE_Y];
  Animal *pa=NULL;

  /* on initialise le tableau */
  for (i = 0; i < SIZE_X; i++) {
    for (j = 0; j < SIZE_Y; j++) {
      ecosys[i][j]=' ';
    }
  }

  /* on ajoute les proies */
  Animal *pa1 = liste_proie;
  
  while (pa1) {
    ecosys[pa1->x][pa1->y] = '*';
    pa1=pa1->suivant;
  }

  /* on ajoute les predateurs */
  pa = liste_predateur;
  while (pa) {
      if ((ecosys[pa->x][pa->y] == '@') || (ecosys[pa->x][pa->y] == '*')) { /* proies aussi present */
        ecosys[pa->x][pa->y] = '@';
      } else {
        ecosys[pa->x][pa->y] = 'O';
      }
    pa = pa->suivant;
  }

  /* on affiche le tableau */
  printf("+");
  for (j = 0; j < SIZE_Y; j++) {
    printf("-");
  }  
  printf("+\n");
  for (i = 0; i < SIZE_X; i++) {
    printf("|");
    for (j = 0; j < SIZE_Y; j++) {
      putchar(ecosys[i][j]);
    }
    printf("|\n");
  }
  printf("+");
  for (j = 0; j<SIZE_Y; j++) {
    printf("-");
  }
  printf("+\n");
  int nbproie=compte_animal_it(liste_proie);
  int nbpred=compte_animal_it(liste_predateur);
  
  printf("Nb proies : %5d\tNb predateurs : %5d\n", nbproie, nbpred);

}


void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}

/* PARTIE 2*/

/* Part 2. Exercice 4, question 1 */
void bouger_animaux(Animal* la) {
    //deplcae les animaux d'une liste aléatoirement
    Animal*tmp=la;
    while(tmp){
      if(rand()/(float)RAND_MAX<1){
        tmp->dir[0]=rand()%3-1;
        tmp->dir[1]=rand()%3-1;
      }
    tmp->x=(tmp->x+tmp->dir[0]+SIZE_X)%SIZE_X;
    tmp->y=(tmp->y+tmp->dir[1]+SIZE_Y)%SIZE_Y;
    tmp=tmp->suivant;

    }
}

/* Part 2. Exercice 4, question 3 */
void reproduce(Animal **liste, float p_reproduce) {
   //reproduirt un animal avec une proba p_reproduce
   Animal*na=NULL;
   if(liste){
  na=*liste;
  
   }
   while(na){
    if(rand()/(float)RAND_MAX<p_reproduce){
      ajouter_animal(na->x,na->y,na->energie/2,liste);
      na->energie=na->energie/2;

    }na=na->suivant;
   }
  
}


/* Part 2. Exercice 6, question 1 */
void rafraichir_proies(Animal **liste_proie, int monde[SIZE_X][SIZE_Y]) {
    //bouge les proies  ensuite baisse leur energie de 1 et supprime toutes proies qui  n'ont plus d'energie et applique reproduce sur  la liste
    rafraichir_monde(monde);
    Animal*na=*liste_proie;
    bouger_animaux(na);
    while(na){
        na->energie=na->energie-1.0;
        if(monde[na->x][na->y]>0){
            na->energie=na->energie+monde[na->x][na->y];
           monde[na->x][na->y]=-150;
        }
        if (na->energie<=0.0){
            enlever_animal(liste_proie,na);
        }
       
        na=na->suivant;
        

    }reproduce(liste_proie,p_reproduce_proie);

}

/* Part 2. Exercice 7, question 1 */
Animal *animal_en_XY(Animal *l, int x, int y) {
    
    Animal* na=l;
    while(na!=NULL){
        if((na->x==x)&&(na->y==y)){
            return na;
        }
        
        na=na->suivant;
        
    }

  return NULL;
} 

/* Part 2. Exercice 7, question 2 */
void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
    //bouge les animaux ensuite baisse leur energie de 1 et supprime toutes proies mangées par un predateur et applique reproduce sur la liste
    Animal*na=*liste_predateur;
    bouger_animaux(na);
    while(na){
        na->energie=na->energie-1.0;
        if (na->energie<=0.0){
            enlever_animal(liste_predateur,na);
        }
        Animal* p=animal_en_XY(*liste_proie,na->x,na->y);
        if (p!=NULL){
            //printf("Une proie va se faire manger !! \n");
            na->energie=na->energie+p->energie;
            enlever_animal(liste_proie,p);
        }
        na=na->suivant;
        

    }reproduce(liste_predateur,p_reproduce_predateur);


}

/* Part 2. Exercice 5, question 2 */
void rafraichir_monde(int monde[SIZE_X][SIZE_Y]){

    for(int i=0; i<SIZE_X; i++){
        for(int j=0; j<SIZE_Y;j++){
            monde[i][j]=(monde[i][j])+1;
        }
    }


}

