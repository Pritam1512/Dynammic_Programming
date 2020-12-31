#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int wt[],int n,int W)
{
    int t[n+1][W+1];

    for(int i=0;i<n+1;i++)
    {
        t[i][0] = 0;
    }
    for(int j=0;j<W+1;j++)
    {
        t[0][j] = 0;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
           if(wt[i-1] <= j)
           {
               t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]]
                             ,t[i-1][j]);
           }
           else if(wt[i-1] > j)
           {
               t[i][j] = t[i-1][j];
           }
        }

    }
    return t[n][W];
}

int main()
{
    int wt[] ={11,4,9,6};
    int val[] = {10,40,30, 50};
    int W = 10;

   cout <<  knapsack(val,wt,4,W);
    return 0;
}
