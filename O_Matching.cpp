#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[22][1<<21];//dp[i][mask] denotes the number of ways to assign the first i people to the first i jobs such that the mask is the set of jobs that are already assigned
int n;
int women[22][22];
int sol(int i,int j)
{
    //pre-computation/base case
    if(j==(1<<n)-1)
    {
        return 1;
    }
    //pruning
    if(i>=n)
    {
        return 0;
    }
    int &ans=dp[i][j];
    //memoization
    if(~ans)
    {
        return ans;
    }
    int res=0;
    for(int k=0;k<n;++k)
    {
        if(women[i][k]==1)
        {
            if((j&(1<<k))==0)//the job is not assigned yet
            {
                if(dp[i+1][j+(1<<k)]>-1)//dp state already computed
                {
                    res+=dp[i+1][j+(1<<k)]%1000000007;
                    continue;
                }
                res=(1000000007+res+sol(i+1,j+(1<<k)))%1000000007;//assigning ith person to kth job
            }
        }
    }
    return ans=res;
    assert(~dp[i][j] && dp[i][j]>=0);//sanity check means dp state is already computed
}
signed main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>women[i][j];
        }
    }
    cout<<sol(0,0)<<endl;
    return 0;
}