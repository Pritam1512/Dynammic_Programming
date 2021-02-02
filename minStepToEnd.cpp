#include<bits/stdc++.h>
using namespace std;

int countWay(int arr[],int n)
{

    int dp[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] =0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<=i+arr[i] && j<n;j++)
        {
           dp[j] = min(dp[j] , dp[i]+1);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << dp[i] << " ";
    }

}

int main()
{
    int arr[] = {1,3,5,8,9,2,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

     countWay(arr,10);
    return 0;
}
