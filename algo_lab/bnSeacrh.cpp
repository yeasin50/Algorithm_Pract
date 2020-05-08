#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void display(int *arr, int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}

void InsertionSort(int *arr,int n)
{
    for(int step=1; step<n; step++){
        int key = arr[step],i;

        for(i =step-1; i>=0 && arr[i]>key; i--)
            arr[i+1]= arr[i];
        arr[i+1]= key;
    }
}
void bianry(int *arr,int n,int search)
{   
    int s=0,e=n-1;
    while(s<=e){
        int mid= (s+e)/2;
        if(search == arr[mid]){
            printf("\nData Found at poss: %d\n",mid);
            break;
        }
        else if(arr[mid]>search)e=mid-1;
        else s=mid+1;
        printf("Mid %d ",mid);

    }

    
}
int main()
{
    int arr[]= {2,5,6,1,5,7,1,0};
    int n = sizeof(arr)/sizeof(arr[0]),search;
    InsertionSort(arr,n);
   //sort(arr,arr+n);
    display(arr, n);
     printf("\nEnter Element: ");
    scanf("%d",&search);
    bianry(arr,n,search);
    display(arr, n);



}
