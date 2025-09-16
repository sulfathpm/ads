#include <stdio.h>
#include <stdlib.h>

// Function to display array
void display(int a[], int n) {
    printf("\nArray elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Linear search function
void linear(int a[], int n) {
    int x, i, found = 0;
    printf("\nEnter the element to search: ");
    scanf("%d", &x);
    
    for(i = 0; i < n; i++) {
        if(a[i] == x) {
            printf("%d found at position %d.", x, i+1);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Element not found!");
    }
}

// Bubble sort function
void sort(int a[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Binary search function (recursive)
void binary(int a[], int x, int low, int high) {
    if(low <= high) {
        int mid = (high + low) / 2;
        
        if(a[mid] == x) {
            printf("\nElement(%d) found at position %d", x, mid+1);
        } else if(a[mid] > x) {
            binary(a, x, low, mid-1);
        } else {
            binary(a, x, mid+1, high);
        }
    } else {
        printf("Element not found!");
    }
}

int main() {
    int i, n, a[10], ch, x;
    
    printf("N=? ");
    scanf("%d", &n);
    
    printf("\nEnter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    while(1) {
        printf("\n.........operations................\n");
        printf("1. Linear search\n");
        printf("2. Binary search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1: 
                linear(a, n);
                break;
            case 2: 
                sort(a, n); // Sort the array first
                printf("\nEnter the element to search: ");
                scanf("%d", &x);
                binary(a, x, 0, n-1);
                break;
            case 3: 
                display(a, n);
                break;
            case 4:
                printf("exiting.....");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}