#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[16][16];
int arr[1<<16],f[1<<16];
/*
    Approach: Bitmask DP
    In this problem, we need to find the max value of the whole group of the graph.

    dp[i][j] is the value of the edge between i and j (i<j)
    arr[i] is the sum of the value of the edges in the group i
    f[i] is the max value of the group i
    f[i]=max(f[i^j]+arr[j]) (j is the subset of i)
    f[(1<<n)-1] is the max value of the whole group

    Time complexity: O(2^n*n^2)=O(2^16*16^2)
    Space complexity: O(2^n)=O(2^16)
*/
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>dp[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);++i)//find the max value of each group
    {
        arr[i]=0;
        for(int j=0;j<n;++j)
        {
            if(i&(1<<j))//if j is in the group i
            {
                for(int k=j+1;k<n;++k)//find the max value of each group
                {
                    if(i&(1<<k))//again, if k is in the group i vice versa
                    {
                        arr[i]+=dp[j][k];
                    }
                }
            }
        }
    }
    for(int i=0;i<(1<<n);++i)//find the max value of each group
    {
        for(int j=i;j;j=(j-1)&i)//calculate the max value of each group
        {
            f[i]=max(f[i],f[i^j]+arr[j]);//f[i^j] is the max value of the other group
        }
    }
    cout<<f[(1<<n)-1]<<endl;//the max value of the whole group
}
signed main()
{
    sol();
    return 0;
}