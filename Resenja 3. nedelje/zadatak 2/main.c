#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
unsigned int broj_gostiju;
char naziv_pice[20];
float apetit;
}struktura;
typedef struct{
float broj_parcadi;
unsigned int broj_pica;
char naziv[20];
}porudzbina;



int main()
{
    char ime[100];
    ponovo:
    printf("Unesite naziv datoteke: ");
    gets(ime);
    FILE* dat = fopen(ime, "r");
    if(dat == NULL)
        goto ponovo;
    int i = 0;
    struktura niz[100];
    porudzbina niz1[100];
    for (;;){
    if (feof(dat))
        break;

    fscanf(dat,"%u\n",&(niz[i].broj_gostiju));


    fgets(niz[i].naziv_pice,20,dat);

    fscanf(dat,"%f\n",&(niz[i].apetit));






    niz1[i].broj_parcadi = niz[i].broj_gostiju * niz[i].apetit;
    strcpy(niz1[i].naziv,niz[i].naziv_pice);
    niz1[i].broj_pica = ceil(niz1[i].broj_parcadi / 8);

    i++;
    }
fclose(dat);
int j =0;

FILE* dat1 = fopen("Porudzbina.txt", "w+");

for(j=0;j<i;j++){
    fprintf(dat1,"%5.1f\n",niz1[j].broj_parcadi);
    fprintf(dat1,"%2u\n",niz1[j].broj_pica);
    fputs(niz1[j].naziv, dat1);




}

fclose(dat1);

    return 0;
}
