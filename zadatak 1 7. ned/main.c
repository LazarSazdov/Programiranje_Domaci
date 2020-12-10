//Spregnuta realizacija steka celobrojnih vrednosti
//upotrebom jednostruko spregnute liste
#include <stdio.h>
#include <stdlib.h>


//Definicija tipova
typedef int TIP;
typedef struct cvor_st
{
  TIP inf;
  struct cvor_st *sledeci;
} SCVOR;

//1.Push funkcija
void push(TIP inf, SCVOR **vrh)
{
  SCVOR *novi;
  novi = (SCVOR *)malloc(sizeof(SCVOR));
  novi->inf = inf;
  novi->sledeci = *vrh;
  *vrh = novi;
}

//2.Pop funkcija

TIP Pop(SCVOR** head){

    int counter = 0;
    if(*head == NULL){
        return -1;
    }
    SCVOR* temporary;
    temporary = (SCVOR*)malloc(sizeof(SCVOR));
    temporary = *head;

    counter = temporary->inf;
    *head = temporary->sledeci;
    free(temporary);
    return counter;
}

//3.Top funkcija
TIP top(SCVOR *vrh)
{
  if (vrh == NULL)
    return -1;
  return vrh->inf;
}

//4.Brisanje steka
void obrisi_stek(SCVOR *vrh)
{
  if (vrh!= NULL)
  {

    obrisi_stek(vrh->sledeci);
    printf("brisemo element: %i\n", vrh->inf);
    free(vrh);
  }
}

//5.Ispis steka
void ispisi_stek(SCVOR *vrh)
{
  if (vrh != NULL)
  {
    printf("element: %i\n", vrh->inf);
    ispisi_stek(vrh->sledeci);
    printf("Sam sebe cekam");
  }
}

int main()
{
  /* vrh steka je lokalna promenljiva */
  SCVOR *vrh;
  TIP i, odg;

  /* inicijalizacija praznog steka*/
  vrh = NULL;

  do {

    printf("\n   Opcije:\n");
    printf("\t1. Smestanje na stek - push.\n");
    printf("\t2. Skidanje sa steka - pop.\n");
    printf("\t3. Pristup prvom elementu - top.\n");
    printf("\t4. Prikaz sadrzaja celog steka.\n");
    printf("\t5. Kraj.\n");
    printf("\n\t>> ");
    scanf("%d", &odg);

    switch( odg ) {
        case 1: printf("Unesite pozitivan ceo broj: ");
                scanf("%d", &i);
                push(i, &vrh);
                break;
        case 2: i = Pop(&vrh); /* pokupimo jedan element sa steka */
                printf("Skinuli sa steka: %i\n", i);
                break;
        case 3: printf("Na vrhu steka je %i\n", top(vrh)); /* pogledamo sta je na vrhu steka */
                break;
        case 4: ispisi_stek(vrh); /* ispisemo sadrzaj stabla*/
                break;
    }
  } while ( odg!=5 );

  /* obrisemo stek */
  obrisi_stek(vrh);
  vrh = NULL;

  return 0;
}
