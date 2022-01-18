/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define N 5
void enqueue(int[],int*,int*,int);
void dequeue(int[],int*,int*);
int main()
{
    int queue[N];
    int front=-1,rear=-1;
    enqueue(queue,&front,&rear,5);
    enqueue(queue,&front,&rear,6);
    dequeue(queue,&front,&rear);
    dequeue(queue,&front,&rear);
    dequeue(queue,&front,&rear);

    return 0;
}
void enqueue(int queue[],int* front, int* rear,int x){
    if(*rear==N-1)
        printf("queue is full");
    else if(*rear==-1 && *front==-1){
        *rear=*front=0;
        queue[(*rear)]=x;
    }
    else{
        (*rear)++;
        queue[(*rear)]=x;
    }
}
void dequeue(int queue[],int* front, int* rear){
    if(*front==-1 && *rear==-1)
        printf("queue is empty");
    else if(*front==*rear){
        printf("%d",queue[(*front)]);
        *front=*rear=-1;
    }
    else{
        printf("%d",queue[*front]);
        (*front)++;
    }
    
}