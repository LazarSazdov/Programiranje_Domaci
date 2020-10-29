#include <stdio.h>
#include <stdlib.h>
/*
	Napraviti program koji od korisnika zahteva
	da unosi pozitivne elemente u dinamicki alociran niz.
	Niz alocirati na pocetku sa 5 elemenata i prosiriti
	svaki put kada je to potrebno. Na kraju ispisati ucitane vrednosti.
*/
int main()
{
int* niz = malloc(5*sizeof(int));
printf("Unesite niz pozitivnih brojeva (0 za prekid unosa)\n");
int i;
for(i=0;;){
        if (i > 4){
        niz = realloc(niz,(i+1)*sizeof(int));

    }
    scanf("%i",niz + i);
    if (niz[i] < 0){
        printf("Uneli ste negativan broj!!!\n");
    }else if(niz[i] == 0){
    break;
    }

    i++;
}
printf("Niz izgleda ovako:\n");
for(int j =0;j<i;j++){

    printf("%i   ",niz[j]);

}

free(niz);
    return 0;
}
