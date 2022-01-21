#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* left;
	struct node* right;
};

// A Linked List Node for queue
struct queue_Node
{
    int data;               // integer data
    struct Node* next;      // pointer to the next node
}*rear = NULL, *front = NULL;
 
// function to allocate the new queue node
struct queue_Node* newNode_queue(int item)
{
    // allocate a new node
    struct queue_Node* node = (struct Node*)malloc(sizeof(struct Node));
 
    // check if the queue (heap) is full. Then inserting an element would
    if (node != NULL)
    {
        // set data in the allocated node and return it
        node->data = item;
        node->next = NULL;
        return node;
    }
    else {
        printf("\nHeap Overflow");
        exit(EXIT_FAILURE);
    }
}
 
int dequeue()        // delete at the beginning
{
    if (front == NULL)
    {
        printf("\nQueue Underflow");
        exit(EXIT_FAILURE);
    }
 
    struct queue_Node* temp = front;
    printf("Removing %d\n", temp->data);
 
    // advance front to the next node
    front = front->next;
 
    // if the list becomes empty
    if (front == NULL) {
        rear = NULL;
    }
 
    // deallocate the memory of the removed node and optionally return the removed item
    int item = temp->data;
    free(temp);
    return item;
}
 
// function to add an item to the queue
void enqueue(int item)        // insertion at the end
{
    // allocate a new node in a heap
    struct queue_Node* node = newNode(item);
    printf("Inserting %d\n", item);
 
    // special case: queue was empty
    if (front == NULL)
    {
        // initialize both front and rear
        front = node;
        rear = node;
    }
    else {
        // update rear
        rear->next = node;
        rear = node;
    }
}
 
// function to return the top element in a queue
int peek()
{
    // check for an empty queue
    if (front != NULL) {
        return front->data;
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
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
void Level_Order(struct node* root){
    
}
int main()
{   
	struct node* root = newNode();
	return 0;
}
