#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[100005];
int dfs(int node,vector<int>adj[])//returns the longest path from the node to any other node in the graph
{
    //pruning
    if(adj[node].size()==0)//if the node is a leaf node then the longest path from the node to any other node in the graph is 0 as there are no other nodes in the graph to which we can go from the leaf node and hence the longest path from the node to any other node in the graph is 0
    {
        return 0;
    }
    //base case
    if(dp[node]!=-1)//if the answer is already calculated then we return the answer
    {
        return dp[node];
    }
    //compute
    int ans=0;
    for(auto& it:adj[node])
    {
        //transitions
        ans=max<int>(ans,1+dfs(it,adj));//we take the maximum of the longest path from the current node to any other node in the graph and the longest path from the adjacent node to any other node in the graph and add 1 to it to get the longest path from the current node to any other node in the graph
    }
    //save and return
    return dp[node]=ans;
}
signed main()
{
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    vector<int>adj[n+1];
    
    vector<pair<int,int>>edges(m);
    for(int i=0;i<m;i++)
    {
        cin>>edges[i].first>>edges[i].second;
    }
    int ans=0;
    for(int i=0;i<m;++i)
    {
        adj[edges[i].first].push_back(edges[i].second);//directed graph
    }
    for(int i=1;i<=n;i++)
    {
        ans=max<int>(ans,dfs(i,adj));//we take the maximum of the longest path from each node to any other node in the graph to get the longest path in the graph from any node to any other node in the graph
    }
    cout<<ans<<endl;
    return 0;
}