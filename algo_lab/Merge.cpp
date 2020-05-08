#include<bits/stdc++.h>
void display(int *arr,int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void merge(int *arr, int s,int e)
{
    int mid =(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[100];

    while(i<=mid && j<=e){
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else 
            temp[k++]=arr[j++];
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=e)
        temp[k++]=arr[j++];

    for(int i=s;i<=e;i++)
        arr[i]=temp[i];

}
void mergesort(int *arr,int s, int e)
{
    if(s>=e)
        return;
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}
int main(){
    int arr[]={6,3,2,7,1};
    mergesort(arr,0,4);
    display(arr,5);
}