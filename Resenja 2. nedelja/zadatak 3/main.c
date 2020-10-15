#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prebroj(FILE* dat)
{
    char niz[1000], slovo;
    int broj = 0;
    int j=1, i=0;
    int niz1[1000];
    int rec,m;
    char najveca[1000];
    for(;;)
    {
        slovo = fgetc(dat);
        if (slovo == EOF)
            break;
        if(slovo != 32 && slovo != 12 && slovo >= 32 && slovo < 127)
        {
            if ( j == 1)
            {
                broj ++;
                i=0;
            }
            j = 0;
            i++;
        }
        else
        {
            if(broj != 0)
            {
                niz1[broj-1] = i;

            }

            j = 1;

        }

    }
    niz1[broj-1] = i;
    rec = niz1[0];
    m=0;
    for (i=1; i<broj+1; i++)
    {
        if(rec<niz1[i])
        rec = niz1[i];
        m = i;
        }
        i=0;
for(;;)
    {
        slovo = fgetc(dat);
        if (slovo == EOF)
            break;
        if(slovo != 32 && slovo != 12 && slovo >= 32 && slovo < 127)
        {
            if ( j == 1)
            {
                broj ++;

            }
            if(broj == m)
            {
                najveca[i] = slovo;

            }


            j = 0;
            i++;
        }
        else
        {


            j = 1;

        }

    }
    najveca[i] = '\n';
    FILE* dat1 = fopen("tekst2.txt","w");
    fprintf(dat1,"%i\n",broj);
    fputs(najveca,dat1);
    fclose(dat1);
    return broj;
}



int main()
{
    char niz[100];
ponovo:
    printf("Unesite naziv datoteke: ");
    gets(niz);
    FILE* dat = fopen(niz, "r");
    if (dat == NULL)
        goto ponovo;
    printf("broj reci je: %i", prebroj(dat));





    return 0;
}
