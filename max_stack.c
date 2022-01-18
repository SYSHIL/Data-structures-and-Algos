/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//largest element in stack
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

	if (new_node == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}

	// put in the data
	new_node->data = new_data;

	// link the old list off the new node
	new_node->next = (*top_ref);

	// move the head to point to the new node
	(*top_ref) = new_node;
}

// Function to pop an item from stack
int pop(struct node** top_ref)
{
	char res;
	struct node* top;

	// If stack is empty then error
	if (*top_ref == NULL) {
		printf("Stack overflow n");
		getchar();
		exit(0);
	}
	else {
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}
int maximum(struct node** top_ref){
    int max=(*top_ref)->data;
    struct node* trav = (*top_ref);
    while(trav){
        if(trav->data>max){
            max=trav->data;
        }
        trav=trav->next;
    }
    return max;
}
int main()
{   struct node* head=NULL;
    push(&head,20);
    push(&head,30);
    push(&head,50);
    push(&head,32);
    printf("%d",maximum(&head));
    return 0;
}