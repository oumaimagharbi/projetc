#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "rech.h"
#include "rechr.h"
#include "afficher_plane.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "who.h"
#include "ameni.h"
#include "bilel.h"
#include "reserver.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int verif(char nom[], char prenom[]){
FILE*f;
char Nom[20]; char Prenom[20];int Role;
f=fopen("/home/gharbi/Downloads/skytravel3/src/personne.txt","r");//ouvertur du fichier en mode lecture
if(f !=NULL) {
while(fscanf(f,"%s %s %d \n",Nom,Prenom,&Role)!=EOF){ //parcours du fichier;
}
fclose(f);
if ((strcmp(nom,Nom)==0) && (strcmp(Prenom,prenom)==0)) return Role;
} return 0;
}


void
on_Quitter01_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"loginwindow");
aller_allerretour_window=lookup_widget(button,"agent");
gtk_widget_destroy(aller_allerretour_window);
client=create_loginwindow();
gtk_widget_show(client);
}


void
on_Rechercher2_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
//recherche client de vol
GtkWidget *aller;
GtkWidget *retour;
GtkWidget *date;
GtkWidget *Bebe;
GtkWidget *enfant;
GtkWidget *adulte;
GtkWidget *class;
GtkWidget *error;
///////////////////////////////////////
aller=lookup_widget(button,"allercomboclient");
retour=lookup_widget(button,"retourcomboclient");
date=lookup_widget(button,"entry7");
class=lookup_widget(button,"combobox2");
Bebe=lookup_widget(button,"spinbutton6");
enfant=lookup_widget(button,"spinbutton5");
adulte=lookup_widget(button,"spinbutton4");
error=lookup_widget(button,"errorclientmessage");
///////////////////////////////////////
int B; int Ad; int E;
char A [50]; char R[50];
char D [50]; char C [10];
B=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Bebe));
Ad=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(adulte));
E=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(enfant));
strcpy(C,gtk_combo_box_get_active_text(GTK_COMBO_BOX(class)));
strcpy(A,gtk_combo_box_get_active_text(GTK_COMBO_BOX(aller)));
strcpy(R,gtk_combo_box_get_active_text(GTK_COMBO_BOX(retour)));
strcpy(D,gtk_entry_get_text(GTK_ENTRY(date)));

///////////////////////////////////////
if (strcmp(A,R)!=0 && strcmp(D,"")!=0){
int x = B+Ad+E;
char result [100];
sprintf(result,"%s %s",D,C);
rech(A,R,result,B,Ad,E);
char tested [100] ;
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"geneclient");
aller_allerretour_window=lookup_widget(button,"client");
gtk_widget_destroy(aller_allerretour_window);
client=create_geneclient();
gtk_widget_show(client);}
else
gtk_label_set_text(error,"choisir informations correcte");

}


void
on_Quitter1_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"geneagent");
aller_allerretour_window=lookup_widget(button,"agent");
gtk_widget_destroy(client);
aller_allerretour_window=create_agent();
gtk_widget_show(aller_allerretour_window);
}


void
on_Quitter2_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"geneclient");
aller_allerretour_window=lookup_widget(button,"aller_allerretour_window");
gtk_widget_destroy(client);
aller_allerretour_window=create_aller_allerretour_window();
gtk_widget_show(aller_allerretour_window);
}


void
on_loginbutton_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
//1 = agent
//2 = client
GtkWidget *loginwindow , *agent, *aller_allerretour_window;
GtkWidget *entry10, *entry11, *WPlabel;
char login[20]; char password [20];
entry10=lookup_widget(button,"entry10");
entry11=lookup_widget(button,"entry11");
WPlabel=lookup_widget(button,"WPlabel");
strcpy(login,gtk_entry_get_text(GTK_ENTRY(entry10)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(entry11)));
////////////////
int x=verif(login,password);
////////////////////
if(x==1){
who (login,password,x);
agent=lookup_widget(button,"agent");
loginwindow=lookup_widget(button,"loginwindow");
gtk_widget_destroy(loginwindow);
agent=create_agent();
gtk_widget_show(agent);}
if(x==2){
who (login,password,x);
aller_allerretour_window=lookup_widget(button,"aller_allerretour_window");
loginwindow=lookup_widget(button,"loginwindow");
gtk_widget_destroy(loginwindow);
aller_allerretour_window=create_aller_allerretour_window();
gtk_widget_show(aller_allerretour_window);}
char tast[20];
sprintf(tast,"%d",x);
if(x==0){gtk_label_set_text(WPlabel,"wrong pass / login ");}
}


void
on_allerbutton_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"client");
aller_allerretour_window=lookup_widget(button,"aller_allerretour_window");
gtk_widget_destroy(aller_allerretour_window);
client=create_client();
gtk_widget_show(client);
}


