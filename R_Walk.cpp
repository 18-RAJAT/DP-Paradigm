#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[64][51][51];
int n,k;
int ans[51][51],temp[51][51];

/*
    dp[l][i][j] is the number of ways to reach from i to j in exactly 2^l steps
    dp[l][i][j]=sum(dp[l-1][i][u]*dp[l-1][u][j]) where u is the intermediate node and l is the power of 2 and i and j are the starting and ending node respectively and dp[0][i][j] is the adjacency matrix of the graph where i and j are the starting and ending node respectively.
*/
void matrixMultiplication()
{
    //dp[l][i][j] is the number of ways to reach from i to j in exactly 2^l steps
    for(int l=1;l<64;l++)//l is the power of 2
    {
        for(int i=1;i<=n;i++)//i is the starting node
        {   
            for(int j=1;j<=n;j++)//j is the ending node
            {
                for(int u=1;u<=n;u++)//u is the intermediate node
                {
                    dp[l][i][j]=(dp[l][i][j]+((dp[l-1][i][u]*dp[l-1][u][j])%1000000007))%1000000007;
                }
            }
        }
    }
}

//get the bit at position l from the right in the binary representation of k where l is 0-indexed and k is a non-negative integer and k is less than 2^64 and k is the number whose binary representation is to be found and the bit at position l from the right in the binary representation of k is to be found and the bit at position l from the right in the binary representation of k is returned as an integer. 
int getBit(int k,int l)
{
    return ((k>>l)&1);
}
void sol()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        ans[i][i]=1;
        for(int j=1;j<=n;j++)
        {
            cin>>dp[0][i][j];
        }
    }
    //base case
    if(k==0)
    {
        cout<<1<<endl;
        return;
    }
    //pre computation
    // int &res=dp[0][1][n];
    //if there is no edge from 1 to n then there is no way to reach from 1 to n in exactly k steps(pruning)
    // if(~res)
    // {
    //     res=0;
    // }
    matrixMultiplication();
    for(int l=0;l<64;l++)
    {
        if(getBit(k,l)==0)
        {
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                temp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int u=1;u<=n;u++)
                {
                    //using matrix multiplication
                    temp[i][j]=(temp[i][j]+((ans[i][u]*dp[l][u][j])%1000000007))%1000000007;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans[i][j]=temp[i][j];
            }
        }
    }
    int answer=0;
    //answer is the number of ways to reach from 1 to n in exactly k steps
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            answer=(answer+ans[i][j])%1000000007;
        }
    }
    cout<<answer<<endl;
}
signed main()
{
    sol();
    return 0;
}