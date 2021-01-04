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

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            cout << t[i][j] <<" ";
        }
        cout << "" << endl;
    }
    return t[n][sum];
}

int main()
{
    int arr[] = {1,2,7};
    int sum = 9;
    bool c = subset_sum(arr,3,sum);
   //if(c == true)
    //    cout << "subset is present"<<endl;
  // else
     //   cout << "Not present "<<endl;
    return 0;
}
