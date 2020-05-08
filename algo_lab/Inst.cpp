#include<bits/stdc++.h>

void display(int *arr,int n){
    for (int i=0; i<n;i++)
        printf("%d ",arr[i]);
   printf("\n");
}

void insertionSort(int *arr,int n){
    for(int step = 1; step<n; step++){
        int key = arr[step],i;

        for(i=step-1; i>=0 && arr[i]>key;i--)
            arr[i+1] = arr[i];
        arr[i+1]=key;
    }
}
int main()
{
    int arr[]={2,4,5,1,34,0,54};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,n);
    display(arr,n);
}