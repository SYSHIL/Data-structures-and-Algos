// Program to find height of a binary tree, recursive solution

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
int max(int leftheight,int rightheight){
    if(leftheight>rightheight)
       return leftheight;
    else
       return rightheight;
}
int Findheight(struct node* root){
    if(root==NULL)
       return 0;
    int leftheight = Findheight(root->left);
    int rightheight = Findheight(root->right);
    return max(leftheight,rightheight)+1;

}
int main()
{   
	struct node* root = newNode();
	printf("%d",Findheight(root));
	return 0;
}
