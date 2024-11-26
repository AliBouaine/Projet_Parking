#include "Ser.h"

int ajouter(char * filename, service s, int choix[], char ch[] )
{
 strcpy(ch, "");
    if (choix[0] == 1)
        strcat(ch, "/especes/");
    if (choix[1] == 1)
        strcat(ch, "/carte_bancaire/");


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
int modifier( char * filename, int id, service nouv )
{
    int tr=0;
    service s;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %f \n",&s.id,s.nom,&s.tarif)!=EOF)
        {
            if(s.id== id)
            {
                fprintf(f2,"%d %s %f\n",nouv.id,nouv.nom,nouv.tarif);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %f\n",s.id,s.nom,s.tarif);

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
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %f\n",&s.id,s.nom,&s.tarif)!=EOF)
        {
            if(s.id== id)
                tr=1;
            else
                fprintf(f2,"%d %s %f\n",s.id,s.nom,s.tarif);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
service chercher(char * filename, int id)
{
    service s;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %f\n",&s.id,s.nom,&s.tarif)!=EOF)
        {
            if(s.id== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        s.id=-1;
    return s;
}
void affecterService(char * servicefile,char * reservationfile ,int id) 
{
    FILE * f = fopen(servicefile, "r");
    FILE * f2 = fopen(reservationfile, "a"); 

    if(f!=NULL && f2!=NULL)
    {

    service s;
    int tr=0;
  while(tr==0&& fscanf(f,"%d %s %f\n",&s.id,s.nom,&s.tarif)!=EOF)
        {
            if(s.id== id){
                tr=1;
                fprintf(f2,"%d %s %f\n",s.id,s.nom,s.tarif);}
        }
    
    }
    fclose(f);
    fclose(f2);

}
