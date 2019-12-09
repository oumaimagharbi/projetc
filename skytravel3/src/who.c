#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void who (char nom[20], char prenom[20],int age){
FILE*f;
f=fopen("/home/gharbi/Downloads/skytravel3/src/current.txt","w"); //ouvrir un fichier en mode ajout
if(f!=NULL) { //si le fichier est ouvert
fprintf(f,"%s %s %d \n",nom,prenom,age);//écriture dans le fichier
}
fclose(f); //fermeture du fichier
}
