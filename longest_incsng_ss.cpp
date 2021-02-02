#include<bits/stdc++.h>
using namespace std;

int lis(int arr[],int n)
{
    int dp[n];
    for(int i=0;i<n;i++)
    {
        dp[i] =1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i] )
            {
                dp[i] = max(dp[j] +1,dp[i]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << dp[i] <<" ";
    }
}

int main()
{
    int arr[] = {3,4,1,5,2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
   lis(arr,n);
}

