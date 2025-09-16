/******************************************************************************

 3. Write a Menu Driven Program to perform queue operations.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#define maxsize 10
void push(queue[],int *front,int *rear){
    int x;
    if(rear==maxsize-1){
        printf("\nqueue overflow.\nCan't insert anymore.\n");
    }
    printf("\nEnter the element to insert: ");
    scanf("%d",&x);
    queue[rear++]=x;
    //rear++;
    printf("\nElement(%d) inserted on to the queue.\n",queue[front]);
}
void pop(int queue[],int *front,int *rear){
    int x;
    if((front==-1&&rear==-1)||(front>rear)){
        printf("\nqueue underflow.\nCan't delete.")
    }
    x=queue[front];
    rear--;
    printf("deleted %d",x);
}
void peek(int queue[],int *front,int *rear){
    if((front==-1&&rear==-1)||(front>rear)){
        printf("\nqueue underflow.\nNothing to display.\n");
    }
    printf("\nLast element of queue: %d",queue[rear]);
}
void display(int queue[],int front,int rear){
    if(front<=-1){
        printf("\nqueue underflow.\nNothing to displayy.");
    }
    for(int i=0;i<n;i++){
        printf("Element(%d)",i+1);
        printf("%d",queue[i]);
    }
}
int main()
{   int n,i,queue[maxsize],rear,front=-1;
    int rear=-1;
    // printf(" N=? ");
    // scanf("%d",&n);
    while(1){
        printf("\n................queue operations.....................\n1. Insert an element.\n2. Delete an element.\n3. peek.\n4. display.\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1 :    push(queue,&front,&rear);
                        break;
            case 2 :    pop(queue,&front,&rear);
                        break;
            case 3 :    peek(queue,&front,&rear);
                        break;
            case 4 :    display(queue,front,rear);
                        break;
            default:    printf("invalid choice!\nexiting.......");
                        exit(0);
        }
    }
    return 0;
}