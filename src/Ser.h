#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include <stdio.h>
typedef struct
{
    int id;
    char nom[50];
    char tarif[10];
}service;
typedef struct
{
    int id;
    char nom[50];
    float tarif;
}reservation;

int ajouter(char *, service , int*,char*);
int modifier( char *, int, service );
int supprimer(char *, int );
service chercher(char *, int);
void affecterService(char *,char * ,int );
#endif 
