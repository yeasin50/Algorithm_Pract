#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void LCS(char *x, char *y, int m,int n){
    int L[m+1][n+1];

    for(int i=0; i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0) L[i][j]=0;
            else if(x[i-1]==y[j-1]) L[i][j]=L[i-1][j-1]+1;
            else L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }
    int index =L[m][n];
    printf("%d \n",index);

    char lcs[index+1];
    lcs[index]='\0';

    int i=m,j =n;
    while( i>0 && j>0){
        if(x[i-1] == y[j-1]){
            lcs[index-1] = x[i-1];
            i--;j--;index--;
        }
        else if(L[i-1][j] > L[i][j-1])
            i--;
        else j--;
    }

    int f=0;
    while (lcs[f]!=NULL)
    {
        printf("%c",lcs[f]);
        f++;
    }
    
}

int main() 
{ 
  char X[] = "AGGTAB"; 
  char Y[] = "GXTXAYB"; 
  int m = strlen(X); 
  int n = strlen(Y); 
  LCS(X, Y, m, n); 
  return 0; 
} 