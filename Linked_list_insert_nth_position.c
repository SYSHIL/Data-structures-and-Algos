#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
// Insert a node at nth position
struct node{
    int data;
    struct node* next;
};
typedef struct node node;
node* head;
void insert(int data,int n){
    node* temp1 = (node*)malloc(sizeof(node));
    temp1->data=data;
    temp1->next=NULL;
    if(n==1){
        temp1->next=head;
        head=temp1;
        return;
    }
    node *temp2 = head;
    int i;
    for(i=0;i<n-2;i++){
        temp2 = temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}
void print(){
      
    while(head){
          printf("%d\n",head->data);
          head=head->next;
    }
}
int main(){
    head=NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    print();
}