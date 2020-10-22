#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ime[100];
ponovo:
    printf("Unesite naziv datoteke: ");
    gets(ime);
    FILE* dat = fopen (ime , "r+");
if (dat == NULL)
goto ponovo;
    char c;

    for(;;){
        c = fgetc(dat);
        if (c == EOF)
            break;
        else if (c >= 'a' &&  c <= 'z')
            {c -= 32;
            fseek(dat,-1,SEEK_CUR);
        fputc(c,dat);
            fseek(dat,0,SEEK_CUR);
            }
    }
	fclose(dat);
    return 0;
}
