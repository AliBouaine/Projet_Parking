#include "Ser.h"
#include<string.h>
#include <stdio.h>
int pull( int id){
   FILE *f = fopen("add.txt", "r");
    if (f != NULL)
    {
        fscanf(f, "%d",&id);
        fclose(f);
    }
	remove("add.txt");
	return id;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void add( int id){
   FILE *f = fopen("add.txt", "w");
    if (f != NULL)
    {
        fprintf(f, "%d",id);
        fclose(f); 
    }
}
//////////////
int ajouter(char * filename, service s, int choix[], char ch[] )
{
 strcpy(ch, "");
    if (choix[0] == 1)
        strcat(ch, "especes/");
    if (choix[1] == 1)
        strcat(ch, "/carte_bancaire");
for (int i=0 ;s.tarif[i] != '\0'; i++){
if (s.tarif[i] < '0' || s.tarif[i] > '9') {
return 0; }}
 if (strcmp(s.nom,"")==0){return 0;}
    FILE * f=fopen(filename, "a+");
    if(f!=NULL)
    {
	char chtemp[150]; 
	int lastserid=0;
	service se; 	
while (fscanf(f,"%d %s %s %s \n",&se.id,se.nom,se.tarif,chtemp)!=EOF){
if (se.id>lastserid)
lastserid=se.id;
}
s.id=lastserid+1;


        fprintf(f,"%d %s %s %s \n",s.id,s.nom,s.tarif,ch);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier( char * filename, int id, service nouv,int choix[] ,char ch[])
{
char temp[150];
strcpy(ch, "");
    if (choix[0] == 1)
        strcat(ch, "/especes/");
    if (choix[1] == 1)
        strcat(ch, "/carte_bancaire/");
for (int i=0 ;nouv.tarif[i] != '\0'; i++){
if (nouv.tarif[i] < '0' || nouv.tarif[i] > '9') {
return 0 ;}
}
if (strcmp(nouv.nom,"")==0){return 0;}

    int tr=0;
    service s;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %s \n",&s.id,s.nom,s.tarif,temp)!=EOF)
        {
            if(s.id== id)
            {
                fprintf(f2,"%d %s %s %s \n",nouv.id,nouv.nom,nouv.tarif,ch);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %s \n",s.id,s.nom,s.tarif,temp);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
int supprimer(char * filename, int id)
{
    int tr=0;
    service s;
    char ch [150];
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %s \n",&s.id,s.nom,s.tarif,ch)!=EOF)
        {
            if(s.id== id)
                tr=1;
            else
                fprintf(f2,"%d %s %s %s \n",s.id,s.nom,s.tarif,ch);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
service chercher(char * filename, int id , char ch [])
{
    service s;
    int tr=0;

    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %s %s \n",&s.id,s.nom,s.tarif,ch)!=EOF)
        {
            if(s.id==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        s.id=-1;
    return s;
}
Reservation chercher_res(char * filename, int id )
{
    Reservation r;
    int tr=0;

    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %d %s %s %s %d \n",&r.reservationID,&r.citoiyantid,r.date,r.createdDate,r.parkingSpot,&r.state)!=EOF)
        {
            if(r.reservationID==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        r.reservationID=-1;
    return r;
}
void affecterService(char * servicefile,char * reservationfile ,int id,char chaine[5]) 
{
    FILE * f = fopen(servicefile, "r");
    FILE * f2 = fopen(reservationfile, "a"); 

    if(f!=NULL && f2!=NULL)
    {
    char ch[150];
    service s;

    int tr=0;
  while(tr==0&& fscanf(f,"%d %s %s %s \n",&s.id,s.nom,s.tarif,ch)!=EOF)
        {
            if(s.id== id){
                tr=1;
                fprintf(f2,"id de service : %d affecter a:%s \n",s.id,chaine);}
        }
    
    }
    fclose(f);
    fclose(f2);

}
void afficher_service (GtkWidget *liste,char ch[]){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
    	

	int id; 
    	char nom[15] ;
    	char tarif[15];
	store =NULL;


	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("ID service",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("tarif",renderer,"text",TARIF,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		

	
	}
	store=gtk_list_store_new (COLUMNS ,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("services.txt", "r");
	if (f==NULL){
		return;
	}
	else {
		f=fopen("services.txt", "a+");
		while (fscanf(f,"%d %s %s %s\n",&id,nom,tarif,ch)!=EOF){

			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store ,&iter ,ID ,id ,NOM, nom ,TARIF,tarif,-1);
	}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);


}
}
void supprimer_tre(service s,char ch[])
{

	int id;
    	char nom[15] ;
    	char tarif[15];


	service s2;
	FILE *f,*g;
	f=fopen("services.txt","r");
	g=fopen("dumb.txt","w");
	if (f==NULL || g==NULL){
		return;
	}
	else {
		while(fscanf(f,"%d %s %s %s\n",&s2.id,s2.nom,s2.tarif,ch)!=EOF){
			if (s.id != s2.id || strcmp(s.nom,s2.nom)!=0|| strcmp(s.tarif,s2.tarif)!=0 )
				fprintf(g,"%d %s %s %s\n",s2.id,s2.nom,s2.tarif,ch);
		}

	} 
	fclose(f);
	fclose(g);
	remove("services.txt");
	rename("dumb.txt","services.txt");
}

