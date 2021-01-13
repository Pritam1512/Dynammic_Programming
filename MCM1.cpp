#include<bits/stdc++.h>
using namespace std;

//MCM USING RECURSION AND MEMOIZATION

int t[1001][1001];
int findMCMRec(int arr[],int i,int j)
{
     int minE = INT_MAX;
    if(i>=j)
        return 0;
   for(int k=i;k<=j-1;k++)
   {
       int temp = findMCMRec(arr,i,k) + findMCMRec(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
        if(temp < minE)
            minE = temp;
   }
   return minE;
}
int findMCMMemo(int arr[],int i,int j)
{
    int minE = INT_MAX;
    if(i>=j)
        return 0;
    if(t[i][j] != -1)
        return t[i][j];
    for(int k=i;k<=j-1;k++)
    {
        int temp = findMCMMemo(arr,i,k) + findMCMMemo(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
        if(temp < minE)
            minE = temp;
    }
    return t[i][j] = minE;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    memset(t,-1,sizeof(t));
    //INITIALIZE EACH ELEMENT OF MATRICES BY -1 USING MEMSET

    cout << "Minimum number of multiplications(Recursive version) is "<<endl;
    cout << findMCMRec(arr,1,n-1) <<endl;
     cout << "Minimum number of multiplications(Memoized version) is "<<endl;
    cout << findMCMMemo(arr,1,n-1);
    return 0;
}

