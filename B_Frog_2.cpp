#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001];
int heights[100001];
int recur(int k,int currStone,int destStone)
{
    //recur is used to number of ways to populate level[1] to level[n-1] for valid configuration

    //pruning
    if(currStone==destStone)
    {
        return 0;
    }
    //base case
    if(dp[currStone]!=-1)
    {
        return dp[currStone];
    }
    //recursive case
    int ans=INT_MAX;
    for(int jump=1;jump<=k;jump++)
    {
        if((currStone+jump)>destStone)
        {
            break;
        }
        ans=min<int>(ans,recur(k,currStone+jump,destStone)+abs<int>(heights[currStone]-heights[currStone+jump]));
    }
    //save and return
    return dp[currStone]=ans;
}
signed main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>heights[i];
        dp[i]=-1;
    }
    cout<<recur(k,1,n);
    return 0;
}