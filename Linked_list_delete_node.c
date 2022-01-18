#include<stdio.h>
#include<stdlib.h>
// Insert a node at the beginning
struct node{
    int data;
    struct node* next;
};
typedef struct node node;
node* head = NULL;
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
void delete_node(int key){
    node* temp = head,*prev;
    if(temp!=NULL && temp->data==key){
        head=temp->next;
        free(temp);
        return;
    }
    while (temp!=NULL && temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp!=NULL){
        prev->next = temp->next;
        free(temp);
        return;
    }
    
}
void print(){
    node* temp = head;
    while(temp){
          printf("%d\n",temp->data);
          temp=temp->next;
    }
}
int main(){
    printf("Enter number of nodes:");
    int num_of_nodes,i,insert_num;
    scanf("%d",&num_of_nodes);
    for(i=0;i<num_of_nodes;i++){
        printf("\nEnter data to be inserted:");
        scanf("%d",&insert_num);
        insert(insert_num);
    }
    int key;
    print();
    scanf("%d",&key);
    delete_node(key);
    print();
    return 0;
}