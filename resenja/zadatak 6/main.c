#include <stdio.h>
#include <stdlib.h>
void unos(int* pok, int r, int k, int a)
{
    int i,j;



    for(j=0; j<k; j++)
    {

        scanf("%i",pok+j);
    }


}

void ispis(int* pok,int k,int r){

    int i,j;

        for(j=0;j<k;j++){
            printf("%i ",*(pok+j));


    }
        printf("\n");
}


void sabiranje(int* pok1, int* pok2,int* pok3, int r, int k)
{
    int j;
    for (j=0; j<k; j++)
        *(pok3+j) = *(pok1+j) + *(pok2+j);


}

int main()
{
    int r,k;
    int i,j;
    printf("Unesite broj redova matrice: ");
    scanf("%i",&r);
    printf("Unesite broj kolona matrice: ");
    scanf("%i",&k);
    int mat1[r][k];
    int mat2[r][k];
    int mat3[r][k];
    printf("Unesite 1. matricu: \n\n");
    for (i=0; i<r; i++)
        unos(*(mat1+i),r,k,1);
    printf("Unesite 2. matricu: \n\n");
    for (i=0; i<r; i++)
        unos(*(mat2+i),r,k,1);
    for (i=0; i<r; i++)
        sabiranje(*(mat1+i),*(mat2+i),*(mat3+i),r,k);
        printf("\n\n*****************************\n\n");
    for (i=0; i<r; i++)
        ispis(*(mat3+i),r,k);
    return 0;
}
