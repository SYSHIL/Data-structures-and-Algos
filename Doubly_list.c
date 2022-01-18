#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
typedef struct node node;
void create(node** head_ref,node** tail_ref, int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data=data;
    if(*head_ref==NULL){
        *head_ref=*tail_ref=newnode;
    }
    else{
        (*tail_ref)->next=newnode;
        newnode->prev=*tail_ref;
        *tail_ref=newnode;
    }
}
void print(node** head_ref){ //O(n)
    node* temp=*head_ref;
    while(temp){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void insert_end(node** head_ref,node **tail_ref,int data){ // O(1)
    node* insert_end_node = (node*)malloc(sizeof(node));
    insert_end_node->data=data;

    if(*head_ref==NULL){
        *head_ref=*tail_ref=insert_end_node;
    }
    else{
    insert_end_node->prev=*tail_ref;
    (*tail_ref)->next=insert_end_node;
    *tail_ref=insert_end_node;
    }
}
void insert_beginning(node** head_ref,node** tail_ref,int data){
    node* insert_beg_node = (node*)malloc(sizeof(node));
    insert_beg_node->data=data;

    if(*head_ref==NULL){
        *head_ref=*tail_ref=insert_beg_node;
    }
    else{
        (*head_ref)->prev=insert_beg_node;
        insert_beg_node->next=*head_ref;
        *head_ref=insert_beg_node;
    }
}
int main(){
    node *head=NULL;
    node* tail=NULL;
    insert_end(&head,&tail,40);
    create(&head,&tail,10);
    create(&head,&tail,10);   
    print(&head);
    printf("\n");
    insert_end(&head,&tail,40);
    print(&head);
    printf("\n");
    insert_beginning(&head,&tail,20);
    print(&head);
    printf("\n");
    return 0;
}
