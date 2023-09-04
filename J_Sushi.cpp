#include<bits/stdc++.h>
using namespace std;
#define int long long
bool flag[305][305][305];
double dp[305][305][305];
double dfs(int n,int c1,int c2,int c3)//n:total number of sushi,c1,c2,c3:number of plates with 1,2,3 sushi.
{
    if(c1==0&&c2==0&&c3==0)//All plates are empty.
    {
        return 0;
    }
    if(flag[c1][c2][c3])//This state has already been seen.
    {
        return dp[c1][c2][c3];
    }
    double ans=0;
    ans+=double(n-c1-c2-c3)/double(c1+c2+c3);//probability of choosing an empty plate.
    //base case.
    if(c1>=1)
    {
        ans+=(dfs(n,c1-1,c2,c3)+1.0)*double(c1)/double(c1+c2+c3);//probability of choosing a plate with 1 sushi.
    }
    if(c2>=1)
    {
        ans+=(dfs(n,c1+1,c2-1,c3)+1.0)*double(c2)/double(c1+c2+c3);//probability of choosing a plate with 2 sushi.
    }
    if(c3>=1)
    {
        ans+=(dfs(n,c1,c2+1,c3-1)+1.0)*double(c3)/double(c1+c2+c3);//probability of choosing a plate with 3 sushi.
    }
    flag[c1][c2][c3]=true;//This state has already been seen.
    return dp[c1][c2][c3]=ans;//memo.

    assert(dp[c1][c2][c3]!=0 && dp[c1][c2][c3]!=-1 && c1!=0 && c2!=0 && c3!=0);
}
signed main()
{
    int n;
    cin>>n;
    int c1=0,c2=0,c3=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        //Count the number of plates with 1,2,3 sushi.
        if(a==1)
        {
            c1++;
        }
        if(a==2)
        {
            c2++;
        }
        if(a==3)
        {
            c3++;
        }
    }
    double ans=dfs(n,c1,c2,c3);//Calculate the expected value.
    cout<<fixed<<setprecision(15)<<ans<<endl;
    return 0;
}