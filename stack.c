#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char data;
    struct node* next;
    
};
#define TRUE (1==1)
#define FALSE (1==2)
int isoperator(char operator);
void push(struct node** top_ref, char new_data);
char pop(struct node** top_ref);
int lookup_precedence(char operator);
int is_stack_empty(struct node** top_ref);
char peek(struct node** top_ref){
    return (*top_ref)->data;
}
int isoperator(char operator){
    if(operator=='+'||operator=='-'||operator=='*'||operator=='/'||operator=='('||operator==')'||operator=='^')
       return 1;
    else
       return 0;
}
int lookup_precedence(char operator){
    switch(operator)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
}
void push(struct node** top_ref, char new_data)
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
int is_stack_empty(struct node** top_ref){
    if(*top_ref==NULL)
       return 1;
    else
       return 0;
}
// Function to pop an item from stack
char pop(struct node** top_ref)
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

int main(){
    char expression[20];
    int pos_expression=0;
    printf("Enter your expression : ");
    scanf("%s",expression);
    struct node* top=NULL;
    char output;
    while(expression[pos_expression]!='\0')
    {   
        char character=expression[pos_expression];
        if(isoperator(character)){
             
            if(is_stack_empty(&top))
                push(&top,character);
            
            else if(character=='(') 
                push(&top,character);// "(" is highest precedence anyway no need to pop anything
            else if(character==')'){ // closing brackets never stay in the stack
                while((output=pop(&top))!=')')
                    printf("%c",output);
            }
            else{
                while(peek(&top)!='(' && lookup_precedence(character)<=lookup_precedence(peek(&top))){
                    output = pop(&top);
                    printf("%c",output);
                }
                push(&top,character);
            }
        }
        else{
            printf("%c",character); //operands are simply printed
        }

        pos_expression++;
    }
    while(!is_stack_empty(&top)){
        output=pop(&top);
        printf("%c",output);
    }
return 0;
} 