void
on_allerretourbutton_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"allerretourclient");
aller_allerretour_window=lookup_widget(button,"aller_allerretour_window");
gtk_widget_destroy(aller_allerretour_window);
client=create_allerretourclient();
gtk_widget_show(client);
}


void
on_quitter3button_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"loginwindow");
aller_allerretour_window=lookup_widget(button,"aller_allerretour_window");
gtk_widget_destroy(aller_allerretour_window);
client=create_loginwindow();
gtk_widget_show(client);
}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"allerretourclient");
aller_allerretour_window=lookup_widget(button,"aller_allerretour_window");
gtk_widget_destroy(client);
aller_allerretour_window=create_aller_allerretour_window();
gtk_widget_show(aller_allerretour_window);
}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
//recherche client de vol aller retour
GtkWidget *aller;
GtkWidget *retour;
GtkWidget *dateA;
GtkWidget *dateB;
GtkWidget *Bebe;
GtkWidget *enfant;
GtkWidget *adulte;
GtkWidget *class;
GtkWidget *error;
///////////////////////////////////////
aller=lookup_widget(button,"combobox6");
retour=lookup_widget(button,"combobox7");
dateA=lookup_widget(button,"entry14");
dateB=lookup_widget(button,"entry15");
class=lookup_widget(button,"combobox3");
Bebe=lookup_widget(button,"spinbutton9");
enfant=lookup_widget(button,"spinbutton8");
adulte=lookup_widget(button,"spinbutton7");
error=lookup_widget(button,"label31");
///////////////////////////////////////
int B; int Ad; int E;
char A [50]; char R[50];
char D [50]; char C [10]; char DD [50];
B=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Bebe));
Ad=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(adulte));
E=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(enfant));
strcpy(C,gtk_combo_box_get_active_text(GTK_COMBO_BOX(class)));
strcpy(A,gtk_combo_box_get_active_text(GTK_COMBO_BOX(aller)));
strcpy(R,gtk_combo_box_get_active_text(GTK_COMBO_BOX(retour)));
strcpy(D,gtk_entry_get_text(GTK_ENTRY(dateA)));
strcpy(DD,gtk_entry_get_text(GTK_ENTRY(dateB)));

///////////////////////////////////////
if (strcmp(A,R)!=0 && strcmp(D,"")!=0 && strcmp(DD,"")!=0){
int x = B+Ad+E;
char result [100];
sprintf(result,"%s %s",D,C);
rech(A,R,result,B,Ad,E);
sprintf(result,"%s %s",DD,C);
rechr(R,A,result,B,Ad,E);
char tested [100] ;
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"geneclientretour");
aller_allerretour_window=lookup_widget(button,"allerretourclient");
gtk_widget_destroy(aller_allerretour_window);
client=create_geneclientretour();
gtk_widget_show(client);}
else
gtk_label_set_text(error,"choisir informations correcte");
}


void
on_Quitter02_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"client");
aller_allerretour_window=lookup_widget(button,"aller_allerretour_window");
gtk_widget_destroy(client);
aller_allerretour_window=create_aller_allerretour_window();
gtk_widget_show(aller_allerretour_window);
}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
GtkWidget *aller;
GtkWidget *retour;
GtkWidget *date;
GtkWidget *Bebe;
GtkWidget *enfant;
GtkWidget *adulte;
GtkWidget *class;
GtkWidget *error;
///////////////////////////////////////
aller=lookup_widget(button,"combobox8");
retour=lookup_widget(button,"combobox9");
date=lookup_widget(button,"entry3");
class=lookup_widget(button,"classcombo");
Bebe=lookup_widget(button,"spinbutton12");
enfant=lookup_widget(button,"spinbutton11");
adulte=lookup_widget(button,"spinbutton10");
error=lookup_widget(button,"label33");
///////////////////////////////////////
int B; int Ad; int E;
char A [50]; char R[50];
char D [50]; char C [10];
B=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Bebe));
Ad=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(adulte));
E=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(enfant));
strcpy(C,gtk_combo_box_get_active_text(GTK_COMBO_BOX(class)));
strcpy(A,gtk_combo_box_get_active_text(GTK_COMBO_BOX(aller)));
strcpy(R,gtk_combo_box_get_active_text(GTK_COMBO_BOX(retour)));
strcpy(D,gtk_entry_get_text(GTK_ENTRY(date)));

///////////////////////////////////////
if (strcmp(A,R)!=0 && strcmp(D,"")!=0){
int x = B+Ad+E;
char result [100];
sprintf(result,"%s %s",D,C);
rech(A,R,result,B,Ad,E);
char tested [100] ;
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"geneagent");
aller_allerretour_window=lookup_widget(button,"agent");
gtk_widget_destroy(aller_allerretour_window);
client=create_geneagent();
gtk_widget_show(client);}
else
gtk_label_set_text(error,"choisir informations correcte");



}


