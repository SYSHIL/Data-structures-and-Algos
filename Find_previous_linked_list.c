#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// Insert a node at the beginning
struct node{
    int data;
    struct node* next;
};
typedef struct node node;
node* head;
void insert(int x){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data=x;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
void print(){
    
    while(head){
          printf("%d\n",head->data);
          head=head->next;
    }
}
int findprev(int key){//no need to pass head as it is global
    node* tmp = head;
    int prev;
    while(tmp->next!=NULL){
        if(tmp->next->data==key){
            prev=tmp->data;
            return prev;
        }
    }
    return -1;// element not found
}
 // List is empty
int main()
{   sleep(10);
     head=NULL;
    printf("Enter number of nodes:");
    int num_of_nodes,i,insert_num;
    scanf("%d",&num_of_nodes);
    for(i=0;i<num_of_nodes;i++){
        printf("\nEnter data to be inserted at the beginning of the list:");
        scanf("%d",&insert_num);
        insert(insert_num);
    }
    printf("\nEnter key value : ");
    int key;
    scanf("%d",&key);
    printf("\nPrevious value of %d is %d",key,findprev(key));
    return 0;
}
