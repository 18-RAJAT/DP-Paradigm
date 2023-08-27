#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[100005][3],ndp[100005][3];
signed main()
{
    int n;
    cin>>n;
    //pruning
    
    //base case
    if(n==0)
    {
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>dp[i][1]>>dp[i][2]>>dp[i][3];
    }
    ndp[1][1]=dp[1][1];
    ndp[1][2]=dp[1][2];
    ndp[1][3]=dp[1][3];
    for(int i=2;i<=n;++i)
    {
        //transitions
        ndp[i][1]=max<int>(ndp[i-1][2],ndp[i-1][3])+dp[i][1];
        ndp[i][2]=max<int>(ndp[i-1][1],ndp[i-1][3])+dp[i][2];
        ndp[i][3]=max<int>(ndp[i-1][1],ndp[i-1][2])+dp[i][3];
    }
    //save and return
    int ans=max<int>(ndp[n][1],max<int>(ndp[n][2],ndp[n][3]));
    cout<<ans;
    return 0;
}