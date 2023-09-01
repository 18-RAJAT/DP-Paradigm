#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1005][1005];
int dfs(int i,int j,int n,int m,vector<vector<char>>&grid)
{
    //base case for invalid case
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='#')
    {
        return 0;
    }
    //pruning
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    //base case
    if(i==n-1 && j==m-1)
    {
        return 1;
    }
    //recursive case

    //we can also use memoization to store the number of ways to reach the end point from that direction.
    //calculating the number of ways to reach the end point from the right and bottom direction.
    int recur=dfs(i+1,j,n,m,grid)+dfs(i,j+1,n,m,grid);
    //save and return
    return dp[i][j]=recur%1000000007;

    //correctness of the code
    assert(dp[i][j]>=0);
}
void sol()
{
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    vector<vector<char>>grid(n,vector<char>(m,'.'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<dfs(0,0,n,m,grid);//starting from the top left corner of the grid.
}
signed main()
{
    sol();
}