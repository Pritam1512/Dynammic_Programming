#include<bits/stdc++.h>
#include<string>
using namespace std;

//FOR SMALLEST COMMON SUPERSEQUENCE
//CONCATINATE A AND B
//PRINT EVERY THING EXCEPT LCS

string LCS(string x,string y,int n,int m)
{
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
            {
               t[i][j] = max(t[i-1][j]
                             ,t[i][j-1]);
            }
        }
    }
    /*for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            cout << t[i][j] <<" ";
        }
        cout << "" <<endl;
    }
    */
    string s;
    int i=n,j=m,k=0;
    while(i >0 && j >0)
    {
        if(x[i-1] == y[j-1])
        {
            s.push_back(x[i-1]);
            i--;
            j--;


        }
        else if(t[i-1][j] > t[i][j-1])
        {
            i--;
        }
        else
            j--;

    }
    return s;
}

int main()
{
    string x = "abc";
    string y = "bcv";

    string s  = LCS(x,y,3,3);
    reverse(s.begin(),s.end());
    cout <<"LCS is "<< s << endl;
    cout << s << endl;

    return 0;
}
