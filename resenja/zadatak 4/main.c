#include <stdio.h>
#include <stdlib.h>
int main()
{
int i,broj;
int n;
printf("unesite broj elemenata niza: ");
scanf("%i",&n);
int niz[n];
printf("unesite clanove niza: ");
for(i=0;i<n;i++){
    scanf("%i",niz+i);
}
broj=*niz;
for(i=0;i<n-1;i++){
    if (broj < *(niz+i+1))
    broj = *(niz+i+1);
}
printf("najveci broj je %i",broj);
    return 0;
}
