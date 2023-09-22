#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[3005][3005];
void permutation()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    dp[0][0]=1;
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(s[i]=='<')
            {
                dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%1000000007;//adding because we are adding the same value twice.
                // dp[i+1][i+2]-=dp[i][j];//subtracting because we are subtracting the same value twice.
            }
            else
            {
                dp[i+1][0]=(dp[i+1][0]+dp[i][j])%1000000007;//adding because we are adding the same value twice.
                dp[i+1][j+1]=(dp[i+1][j+1]-dp[i][j]+1000000007)%1000000007;//adding because we are adding the same value twice.
            }
        }
        //prefix sum array for each row.
        for(int j=0;j<n;++j)
        {
            dp[i+1][j+1]=(dp[i+1][j+1]+dp[i+1][j])%1000000007;//adding because we are adding the same value twice.
        }
    }
    int ans=0;
    //sum of all the elements in the last row.
    for(int i=0;i<n;++i)
    {
        ans+=dp[n-1][i]%1000000007;
    }
    cout<<ans%1000000007<<endl;
}
signed main()
{
    permutation();
    return 0;
}