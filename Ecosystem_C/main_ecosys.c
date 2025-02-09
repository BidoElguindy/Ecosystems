#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>
#include "ecosys.h"



#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 40000


/* Parametres globaux de l'ecosysteme (externes dans le ecosys.h)*/

int main(void) {
  
   
//création liste de proies
Animal *liste_proie = NULL;

    for(int i = 0; i<20; i++){
        
        ajouter_animal(rand() % SIZE_X,rand()% SIZE_Y, rand()%10, &liste_proie);
        }
//création liste de prédateurs

Animal *liste_predateur = NULL;

    for(int i = 0; i<20; i++){
        ajouter_animal(rand() % SIZE_X,rand()% SIZE_Y, rand()%12, &liste_predateur);
    }
    
int n =compte_animal_it(liste_proie);

printf("%d \n ",n);

    
  
//création du monde
int monde[SIZE_X][SIZE_Y];
    for(int i=0; i<SIZE_X; i++){
        for(int j=0; j>SIZE_Y;j++){
            monde[i][j]=0;
        }
    }
    FILE * f=fopen("Evol_Pop.txt","w");
    
//afficher_ecosys(liste_proie,liste_predateur);
//simulation ecosysteme
    int i=0;
    
    while((i!=15)&&(compte_animal_it(liste_proie)!=0)&&(compte_animal_it(liste_predateur)!=0)){
        fprintf(f,"%d %d %d \n",i,compte_animal_it(liste_proie),compte_animal_it(liste_predateur));
        rafraichir_proies(&liste_proie,monde);
        rafraichir_predateurs(&liste_predateur,&liste_proie);
        usleep(900000);
        clear_screen();
        afficher_ecosys(liste_proie,liste_predateur);
        
        i++;

       
    }
        
    
  /* A completer. Part 2:
   * exercice 4, questions 2 et 4 
   * exercice 6, question 2
   * exercice 7, question 3
   * exercice 8, question 1
   */

  return 0;
}

