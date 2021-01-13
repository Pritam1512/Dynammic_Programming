#include<bits/stdc++.h>
using namespace std;


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
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout << "Minimum number of multiplications is "<<endl;
    cout << findMCMRec(arr,1,n-1);
    return 0;
}
