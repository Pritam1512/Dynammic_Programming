#include<iostream>

using namespace std;

int countSubset(int arr[],int n,int w)
{
    int c[n+1][w+1];

    for(int i=0;i<w+1;i++)
    {
        c[0][i] = 0;
    }
    for(int i=0;i<n+1;i++)
    {
        c[i][0] = 1;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(arr[i-1] <=j)
            {
                c[i][j] = c[i-1][j-arr[i-1]] + c[i-1][j];
            }
            else
            {
                c[i][j] = c[i-1][j];
            }
        }
    }

    return c[n][w];

}

int main()
{
    int arr[] = {1, 2, 3, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int c = countSubset(arr,n,6);
    cout << "Number of subsets are : "<<c <<endl;


    return 0;
}
