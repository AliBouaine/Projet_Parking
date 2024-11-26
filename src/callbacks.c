#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Ser.h"
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

}


void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

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

}


void
on_alibouaine_checkbutton12_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_alibouaine_checkbutton11_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_alibouaine_button17_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

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

