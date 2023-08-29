#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+5;
int dp[N];
int knapsackMaxValue(int knapsack[105][2],int n,int weight)
{
    //pruning
    if(n==0)
    {
        return 0;
    }
    //precompute
    for(int i=0;i<N;++i)
    {
        dp[i]=2e9;
    }
    //base case
    if(knapsack[0][1]<=weight)
    {
        dp[knapsack[0][1]]=knapsack[0][0];
    }
    //dp[i] stores the minimum weight required to get value i
    dp[0]=0;
    //transitions
    for(int i=0;i<=n;++i)
    {
        int W=knapsack[i][0];//weight
        int V=knapsack[i][1];//value
        for(int j=N-1;j>=V;--j)//reverse loop to avoid overwriting dp[j-V] which is required for the next iteration of i loop (i.e. for the next item)
        {
            //dp[j] stores the minimum weight required to get value j
            dp[j]=min<int>(dp[j],dp[j-V]+W);
        }
    }
    //compute
    int ans=0;
    for(int i=0;i<N;++i)
    {
        if(dp[i]<=weight)
        {
            ans=max<int>(ans,i);
        }
    }
    //save and return
    return ans;
}
signed main()
{
    int n,W;
    cin>>n>>W;
    int knapsack[105][2];
    for(int i=1;i<=n;++i)
    {
        cin>>knapsack[i][0]>>knapsack[i][1];
    }
    cout<<knapsackMaxValue(knapsack,n,W);
    return 0;
}