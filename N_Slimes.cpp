#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=405,INF=2e18;
int calc(int i,int j,int arr[N],int **dp)//i and j are the starting and ending indices of the array. arr is the array. dp is the memo table.dp[i][j] stores the minimum cost of merging the array from i to j.
{
    /*
        DP on Contiguous Segments:
        This is a very common type of DP problem. The idea is to divide the array into two parts and then solve the problem recursively for both the parts. The answer for the original array is the maximum/minimum/sum of the answers for the two parts.



        1. dp[i][j] = dp[i][k] + dp[k+1][j] + cost[i][j] + cost[i][k] + cost[k+1][j] //k is the last element of the first part. cost[i][j] is the cost of merging the two parts. cost[i][k] and cost[k+1][j] are the costs of the two parts.


        2. dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost[i][j] + cost[i][k] + cost[k+1][j]) //k is the last element of the first part. cost[i][j] is the cost of merging the two parts. cost[i][k] and cost[k+1][j] are the costs of the two parts.


        3. dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + cost[i][j] + cost[i][k] + cost[k+1][j]) //k is the last element of the first part. cost[i][j] is the cost of merging the two parts. cost[i][k] and cost[k+1][j] are the costs of the two parts.
    */
   //base case.
    if(i==j)
    {
        return 0;
    }
    //pruning optimization.
    if(i>j)
    {
        return INT_MAX;
    }
    //save by reference.
    int &ans=dp[i][j];

    //pruning optimization.
    if(~ans)
    {
        return ans;
    }
    int cost=0;
    //calc cost.
    for(int k=i;k<=j;++k)
    {
        cost+=arr[k];
    }
    int res=INF;
    //recursion + memo + transition function.
    for(int k=i;k<j;++k)
    {
        int currAns=calc(i,k,arr,dp)+calc(k+1,j,arr,dp)+cost;//cost of merging.
        res=min(res,currAns);//minimize.
    }
    //save and return.
    return dp[i][j]=res;

    assert(dp[i][j]!=-1);//pruning optimization.
}
signed main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int **dp=new int*[n];//dp[i][j] stores the minimum cost of merging the array from i to j.
    //initialize dp.
    for(int i=0;i<n;++i)
    {
        dp[i]=new int[n];
        for(int j=0;j<n;++j)
        {
            dp[i][j]=-1;
        }
    }
    cout<<calc(0,n-1,arr,dp)<<endl;
    
    //free memory.
    for(int i=0;i<n;++i)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return 0;
}