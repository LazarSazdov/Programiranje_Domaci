#include <stdio.h>
#include <stdlib.h>
/*
	Napraviti program koji od korisnika zahteva
	da unese broj a zatim pronalazi sve
	fibonacijeve brojeve manje od tog broja.
	Potrebno ih je smestiti u dinamicki alociran
	niz a zatim se ispisuju.
*/
int main()
{
int a;
int i,j;
int* niz = malloc(3*sizeof(int));
niz[0] = 0;
niz[1] = 1;
printf("unesite broj a: ");
ponovo:
scanf("%i",&a);
if(a < 1){
    printf("Uneli ste neodgovarajuci broj!!!\n");
    goto ponovo;
}
if(a==1){
    printf("%i",0);
    return 0;
}
for(i=2;;i++){
    niz[i] = niz[i-1] + niz[i-2];
    if(niz[i] >= a){
        break;
    }

    niz = realloc(niz,(i+1)*sizeof(int));
}
for(j=0;j<i;j++){
    printf("%i  ",niz[j]);
}
free(niz);
    return 0;
}
