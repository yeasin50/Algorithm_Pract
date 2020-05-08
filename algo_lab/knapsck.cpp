#include<bits/stdc++.h>
#include<algorithm>
using namespace std; 
int knapSack(int totalW, int weight[], int val[], int n)
{
   int K[n+1][totalW+1];
 
   for (int i = 0; i <= n; i++)
   {
       for (int w = 0; w <= totalW; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (weight
        [i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-weight
                [i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][totalW];
}
 
int main()
{
    int i, n, val[20], weight[20], totalW;
    
    printf("Enter number of items:");
    scanf("%d", &n);
    
    printf("Enter value and weight of items:\n");
    for(i = 0;i < n; ++i){
    	scanf("%d%d", &val[i], &weight[i]);
    }
 
    printf("Enter size of knapsack:");
    scanf("%d", &totalW);
    
    printf("%d", knapSack(totalW, weight, val, n));
    return 0;
}