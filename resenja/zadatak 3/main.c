#include <stdio.h>
#include <stdlib.h>

int ponavljanja(char* s, char slovo){
int i,broj=0;



for (i=0;i<100;i++){
        if(s[i]=='\0')
        break;
    if (slovo==s[i])
    broj++;
}

return broj;
}

int main()
{
char slovo,s[100];
printf("unesite string: ");
gets(s);
printf("unesite slovo: ");
scanf("%c",&slovo);
printf("slovo  %c  se ponavlja  %i  puta u stringu.", slovo, ponavljanja(s,slovo));

     return 0;
}
