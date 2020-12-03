
#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
} node;


void create(node** head, int new_data)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data  = new_data;
    newNode->next = (*head);
    (*head)    = newNode;
}


void deleteNode(node **head, int position)
{
    if (*head == NULL)
        return;

    node* pom = *head;

    if (position == 0)
    {
        *head = pom->next;
        free(pom);
        return;
    }


    for (int i=0; pom!=NULL && i<position-1; i++)
        pom = pom->next;


    if (pom == NULL || pom->next == NULL)
        return;


    node *next = pom->next->next;


    free(pom->next);

    pom->next = next;
}

void printList(node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}


int main()
{

    node* head = NULL;

    create(&head, 7);
    create(&head, 1);
    create(&head, 3);
    create(&head, 2);
    create(&head, 8);

    puts("Lista: ");
    printList(head);
    deleteNode(&head, 2);
    puts("\nLista posle brisanja: ");
    printList(head);
    return 0;
}
