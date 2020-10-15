#include <stdio.h>
#include <stdlib.h>

int main()
{
    char slovo1;
    char slovo2;
    int i=0;
    FILE* dat = fopen("primer.txt","r");
    printf("Unesite slovo: ");
    scanf("%c",&slovo1);
    for(;;)
    {
        slovo2 = fgetc(dat);
        if (slovo2 == EOF)
        break;
        if (slovo2 == slovo1)
            i++;
    }
    printf("Slovo  %c  se ponavlja  %i  puta u tekstu.", slovo1, i);
    return 0;
}
