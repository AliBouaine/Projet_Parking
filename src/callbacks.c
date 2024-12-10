#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Ser.h"

int supp=1;
int choix[2]={0,0};
char ch[150]="";
void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *User_add,*Espace_admin;
	User_add=lookup_widget(button,"User_add");
	gtk_widget_destroy(User_add);
	Espace_admin=create_Espace_admin();
	gtk_widget_show(Espace_admin);
}


void
on_button3_ajouter3_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_modifier4_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Services, *Espace_admin;

    
    Espace_admin = lookup_widget(GTK_WIDGET(button), "Espace_admin");
    gtk_widget_destroy(Espace_admin);

    Services = create_Services();
    gtk_widget_show(Services);
}


void
on_button5_supprimer5_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_radiobutton1_supp_conf_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
supp = 1;}
}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *Sur;
	GtkWidget *Services;
	int id;
	id=pull(id);
	if(supp==1){
	supprimer("services.txt",id);}
	Sur=lookup_widget(button,"Sur");
	gtk_widget_destroy(Sur);
	supp =1;
}


void
on_ali_button3_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
 char vide[2] = "";

GtkWidget *ch1,*ch2;


ch1=lookup_widget(button,"alibouaine_checkbutton9");
ch2=lookup_widget(button,"alibouaine_checkbutton10");


    int a;
    service v;
    GtkWidget *input1, *input2, *input3 ;
    GtkWidget *Services;

    Services = lookup_widget(button, "Services");
    input1 = lookup_widget(button, "alibouaine_entry9");
    input2 = lookup_widget(button, "spinbutton1_ali");
    input3 = lookup_widget(button, "alibouaine_entry10");


strcpy(v.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
v.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input2));
strcpy(v.tarif,gtk_entry_get_text(GTK_ENTRY(input3)));


      a=ajouter("services.txt", v,choix,ch);
  if(a==1){
choix[0]=0;
choix[1]=0;

   gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2), 1);
                    gtk_entry_set_text(GTK_ENTRY(input1), vide);
                    gtk_entry_set_text(GTK_ENTRY(input3), vide);
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch1),FALSE);
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch2),FALSE);


     }
}


void
on_alibouaine_checkbutton10_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[1]=1;
}
}


void
on_ali_button4_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
char vide[2] = "";

GtkWidget *ch1,*ch2;


ch1=lookup_widget(button,"alibouaine_checkbutton11");
ch2=lookup_widget(button,"alibouaine_checkbutton12");


    int a;
    int id;
    service s;
    GtkWidget *input1, *input2, *input3 ;
    GtkWidget *Services;

    Services = lookup_widget(button, "Services");
    input1 = lookup_widget(button, "alibouaine_entry11");
    input2 = lookup_widget(button, "alibouaine_spinbutton4");
    input3 = lookup_widget(button, "alibouaine_entry12");


strcpy(s.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
s.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input2));
strcpy(s.tarif,gtk_entry_get_text(GTK_ENTRY(input3)));
id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input2));

      a=modifier("services.txt",id, s,choix,ch);
  if(a==1){
choix[0]=0;
choix[1]=0;

   gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2), 1);
                    gtk_entry_set_text(GTK_ENTRY(input1), vide);
                    gtk_entry_set_text(GTK_ENTRY(input3), vide);
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch1),FALSE);
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch2),FALSE);

}

}
void
on_alibouaine_checkbutton12_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[1]=1;}
}


void
on_alibouaine_checkbutton11_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[0]=1;}
}


void
on_alibouaine_button17_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
    char mot1[50] = "ECHEC de supp";
    char vide[2] = "";    char ch[150];
	service ser;
	int id;
	GtkWidget *input2,*output2;
	GtkWidget *Sur;
	GtkWidget *Service;

	Service=lookup_widget(button,"Services");
        input2 = lookup_widget(button, "alibouaine_spinbutton5");
	output2=lookup_widget(button,"ali_label71");


          id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input2));
	 ser = chercher("services.txt",id , ch);
	if(ser.id==-1){
        gtk_label_set_text(GTK_LABEL(output2), mot1);	
}
	else {
        gtk_label_set_text(GTK_LABEL(output2), vide);
 	    Sur=create_Sur();
	    gtk_widget_show(Sur);
	add(id);
	}


}


void
on_ali_button18_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_alibouaine_checkbutton9_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[0]=1;
}
}


void
on_ali_button5_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Services,*alibouaine_treeview1;
	Services = lookup_widget(button,"Services");
	alibouaine_treeview1=lookup_widget(Services,"alibouaine_treeview1");
	 afficher_service (alibouaine_treeview1,ch);
}


void
on_radiobutton2_supp_ann_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
supp = 2;}
}


void
on_alibouaine_treeview1_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gint* id;
	gchar* nom;
	gchar* tarif;
	
	
	service s;
	GtkTreeModel *model = gtk_tree_view_get_model (treeview) ;

	if (gtk_tree_model_get_iter(model, &iter, path) ){

		gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, 1, &nom, 2,&tarif,-1);
		s.id = id;
		strcpy(s.nom,nom) ;
		strcpy(s.tarif,tarif);	
                supprimer_tre(s,ch);	
		afficher_service(treeview,ch) ;
}
}

