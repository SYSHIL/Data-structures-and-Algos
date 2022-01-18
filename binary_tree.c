#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode()
{
	// Allocate memory for new node
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
    int num;
    printf("Enter data(-1 if no node) : ");
    scanf("%d",&num);
    if(num==-1)
       return 0;
    node->data=num;
    printf("\nEnter data for left node of %d\n",num);
	node->left = newNode(num);
	printf("\nEnter data for right node of %d\n",num);
	node->right= newNode(num);
    return node;
}

int main()
{   
	struct node* root = newNode();
	return 0;
}

