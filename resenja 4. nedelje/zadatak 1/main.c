#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char * niz = (char*) malloc (sizeof(char));
char c;
int i;
printf("unesite string: ");
for(i=0;;i++){
    scanf("%c",&c);
    if (c == '\n'){
        niz[i] = '\0';
        break;
    }
    niz[i] = c;
    niz = realloc(niz, (i+1)*sizeof(char));
}
char* niz2 = malloc(strlen(niz)*sizeof(char));
strcpy  (niz2,niz);
strupr(niz2);
puts(niz2);
free(niz);
free(niz2);

    return 0;
}
