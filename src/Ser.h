#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct
{
    int id;
    char nom[50];
    char tarif[10];
}service;
typedef struct
{
    int reservationID;
int citoiyantid;
char date[11];
    char createdDate[11];
char parkingSpot[10];
    int state;
}Reservation;
enum{
	ID ,
	NOM ,
	TARIF ,
	COLUMNS,
};

int ajouter(char *, service , int*,char*);
int modifier( char *, int, service ,int*,char*);
int supprimer(char *, int );
service chercher(char *, int ,char*);
void affecterService(char *,char * ,int,char chaine[]);
void afficher_service (GtkWidget *liste,char ch[]);
void supprimer_tre(service,char ch[] );
Reservation chercher_res(char * filename, int );
#endif 
