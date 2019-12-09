#include <stdio.h>
#include <stdlib.h>
/*int main(){
FILE*f;
char nom[20]; char prenom[20];
int age,i=0; int nbPersonnes=0;
f=fopen("personne.txt","a+"); //ouvrir un fichier en mode ajout
if(f!=NULL) { //si le fichier est ouvert
for(i=0; i<2; i++) {//Ajout de 10 personnes
printf("Saisir les données");
fflush(stdin);
gets(nom);
fflush(stdin);
gets(prenom);
scanf("%d",&age);
fprintf(f,"%s %s %d \n",nom,prenom,age);//écriture dans le fichier
4}
fclose(f); //fermeture du fichier
}
else
printf("Impossible d'ouvrir le fichier");
f=fopen("personne.txt","r");//ouvertur du fichier en mode lecture
if(f !=NULL) {
while(fscanf(f,"%s %s %d \n",nom,prenom,&age)!=EOF){ //parcours du fichier
nbPersonnes++;
}
printf("le nombre de personnes est %d",nbPersonnes);
fclose(f);
} return 0;
}*/
////////////////////////////
void reserver (char UF[],char RF[],int N) {
char res [100];
char person[100];
char ok[20]; char okk [20];
char ok1[20]; char ok2 [20]; char ok3[20] ;char ok4 [20];char ok5[20];char ok6 [20];
FILE*f1;
f1=fopen(UF,"r");//ouvertur du fichier en mode lecture
if(f1 !=NULL) {
while(fscanf(f1,"%s %s %s\n",person,ok,okk)!=EOF){ //parcours du fichier
printf("%s \n",person);
}}
fclose(f1);
int nb=0;
FILE*f2;
f2=fopen(RF,"r");//ouvertur du fichier en mode lecture
if(f2 !=NULL) {
while(fscanf(f2,"%s %s %s %s %s %s \n",ok1,ok2,ok3,ok4,ok5,ok6)!=EOF){ 
printf("%s %s %s %s %s %s \n",ok1,ok2,ok3,ok4,ok5,ok6);//parcours du fichier
sprintf (res,"%s %s %s %s %s %s",ok1,ok2,ok3,ok4,ok5,ok6);
nb++;
if (nb==N) break;}
}
char FINAL [50] ;
sprintf(FINAL,"%s %s",person,res);
fclose(f2); //fermeture du fichier
FILE*f;
f=fopen("/home/gharbi/Downloads/skytravel3/src/reservations.txt","a+"); //ouvrir un fichier en mode ajout
if(f!=NULL) { 
fprintf(f,"%s\n",FINAL);//écriture dans le fichier
}
fclose(f); //fermeture du fichier
///////////////////
}

