#include<bits/stdc++.h>
using namespace std;
#define int long long
//using prefix sum dp
//dp array takes O(n*k) space and O(n*k) time complexity.

int dp[105][100005];//the total number of ways to distribute candies to the first player such that the nim-sum of the starting position is non-zero.

int arr[105];//arr[i] denotes the number of candies in the i-th box.
int n,k;
int recur(int idx,int sum)//idx is the index of the box and sum is the nim-sum of the starting position.
{
    //pruning the recursion tree by checking if the nim-sum is zero or not.
    if(sum==0)
    {
        return dp[idx][sum]=1;//if the nim-sum is zero then there is only one way to distribute candies to the first player.
    }
    // if(idx==n)
    // {
    //     return dp[idx][sum]=0;
    // }
    //base case if the index of the box is zero then there is no way to distribute candies to the first player.
    if(idx==0)
    {
        // return dp[idx][sum]=recur(idx+1,sum);
        return 0;
    }
    //if the value is already calculated then return the value.
    if(dp[idx][sum]!=-1)
    {
        return dp[idx][sum];
    }
    int ans=0;
    if(sum<=arr[idx])//if the sum is less than or equal to the number of candies in the box then we can distribute candies to the first player in two ways.
    {
        ans=recur(idx,sum-1)+recur(idx-1,sum);//we can either distribute all the candies to the first player or we can distribute all the candies to the second player.
    }
    else
    {
        //if the sum is greater than the number of candies in the box then we can distribute candies to the first player in three ways.
        ans=recur(idx,sum-1)+recur(idx-1,sum)-recur(idx-1,sum-arr[idx]-1)+1000000007;//we can either distribute all the candies to the first player or we can distribute all the candies to the second player.
    }
    ans%=1000000007;
    //return the value.
    return dp[idx][sum]=ans;

    assert(dp[idx][sum]!=-1 && dp[idx][sum]>=0 && dp[idx][sum]<=1000000007 && recur(idx,sum-1)>=0 && recur(idx-1,sum)>=0 && recur(idx-1,sum-arr[idx]-1)>=0);//checking the constraints.
}
signed main()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);//by this we can reduce the number of states in the dp array.
    recur(n,k);
    cout<<dp[n][k]<<endl;//the total number of ways to distribute candies to the first player such that the nim-sum of the starting position is non-zero.
    return 0;
}