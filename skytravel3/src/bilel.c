#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bilel(char TXT[],char C[]){
char text [100000];
char D[10];
FILE *f=fopen (TXT,"r");
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
printf("%s",text);
strcpy(D,text);
}

