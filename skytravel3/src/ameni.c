#include <stdio.h>
#include <stdlib.h>
void ameni (int id)
{
int cd = 0; char i1 [20] ; char i2 [20] ; char i3 [20]; char i4 [20];char i5 [20];char i6 [20];char i7 [20];
FILE*f;
FILE*Ftemp;
f=fopen("/home/gharbi/Downloads/skytravel3/src/reservations.txt","r");
Ftemp=fopen("/home/gharbi/Downloads/skytravel3/src/hebergementtemp.txt","w");
while(!feof(f))
    {
	cd++;
     fscanf(f,"%s %s %s %s %s %s %s \n",i1,i2,i3,i4,i5,i6,i7);

       if(id!=cd)
         {fprintf(Ftemp,"%s %s %s %s %s %s %s \n",i1,i2,i3,i4,i5,i6,i7);
    }}



fclose(f);
fclose(Ftemp);
remove("/home/gharbi/Downloads/skytravel3/src/reservations.txt");
rename("/home/gharbi/Downloads/skytravel3/src/hebergementtemp.txt","/home/gharbi/Downloads/skytravel3/src/reservations.txt");
}

