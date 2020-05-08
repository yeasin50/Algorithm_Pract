#include<bits/stdc++.h>
 void display(int *arr, int n)
 {
     for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
 }
 void quicksort(int number[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=last;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
    
      quicksort(number,first,j-1);
     
      quicksort(number,j+1,last);

   }
}
 int main()
 {
   int arr[]={2,4,5,1,34,0,54};
    int n = sizeof(arr)/sizeof(arr[0]);
   quicksort(arr,0,5);
    display(arr,n);
 }