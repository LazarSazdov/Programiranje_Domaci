#include <stdio.h>
#include <stdlib.h>
/*

	Napraviti program koji od korisnika zahteva
	da unese broj elemenata u dinamicki alociranom nizu,
	a zatim da se taj niz popuni elementima. Nakon toga izracunati
	prosecnu vrednost elemenata u nizu.


*/
int main()
{

int a;
float avg = 0.0;
printf("unesite broj elemenata u nizu: ");
scanf("%i",&a);
int* niz = malloc(a*(sizeof (int)));
printf("Unesite niz:\n");
int i;
for(i=0;i<a;i++){
    scanf("%i",niz + i);
    avg += (float)niz[i];
}
 avg = avg/(float)a;
printf("Prosecna vrednost elemenata u nizu je: %.2f\n",avg);
free(niz);
    return 0;
}
