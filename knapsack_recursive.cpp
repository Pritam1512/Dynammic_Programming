#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int wt[],int n,int W)
{
    if(n==0 || W == 0)
        return 0;
    if(wt[n-1] <= W)
    {
        return max(val[n-1]+knapsack(val,wt,n-1,W-wt[n-1])
                   ,
                    knapsack(val,wt,n-1,W));
    }
    else if(wt[n-1] > W)
    {
        return knapsack(val,wt,n-1,W);
    }

}

int main()
{
    int wt[] ={11,4,9,6};
    int val[] = {10,40,30, 50};
    int W = 10;

    cout << "Maximum profit from knapsack is :" <<knapsack(val,wt,4,W);
    return 0;
}
