#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
    using segment tree to solve the problem because the problem is a range query problem and we can solve range query problem using segment tree in O(logn) time complexity and O(n) space complexity where n is the number of nodes in the segment tree and we can solve range query problem using brute force in O(n) time complexity and O(1) space complexity where n is the number of nodes in the segment tree
*/
struct Node
{
    int height,beauty;
};
//build a segment tree
void buildSegmentTree(vector<Node>&tree,int node,int start,int end)
{
    if(start==end)
    {
        // tree[node].height=0;
        // tree[node].beauty=0;
        tree[node]={start,0};//base case of segment tree build function
        return;
    }
    int mid=(start+end)/2;
    buildSegmentTree(tree,2*node,start,mid);//left subtree
    buildSegmentTree(tree,2*node+1,mid+1,end);//right subtree
    // tree[node].height=0;
    // tree[node].beauty=0;
    tree[node]={end,0};
}
//update a node in segment tree
void updateSegmentTree(vector<Node>&tree,int node,int start,int end,int idx,int beauty)
{
    if(start==end && start==idx)
    {
        tree[node].beauty=max(tree[node].beauty,beauty);//update the beauty of the node in segment tree
        return;
    }
    int mid=(start+end)/2;
    if(idx<=mid)
    {
        updateSegmentTree(tree,2*node,start,mid,idx,beauty);//left subtree
    }
    else
    {
        updateSegmentTree(tree,2*node+1,mid+1,end,idx,beauty);//right subtree
    }
    tree[node].beauty=max(tree[2*node].beauty,tree[2*node+1].beauty);//update the beauty of the node in segment tree
}
//query a node in segment tree
int querySegmentTree(vector<Node>&tree,int node,int start,int end,int left,int right)
{
    if(start>right || end<left)
    {
        return 0;
    }
    if(left<=start && end<=right)
    {
        return tree[node].beauty;//base case of segment tree query function
    }
    int mid=(start+end)/2;
    int leftAns=querySegmentTree(tree,2*node,start,mid,left,right);//left subtree

    int rightAns=querySegmentTree(tree,2*node+1,mid+1,end,left,right);//right subtree

    return max(leftAns,rightAns);//return the maximum of left and right subtree
}
signed main()
{
    int n;
    cin>>n;
    vector<Node>segmentTree(4*n);
    vector<int>height(n),beauty(n);
    for(int i=0;i<n;++i)
    {
        cin>>height[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>beauty[i];
    }
    
    buildSegmentTree(segmentTree,1,1,n);//build the segment tree
    for(int i=0;i<n;++i)
    {
        int idx=height[i];
        int beautyOfNode=querySegmentTree(segmentTree,1,1,n,1,idx-1);//query the maximum beauty of the nodes from 1 to idx-1

        updateSegmentTree(segmentTree,1,1,n,idx,beautyOfNode+beauty[i]);//update the beauty of the node idx
    }
    cout<<querySegmentTree(segmentTree,1,1,n,1,n)<<endl;//query the maximum beauty of the nodes from 1 to n
    
    assert(~segmentTree[1].beauty && segmentTree[1].beauty>=0);//sanity check means segment tree node is already computed
    return 0;
}