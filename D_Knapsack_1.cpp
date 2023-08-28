#include<bits/stdc++.h>
using namespace std;
#define int long long
int weight[100001],value[100001];
int dp[101][100001];
int n;
int recur(int index,int theirWeights)
{
    //base case
    if(index==n)
    {
        return 0;
    }
    //cache check
    if(theirWeights==0)
    {
        return 0;
    }
    //pruning
    if(dp[index][theirWeights]!=-1)
    {
        return dp[index][theirWeights];
    }
    //compute/transitions
    int ans=recur(index+1,theirWeights);
    if(weight[index]<=theirWeights)
    {
        ans=max<int>(ans,recur(index+1,theirWeights-weight[index])+value[index]);
    }
    //save and return
    return dp[index][theirWeights]=ans;
}
signed main()
{
    int W;//weight
    cin>>n>>W;
    for(int i=0;i<n;++i)
    {
        cin>>weight[i]>>value[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<recur(0,W);
    return 0;
}