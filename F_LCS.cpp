#include<bits/stdc++.h>
using namespace std;
#define int long long
string s,t;
int dp[3005][3005];
int dfs(int n,int m)//for calculate the each LCS
{
    //pruning
    
    //base case
    if(n==s.size()||m==t.size())
    {
        return 0;
    }
    //cache check
    if(dp[n][m]!=-1)
    {
        return dp[n][m];//if the answer is already calculated then we return the answer
    }
    //compute
    int ans=0;
    if(s[n]==t[m])
    {
        ans=1+dfs(n+1,m+1);//if the character matches then we add 1 to the answer and move to the next character in both the strings
    }
    else
    {
        //transitions
        ans=max<int>(dfs(n+1,m),dfs(n,m+1));//if the character doesn't match then we move to the next character in either of the strings and take the maximum of the two cases (i.e. either of the two strings)
    }
    //save and return
    return dp[n][m]=ans;
}
void printLCS(int n,int m)
{
    if(n==s.size()||m==t.size())
    {
        return;
    }
    //base case
    if(s[n]==t[m])
    {
        cout<<s[n];
        printLCS(n+1,m+1);//if the character matches then we print the character and move to the next character in both the strings
    }
    else
    {
        if(dfs(n+1,m)>dfs(n,m+1))
        {
            //dfs(n+1,m)>dfs(n,m+1)
            printLCS(n+1,m);
        }
        else
        {
            //dfs(n+1,m)<=dfs(n,m+1)
            printLCS(n,m+1);
        }
    }
    return;
}
signed main()
{
    memset(dp,-1,sizeof(dp));
    cin>>s>>t;
    int calc=dfs(0,0);
    if(calc==0)
    {
        cout<<""<<endl;
        return 0;
    }
    printLCS(0,0);//precompute the LCS and print it in O(n+m) time complexity (i.e. linear time) instead of O(n*m) time complexity (i.e. quadratic time) using recursion and memoization (i.e. top-down DP) instead of tabulation (i.e. bottom-up DP) which takes O(n*m) space complexity (i.e. quadratic space) instead of O(n+m) space complexity (i.e. linear space)
    return 0;
}