#include<bits/stdc++.h>
using namespace std;
#define int long long
string k;
int d;
int dp[10005][105][2];
int memo(int digit,int sum,int val)
{
    //pruning
    if(sum>d)
    {
        return 0;
    }
    //base case
    if(digit==k.size() && sum==0)
    {
        return 1;
    }
    //base case
    if(digit==k.size())
    {
        return 0;
    }
    //memoization
    int &res=dp[digit][sum][val];
    if(~res)
    {
        return res;
    }
    res=0;
    int limit=9;
    //if the digit-th digit of k is 0 then the digit-th digit of k can be 0 only if the number formed by the first digit of k to the digit-th digit of k is 0.
    if(val==0)
    {
        limit=k[digit]-'0';//the digit-th digit of k
    }
    // if(convert(k.substr(0,digit+1))%d==0)
    // {
    //     res++;
    // }
    for(int i=0;i<=limit;i++)
    {
        //the number formed by the first digit of k to the digit-th digit of k is val and the sum of the digits of the number formed by the first digit of k to the digit-th digit of k is sum and the digit-th digit of k.
        res=(res+memo(digit+1,(sum+i)%d,(val==0 && i==limit)?0:1))%1000000007;
    }
    return res;
    assert(dp[digit][sum][val]>=0 && ~dp[digit][sum][val]<=1000000007);//assertion to check if the value of dp[digit][sum][val] is in the range [0,1000000007] or not.
}
signed main()
{
    cin>>k>>d;
    memset(dp,-1,sizeof(dp));
    cout<<(memo(0,0,0)-1+1000000007)%1000000007<<endl;//subtract 1 because 0 is not a valid number.
    return 0;
}