#include<bits/stdc++.h>
using namespace std;
int fibb(int x)
{
    if(x==1)
        return 1;
    if(x==2)
        return 2;
    else
        return fibb(x-1)+fibb(x-2);
}

int totalWays(int n)
{
    return fibb(n);
}

int main()
{
    int n;
    cin >> n;

    cout << totalWays(n);

    return 0;
}
