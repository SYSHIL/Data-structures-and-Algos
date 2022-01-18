#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
    
};
void push(struct node** top_ref, int new_data)
{
	// allocate node
	struct node* new_node
		= (struct node*)malloc(sizeof(struct node));
	// put in the data
	new_node->data = new_data;

	// link the old list off the new node
	new_node->next = (*top_ref);

	// move the top to point to the new node
	(*top_ref) = new_node;
}

// Function to pop an item from stack
void pop(struct node** top_ref)
{
	int res;
	struct node* removed_top;
     
	// If stack is empty then error
	if (*top_ref == NULL) {
		printf("\n-1 - Stack is empty");
	}
	else {
		removed_top = *top_ref;
		res = removed_top->data;
		*top_ref = removed_top->next;
        printf("\nRemoved : %d",res);
		free(removed_top);
	}
}
void delete_stack(struct node** top_ref){//function to delete stack and free memory
    struct node* trav;
    while((*top_ref)!=NULL){
        trav = *top_ref;
        *top_ref=(*top_ref)->next;
        free(trav);
    }
}
int main()
{   int test_cases,query_type,queries;
    int data;
    printf("Enter number of testcases : ");//number of testcasesint
    scanf("%d",&test_cases);
    while(test_cases--){
        printf("\n\t\t\tNew stack of books created!");
        struct node* top=NULL;
        printf("\nType 1 query involves placing a book at the top of a stack\nType 2 query involves removing a book from top of the stack\nand displaying its number");
        printf("\nPlease enter number of queries for newly created stack of books : ");
        scanf("%d",&queries);
        while(queries--){
           printf("\nEnter query type : ");
           scanf("%d",&query_type);
           if(query_type==1){
               printf("\nPlace : ");
               scanf("%d",&data);
               push(&top,data);
           }
           else if(query_type==2){
               pop(&top);
           }
           else{
               printf("\nPlease enter correct query number");
           }
        }
        delete_stack;//delete stack
    }
    
    return 0;
}