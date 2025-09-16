#include<stdio.h>
void selection(int a[]){
    int i,j,min,temp,loc;
    for(i=0;i<n;i++){
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++){
            if(min>a[j]){
                min=a[j];
                loc=j;
            }
        }
        temp=a[j];
        a[j]=a[i];
        a[i]=temp;
    }
}
void bubble(int a[]){
    for(i=0;i<n;i++){
        for(j=1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void display(int a[]){
    printf("\nElements:");
    for(int i=0;i<n;i++){
        printf("\t%d\t",a[i]);
    }
}