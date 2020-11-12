#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node* next;
};
void push(struct Node** head,int data){

struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = data;
new_node->next = (*head);
(*head) = new_node;
}
void countNode(struct Node* head){
int counter = 1;
struct Node* pom;
pom = head;
while(pom->next != NULL){
    pom = pom->next;
    counter ++;
}
printf("\nOva lista ima %i clanova",counter);
}
void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main()
{
struct Node* head = NULL;
push(&head,7);
push(&head,6);
push(&head,5);
push(&head,4);
push(&head,3);
push(&head,2);
push(&head,1);
printf("Lista: \n");
printList(head);
countNode(head);

    return 0;
}
