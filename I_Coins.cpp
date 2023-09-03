#include<bits/stdc++.h>
using namespace std;
#define int long long

double dp[3001][2][3001];//dp[i][j][k] denotes the probability of getting exactly k heads when we toss the first i coins and j denotes whether we have to consider the ith coin or not in the calculation of the probability of getting exactly k heads when we toss the first i coins.

double probability[3001];//probability[i] denotes the probability of getting exactly i heads when we toss the first i coins.
signed main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>probability[i];
    }
    //base case
    dp[1][1][1]=probability[1];//when we toss the first coin then the probability of getting exactly 1 head is the probability of getting a head when we toss the first coin.

    dp[1][0][1]=1-probability[1];//when we toss the first coin then the probability of getting exactly 1 head is the probability of getting a tail when we toss the first coin.

    //transition
    for(int i=2;i<=n;++i)
    {
        //when we toss the ith coin then the probability of getting exactly 0 heads is the probability of getting a tail when we toss the ith coin and we have to consider the ith coin in the calculation of the probability of getting exactly 0 heads when we toss the first i coins or the probability of getting a head when we toss the ith coin and we don't have to consider the ith coin in the calculation of the probability of getting exactly 0 heads when we toss the first i coins.
        if(i%2==0)
        {
            dp[i][1][0]=dp[i-1][1][1]*(1-probability[i])+dp[i-1][0][1]*probability[i];//when we toss the ith coin then the probability of getting exactly 0 heads is the probability of getting a tail when we toss the ith coin.The dp[i][1][0] denotes that we have to consider the ith coin in the calculation of the probability of getting exactly 0 heads when we toss the first i coins.

            dp[i][0][0]=dp[i-1][1][1]*(1-probability[i])+dp[i-1][0][1]*probability[i];//when we toss the ith coin then the probability of getting exactly 0 heads is the probability of getting a tail when we toss the ith coin.The dp[i][0][0] denotes that we don't have to consider the ith coin in the calculation of the probability of getting exactly 0 heads when we toss the first i coins.
        }
        dp[i][1][i]=dp[i-1][1][i-1]*probability[i];//when we toss the ith coin then the probability of getting exactly i heads is the probability of getting a head when we toss the ith coin.The dp[i][1][i] denotes that we have to consider the ith coin in the calculation of the probability of getting exactly i heads when we toss the first i coins.
        dp[i][0][i]=dp[i-1][0][i-1]*(1-probability[i]);//when we toss the ith coin then the probability of getting exactly i heads is the probability of getting a head when we toss the ith coin.The dp[i][0][i] denotes that we don't have to consider the ith coin in the calculation of the probability of getting exactly i heads when we toss the first i coins.

        for(int j=1;j<i;++j)
        {
            dp[i][1][j]=dp[i-1][1][j-1]*probability[i]+dp[i-1][1][j+1]*(1-probability[i]);//when we toss the ith coin then the probability of getting exactly j heads is the probability of getting a head when we toss the ith coin and we have to consider the ith coin in the calculation of the probability of getting exactly j heads when we toss the first i coins or the probability of getting a tail when we toss the ith coin and we don't have to consider the ith coin in the calculation of the probability of getting exactly j heads when we toss the first i coins.

            dp[i][0][j]=dp[i-1][0][j-1]*(1-probability[i])+dp[i-1][0][j+1]*probability[i];//when we toss the ith coin then the probability of getting exactly j heads is the probability of getting a tail when we toss the ith coin and we have to consider the ith coin in the calculation of the probability of getting exactly j heads when we toss the first i coins or the probability of getting a head when we toss the ith coin and we don't have to consider the ith coin in the calculation of the probability of getting exactly j heads when we toss the first i coins.
        }
    }
    double ans=0;
    for(int i=1;i<=n;++i)
    {
        //when we toss the first n coins then the probability of getting exactly i heads is the probability of getting exactly i heads when we toss the first n coins and we have to consider the nth coin in the calculation of the probability of getting exactly i heads when we toss the first n coins or the probability of getting exactly i heads when we toss the first n coins and we don't have to consider the nth coin in the calculation of the probability of getting exactly i heads when we toss the first n coins.
        ans+=dp[n][1][i];
    }
    //save and print
    cout<<fixed<<setprecision(10)<<ans<<endl;
    
    assert(ans>=0 && ans<=1);//the probability of getting exactly i heads when we toss the first i coins is always between 0 and 1.
}