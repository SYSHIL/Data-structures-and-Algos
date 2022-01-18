// Iterative C program to reverse a linked list
#include <stdio.h>
#include <stdlib.h>
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
/* Function to reverse the linked list */
void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* next = NULL;
    struct Node* curr = *head_ref;
    while (curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head_ref=prev;   
}
 
/* Function to push a node */
void insert_end(struct Node** head_ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=NULL;
    if(*head_ref==NULL){
        *head_ref=new_node;
        return;
    }
    struct Node* trav = (*head_ref);
    while(trav->next!=NULL){
        trav=trav->next;
    }
    trav->next=new_node;
}
 
/* Function to print linked list */
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL; 
    insert_end(&head, 20);
    insert_end(&head, 4);
    insert_end(&head, 15);
    printf("Given linked list\n");
    printList(head);
    reverse(&head);
    printf("\nReversed Linked list \n");
    printList(head);
    getchar();
}
