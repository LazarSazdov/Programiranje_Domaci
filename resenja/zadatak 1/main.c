#include <stdio.h>
#include <stdlib.h>

int main()
{
int n;
printf("unesite duzinu matrice ");
scanf("%i", &n);
printf("unesite matricu\n");
float mat[n][n];
int i,j;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
     scanf("%f",&mat[j][i]);

    }
}
printf("transponovana matrica izgleda ovako: \n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
     printf("%.1f ",mat[i][j]);

    }
    printf("\n");
}



    return 0;
}
