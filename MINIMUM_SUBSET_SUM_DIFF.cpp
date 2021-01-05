#include<iostream>

using namespace std;

bool subset_sum(int arr[],int n,int sum)
{
    bool t[n+1][sum+1];
     for (int i = 0; i <= n; i++)
        t[i][0] = true;

    for (int i = 1; i <= sum;i++)
            t[0][i] = false;


    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else if(arr[i-1] > j)
                t[i][j] = t[i-1][j];
        }
    }


    return t[n][sum];
}

int main()
{
    int n;
    cin >> n;
    int arr[n],sum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i] ;
        sum += arr[i];
    }
    int range = sum/2,diff;
    for(int j=range;j>=0;j--)
    {
        if(subset_sum(arr,n,j))
        {
            diff = sum - (2*j);
            break;
        }
    }
    cout << diff <<endl;



    return 0;
}
