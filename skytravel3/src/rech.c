

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void rech(char aller[], char retour[],char rec[],int A,int B, int CC ){
FILE*f;
FILE*f1;
char Nom[100];
char result [100];
char C [50] ;char D [50] ;int x; char Ca [50];
int N=A+B+CC;
sprintf(Nom,"%s%s-%s%s","/home/gharbi/Downloads/skytravel3/src/",aller,retour,".txt");
f=fopen(Nom,"r");//ouvertur du fichier en mode lecture
f1=fopen("/home/gharbi/Downloads/skytravel3/src/currentrech.txt","w");
if(f !=NULL) {
while(fscanf(f,"%s %s %s %d \n",D,C, Ca,&x)!=EOF){
printf("%s - %s - %s - %d \n",D,C, Ca,x);
sprintf(result,"%s %s",D,C);
printf("%s %s",rec,result);
printf("%d",strcmp(result,rec));
if((strcmp(result,rec)==0) && (x>N)){
if(f1!=NULL) { //si le fichier est ouvert
fprintf(f1,"%s %s %d %d %d \n",result,Ca,A,B,CC);//écriture dans le fichier
}
}
}
fclose(f);
fclose(f1);
}
}
