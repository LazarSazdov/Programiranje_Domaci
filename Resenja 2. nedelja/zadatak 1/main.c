#include <stdio.h>
#include <stdlib.h>





int main()
{
    char ime[100];
    char prezime[100];
    int broj[100];
    printf("Unesite ime: ");
    gets(ime);
    printf("Unesite prezime: ");
    gets(prezime);
    printf("Unesite broj u dnevniku: ");
    gets(broj);

    FILE* dat = fopen("Tekst.txt", "w");
    fputs(ime,dat);
    fprintf(dat,"\n");
    fputs(prezime,dat);
    fprintf(dat,"\n");
    fputs(broj,dat);
    fprintf(dat,"\n");
    fclose(dat);

    return 0;
}
