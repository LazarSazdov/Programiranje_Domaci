#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} node;

void inSort(node** head, node* newNode)
{
    node* current;
    if (*head == NULL || (*head)->data >= newNode->data)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        current = *head;
        while (current->next!=NULL &&
                current->next->data < newNode->data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void insertionSort(node **head)
{
    node *sorted = NULL;
    node *current = *head;
    while (current != NULL)
    {
        node *next = current->next;
        inSort(&sorted, current);
        current = next;
    }
    *head = sorted;
}



void printList(node *head)
{
    node *pom = head;
    while(pom != NULL)
    {
        printf("%d  ", pom->data);
        pom = pom->next;
    }
}

void push(node** head, int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data  = data;
    newNode->next = (*head);
    (*head)    = newNode;
}

int main()
{
    node *a = NULL;
    push(&a, 1);
    push(&a, 25);
    push(&a, 42);
    push(&a, 3);
    push(&a, 10);
    printf("Lista pre sortiranja: \n");
    printList(a);
    insertionSort(&a);
    printf("\nLista posle sortiranja \n");
    printList(a);
    return 0;
}
