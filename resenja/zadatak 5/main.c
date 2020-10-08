#include <stdio.h>
#include <stdlib.h>

int main()
{
int i,n,b=0;
printf("unesite duzinu niza: ");
scanf("%i",&n);
int niz[n],niz2[n];
printf("Unesite clanove niza: ");
for(i=0;i<n;i++){

scanf("%i",niz+i);
if (*(niz+i)%3 == 0){
    *(niz2+b)=i;
    b++;
}
}
printf("Brojevi deljivi sa 3 su: ");
for (i=0;i<b;i++){
    printf("%i ",*(niz + *(niz2 + i)));
}


    return 0;
}
