#include<bits/stdc++.h>
using namespace std;
#define int long
int dp[100005][2];
vector<int>adj[100005];
void dfs(int child,int parent)
{
    //pre-computation
    dp[child][0]=1;
    dp[child][1]=1;
    //pruning
    if(adj[child].size()==1 && adj[child][0]==parent)
    {
        return;
    }
    for(auto& it:adj[child])
    {
        //base case
        if(it==parent)
        {
            continue;
        }
        dfs(it,child);//dfs call
        /*
            dp[child][0] denotes the number of ways to assign the first i people to the first i jobs such that the mask is the set of jobs that are already assigned and the ith person is not assigned any job yet
        */
        dp[child][0]=(dp[child][0]*(dp[it][0]+dp[it][1]))%1000000007;//child is not included
        dp[child][1]=(dp[child][1]*dp[it][0])%1000000007;//child is included
    }
}
signed main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][1])%1000000007<<endl;
    assert(~dp[1][0] && dp[1][0]>=0);//sanity check means dp state is already computed
    return 0;
}