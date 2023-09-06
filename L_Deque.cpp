#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
    MINI-MAX Algorithm:
    1. The first player wins if the nim-sum of the starting position is non-zero. Otherwise, if the nim-sum is zero, then the second player will win.

    Inclusion-Exclusion Principle:
    1. The first player wins if the nim-sum of the starting position is non-zero. Otherwise, if the nim-sum is zero, then the second player will win.
*/
int dp[3005][3005][2];//Taro and Jiro.For the first player, the nim-sum of the starting position is non-zero. For the second player, the nim-sum of the starting position is zero.
int arr[3005];
bool visited[3005][3005][2];
int n;

int recur(int l,int r,bool flag)
{
    //pruning optimization.
    if(r<l)
    {
        return 0;
    }
    int &ans=dp[l][r][flag];//save by reference.
    //base case.
    if(visited[l][r][flag])//This state has already been seen.
    {
        return ans;
    }
    visited[l][r][flag]=true;//This state has been seen.
    //Recursion + Memo + Try to remove a[i] stones + Transition function.

    //not flag means the second player. flag means the first player.
    if(flag)
    {
        ans=max<int>(recur(l+1,r,!flag)+arr[l],recur(l,r-1,!flag)+arr[r]);//The first player wins if the nim-sum of the starting position is non-zero.
    }
    else
    {
        ans=min<int>(recur(l+1,r,!flag)-arr[l],recur(l,r-1,!flag)-arr[r]);//The second player wins if the nim-sum of the starting position is zero.
    }
    //save and return.
    return ans;

    assert(ans!=0 && ans!=-1 && r>=l && dp[l][r][flag]^0 && dp[l][r][flag]|1);//pruning optimization.
}
signed main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<recur(0,n-1,1)<<endl;//The first player wins if the nim-sum of the starting position is non-zero.
    return 0;
}