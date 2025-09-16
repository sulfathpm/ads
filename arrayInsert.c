#include<stdio.h>
void insertAtBegin(int a[],int n){ 
    int x;
    printf("\nEnter the element to be inserted at beginning : ");
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        a[i]=a[i-1];
    }
    a[0]=x;
    printf("\nElement is inserted at begining");
}
void insertAtEnd(int a[],int n){
    int x;
    printf("\nEnter the element to be inserted at the end : ");
    scanf("%d",&x);
    a[n]=x;
}
void insertAtPos(int a[],int n){
     int x,y;
    printf("\nEnter the position of the element : ");
    scanf("%d",&x);
    printf("\nEnter the element : ");
    scanf("%d",&y);
    for(int i=x;i<=n;i++){
        a[i]=a[i-1];
    }
    a[x]=y;
}
void Display(int a[],int n){
    printf("\nThe array elements are : ");
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
}
int main(void){
    int a[20],i,x,ch,n;
    printf("\nN=?");
    scanf("%d",&n);
    printf("\nEnter the elements of the array : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    while(1){
        printf("\n--------operation-----------\n1.Insert at the beginning.\n2.Insert at the end.\n3.Insert at a position provided by the user.\n4.Display the array.\nEnter a choice (1 to 4) : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 :    insertAtBegin(a,n);
                        break;
            case 2 :    insertAtEnd(a,n);
                        break;
            case 3 :    insertAtPos(a,n);
                        break;
            case 4 :    Display(a,n);
                        break;
            case 0 :    printf("exiting....");
                        exit(0);
            default:    printf("\nInvalid choice"); 
                        break;
        }
    }
}