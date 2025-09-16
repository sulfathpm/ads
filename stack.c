/******************************************************************************

 3. Write a Menu Driven Program to perform Stack operations.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#define maxsize 10
void push(stack[],int *top){
    int x;
    if(top==maxsize-1){
        printf("\nStack overflow.\nCan't insert anymore.\n");
    }
    printf("\nEnter the element to insert: ");
    scanf("%d",&x);
    stack[top]=x;
    top++;
    printf("\nElement(%d) inserted on to the satck.\n",stack[top]);
}
void pop(int stack[],int *top){
    int x;
    if(top<=-1){
        printf("\nStack overflow.\nCan't delete.")
    }
    x=stack[top];
    top--;
    printf("deleted %d",x);
}
void peek(int stack[],int *top){
    if(top<=-1){
        printf("\nStack underflow.\nNothing to display.\n");
    }
    printf("\nTop element of stack: %d",stack[top]);
}
void display(int stack[],int top){
    if(top<=-1){
        printf("\nStack underflow.\nNothing to displayy.");
    }
    for(int i=0;i<n;i++){
        printf("Element(%d)",i+1);
        printf("%d",stack[i]);
    }
}
int main()
{   int n,i,stack[maxsize],top=-1;
    // printf(" N=? ");
    // scanf("%d",&n);
    while(1){
        printf("\n................stack operations.....................\n1. Insert an element.\n2. Delete an element.\n3. peek.\n4. display.\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1 :    push(stack,&top);
                        break;
            case 2 :    pop(stack,&top);
                        break;
            case 3 :    peek(stack,&top);
                        break;
            case 4 :    display(stack,top);
                        break;
            default:    printf("invalid choice!\nexiting.......");
                        exit(0);
        }
    }
    return 0;
}