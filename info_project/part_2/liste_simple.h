//
//  liste_simple.c
//  
//
//  Created by El Kahoui on 28/02/2021.
//
#include<stdio.h>
#include<stdlib.h>
//#include "liste_simple.h"

struct cellule
{
    int element;
    struct cellule * suivant;

};
typedef struct cellule cellule;
typedef struct cellule * liste;

///////// Prototypes ///////////////////
int testVide(liste);
unsigned longueur(liste);
void affichageListe(liste);
void ajoutDebut(int,liste *);
void ajoutFin(int,liste *);
liste saisieListe(int);
liste cloneListe(liste);
void suppressionDebut(liste *);
void suppressionFin(liste *);
void liberer(liste*);
liste recherche(int, liste);
unsigned occurence(int,liste);
unsigned length(liste);
void concatenation(liste *, liste *);
/////////////////////////////////////////

// Test d'une liste vide.
int testVide(liste L)
{
    if(L==NULL)
        return 1;
    return 0;
}

// Longueur d'une liste.
unsigned longueur(liste L)
{
    unsigned l=0;
    if(testVide(L)==0)
    {
        liste temp=L;
        while(temp!=NULL)
        {
            l+=1;
            temp=temp->suivant;
        }
    }
    return l;
}

// Affichange d'une liste
void affichageListe(liste L)
{
    if(L==NULL)
        printf("[ ]\n");
    else
    {
        liste temp=L;
        printf("S -> ");
        temp = temp->suivant;
        while(temp->suivant!=NULL)
        {
            printf("c%d -> ",temp->element);
            temp=temp->suivant;
        }
        if(temp!=NULL)
            printf("E\n");
    }
}

// Ajout au début d'une liste.
void ajoutDebut(int x,liste * L)
{
    // Allocation de mémoire pour une nouvelle cellule
    cellule * C=(cellule *)malloc(sizeof(cellule));
    //Remplissage de la cellule
    C->element=x;
    C->suivant=*L;
    // Ajout de la cellule au début de la liste
    *L=C;
    return;
}

// Ajout à la fin d'une liste
void ajoutFin(int x,liste * L)
{
    // Allocation de mémoire pour une nouvelle cellule
    liste C=(liste)malloc(sizeof(cellule));
    //Remplissage de la cellule
    C->element=x;
    C->suivant=NULL;
    // Acces à la fin de la liste L
    if(*L==NULL)
        *L=C;
    else
    {
        liste temp=*L;
        while(temp->suivant!=NULL)
            temp=temp->suivant;
        temp->suivant=C;
    }
    return;
}

//saisir dans une liste
liste saisieListe(int n){
    int j;
    liste L=NULL;
    printf("Entrer les elements de la liste : \n");
    for(int i=0;i<n;i++){
        printf("-----------------\n");
        scanf("%d",&j);
        ajoutFin(j,&L);
    }
    return L;
}

//clone a liste
liste cloneListe(liste L){
    if(L == NULL) return NULL;
    liste new = (cellule*)malloc(sizeof(cellule));
    new->element = L->element;
    new->suivant = cloneListe(L->suivant);
    return new;
}

// Suppression du début d'une liste.
void suppressionDebut(liste * L)
{
    if(L!=NULL)
    {
        liste temp=*L;
        *L=(*L)->suivant;
        free(temp);
    }
    return;
}

// Suppresion de la fin d'une liste.
void suppressionFin(liste * L)
{
    if(L==NULL)
    {
        return;
    }
    if((*L)->suivant==NULL)
    {
        free(*L);
        *L=NULL;
    }
    else
    {
        // Acces à la dernière et à la l'avant dernière cellules
        liste temp=*L;
        liste temp_1=*L;
        while(temp->suivant!=NULL)
        {
            temp_1=temp;
            temp=temp->suivant;
        }
        temp_1->suivant=NULL;
        free(temp);
    }
    return;
}

// destruction d'une liste
void liberer(liste *L)
{
    while((*L)!=NULL)
    {
        liste temp=*L;
        *L=(*L)->suivant;
        free(temp);
    }
}

