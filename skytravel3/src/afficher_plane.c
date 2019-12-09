#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include "afficher_plane.h"
#include <gtk/gtk.h>

enum   
{       
        DATE,
	CLASSE,
	CA,
	COLUMNS
};

//Ajouter une personne

/*void ajouter_personne(Personne p)
{

 FILE *f;
  f=fopen("utilisateur.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s \n",p.cin,p.nom,p.prenom,p.date_naissance,p.adresse);
  fclose(f);

}

}*/


//Afficher une personne


void afficher_plane(GtkWidget *liste,char TXT[])
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char date [30];
	char classe [30];
	char ca [30];
	char E [30];
        char A[30];
	char B[30];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  DATE", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Classe", renderer, "text",CLASSE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Companie", renderer, "text",CA, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen(TXT, "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen(TXT, "a+");
              while(fscanf(f,"%s %s %s %s %s %s \n",date,classe,ca,A,E,B)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,DATE ,date,CLASSE,classe,CA,ca, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

