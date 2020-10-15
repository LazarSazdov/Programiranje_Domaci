#include <stdio.h>
#include <stdlib.h>

int main()
{
    char niz1[100], niz2[100];
    char slovo;

    pon1:
    gets(niz1);
    FILE* dat1 = fopen(niz1,"r");
    if (dat1 == NULL)
        goto pon1;

    pon2:
    gets(niz2);
    FILE* dat2 = fopen(niz2,"r");
    if (dat2 == NULL)
    goto pon2;

    FILE* dat3 = fopen("Tekst3.txt","w");

    for(;;){
        slovo = fgetc(dat1);
        if (slovo == EOF)
            break;
        fputc(slovo, dat3);

    }
for(;;){
        slovo = fgetc(dat2);
        if (slovo == EOF)
            break;
        fputc(slovo, dat3);

    }
    fclose(dat1);
    fclose(dat2);
    fclose(dat3);

    return 0;
}
