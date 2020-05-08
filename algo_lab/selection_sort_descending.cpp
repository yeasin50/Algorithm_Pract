
#include <stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n, i, step;
    scanf("%d",&n);
    int arr[n+1];

    for(i=1; i<=n; i++)
        scanf("%d",&arr[i]);

    for(step=1; step<=n;step++)
        {
            int max_poss = step;
            for( i =step+1; i<=n;i++){
                if(arr[i]>arr[max_poss])
                    max_poss=i;
            }

            swap(arr[step],arr[max_poss]);

            for(i=1; i<=n; i++)
                printf("%d ",arr[i]);

            printf("\n");// make sure of it

        }
return 0;

}
