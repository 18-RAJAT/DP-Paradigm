#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001];
vector<int>heights;
int recur(int level)//level is my placing state
{
    //recur is used to number of ways to populate level[1] to level[n-1] for valid configuration

    //pruning
    if(level<=0)
    {
        return 0;
    }
    //base case
    if(dp[level]!=-1)
    {
        return dp[level];
    }
    //recursive case
    int ans=recur(level-1)+abs<int>(heights[level]-heights[level-1]);
    
    //pruning for level-2 as we can jump from level-2 to level directly if we are at level now and level-2 is valid state
    if(level>=2)
    {
        ans=min<int>(ans,recur(level-2)+abs<int>(heights[level]-heights[level-2]));
    }
    return dp[level]=ans;
}
signed main()
{
    int n;
    cin>>n;
    heights.resize(n);
    for(auto &it:heights)
    {
        cin>>it;
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(n-1);
    return 0;
}