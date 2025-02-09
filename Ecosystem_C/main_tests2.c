//
//  main_tests2.c
//  
//
//  Created by Fatou Samba on 17/10/2022.
//
#include "ecosys.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "main_tests2.h"
int main(){
    Animal *liste_proie = NULL;
    Animal *liste_predateur = NULL;
    for (int i=0;i<20;i++){
        liste_proie=ajouter_en_tete_animal(liste_proie,creer_animal(rand()%SIZE_X-1,rand()%SIZE_Y-1,10));
    }for (int j=0;j<20;j++){
        liste_predateur=ajouter_en_tete_animal(liste_predateur,creer_animal(rand()%SIZE_X-1,rand()%SIZE_Y-1,10));
    }
    afficher_ecosys(liste_proie,liste_predateur);
    Animal* l1=liberer_liste_animaux(liste_proie);
    Animal* l2=liberer_liste_animaux(liste_predateur);
    afficher_ecosys(l1,l2);
    return 0;
}