void
on_refrech_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *client;
client=lookup_widget(button,"geneagent");
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
treeview1=lookup_widget(client,"treeview1");

afficher_plane(treeview1,"/home/gharbi/Downloads/skytravel3/src/currentrech.txt"); 
}


void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *client;
client=lookup_widget(button,"geneclient");
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
treeview1=lookup_widget(client,"treeview2");
afficher_plane(treeview1,"/home/gharbi/Downloads/skytravel3/src/currentrech.txt"); 
}


void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"geneclientretour");
aller_allerretour_window=lookup_widget(button,"aller_allerretour_window");
gtk_widget_destroy(client);
aller_allerretour_window=create_aller_allerretour_window();
gtk_widget_show(aller_allerretour_window);
}


void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Spin1;
GtkWidget *Spin2;
Spin1=lookup_widget(button,"spinbutton15");
Spin2=lookup_widget(button,"spinbutton14");
int A=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Spin1));
int B=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Spin2));
reserver("/home/gharbi/Downloads/skytravel3/src/current.txt","/home/gharbi/Downloads/skytravel3/src/currentrech.txt",A);
reserver("/home/gharbi/Downloads/skytravel3/src/current.txt","/home/gharbi/Downloads/skytravel3/src/src/currentrechRetour.txt",B);
}


void
on_button17_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *client;
client=lookup_widget(button,"geneclientretour");
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *treeview1;
treeview1=lookup_widget(client,"treeview3");
afficher_plane(treeview1,"/home/gharbi/Downloads/skytravel3/src/currentrech.txt");
GtkWidget *treeview2;
treeview2=lookup_widget(client,"treeview4");
afficher_plane(treeview2,"/home/gharbi/Downloads/skytravel3/src/currentrechRetour.txt");

}


void
on_buttonsupprimreservation_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *label;
GtkWidget *Spinbutton;
char D[100000];
//////////////////////////////////////
window2=lookup_widget(button,"window2");
label=lookup_widget(button,"label38");
Spinbutton=lookup_widget(button,"spinbutton13");
//////////////////////////////////////
int B=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Spinbutton));
char k[20];
sprintf(k,"%d suprimée",B);
gtk_label_set_text(label,k);
ameni(B);
}


void
on_buttonajoutreservation_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
}


void
on_buttonmodifreservation_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *label;
GtkWidget *Spinbutton;
window2=lookup_widget(button,"window2");
label=lookup_widget(button,"label38");
Spinbutton=lookup_widget(button,"spinbutton13");
int B=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Spinbutton));
ameni(B);
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"window2");
aller_allerretour_window=lookup_widget(button,"client");
gtk_widget_destroy(client);
aller_allerretour_window=create_client();
gtk_widget_show(aller_allerretour_window);

}


void
on_buttonrefreshreservation_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
GtkWidget *label;
/*char D[100000];
//////////////////////////////////////*/
window2=lookup_widget(button,"window2");
label=lookup_widget(button,"label38");
/*/////////////////////////////////////
//gtk_label_set_text(label,"");
bilel("/home/coca/gladeProject/skytravel3/src/reservations.txt",label);
//gtk_label_set_text(label,D);*/
char text [100000];
char D[10];
FILE *f=fopen ("/home/gharbi/Downloads/skytravel3/src/reservations.txt","r");
int i=0;
int bilel=0;
while(fscanf(f,"%s",D)!=EOF){
i++;
if (bilel<1) {
if(i==8) {bilel++;strcat(text,"\n"); i=0;}
strcat(text,D);
strcat(text," ");}
else {if(i==7) {strcat(text,"\n"); i=0;}
strcat(text,D);
strcat(text," ");}
}
gtk_label_set_text(label,text);
}


void
on_buttonquit_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"aller_allerretour_window");
aller_allerretour_window=lookup_widget(button,"window2");
gtk_widget_destroy(aller_allerretour_window);
client=create_aller_allerretour_window();
gtk_widget_show(client);
}


void
on_modifier_reservation_button_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *aller_allerretour_window , *agent, *client;
client=lookup_widget(button,"window2");
aller_allerretour_window=lookup_widget(button,"aller_allerretour_window");
gtk_widget_destroy(aller_allerretour_window);
client=create_window2();
gtk_widget_show(client);
}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Spin1;

Spin1=lookup_widget(button,"spinbutton16");

int A=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Spin1));

reserver("/home/coca/gladeProject/skytravel3/src/current.txt","/home/gharbi/Downloads/skytravel3/src/currentrech.txt",A);

}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Spin1;

Spin1=lookup_widget(button,"spinbutton16");

int A=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Spin1));

reserver("/home/gharbi/Downloads/skytravel3/src/current.txt","/home/gharbi/Downloads/skytravel3/src/currentrech.txt",A);

}

