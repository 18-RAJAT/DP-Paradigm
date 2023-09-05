/*
impartial game means that the first player can always win and the second player can always lose or vice versa.

The first player can always win if the nim-sum of the starting position is non-zero. Otherwise, if the nim-sum is zero, then the second player will win.

The nim-sum of a position is the bitwise XOR of the sizes of the piles.

impartial games->Sprague-Grundy theorem

1.Nim Game:https://codeforces.com/contest/1516/problem/A
2.Grundy Number:https://codeforces.com/contest/1516/problem/B
3.XOR Operation:https://codeforces.com/contest/1516/problem/A
4.Wining Strategy:https://codeforces.com/contest/1516/problem/C
5.Loosing Strategy:https://codeforces.com/contest/1516/problem/D


Grundy Number: Used to calculate the Grundy number of a position. If a game is impartial, then the Grundy number of a position is the smallest non-negative integer that is not the Grundy number of any position that can be reached in one move.


XOR Operation: Used to calculate the Grundy number of a position. If a game is impartial, then the Grundy number of a position is the bitwise XOR of the sizes of the piles.


Wining/Loosing Strategy: Used to calculate the Grundy number of a position. If a game is impartial, then the Grundy number of a position is the smallest non-negative integer that is not the Grundy number of any position that can be reached in one move.
*/

//turn^1=1-turn (0->1,1->0).
//turn^0=turn (0->0,1->1).
int dp[100005][2];
int arr[105];
int n,k;
#include<bits/stdc++.h>
using namespace std;
#define int long long
int stoneGame(int num,int turn)
{
    //pruning optimization.
    if(dp[num][turn]!=-1)//This state has already been seen.
    {
        return dp[num][turn];
    }
    //base case.
    if(num==0)//All stones are removed.
    {
        return dp[num][turn]=turn^1;//If the number of stones is even, then the first player wins, otherwise the second player wins.
    }
    //Recursion + Memo + Try to remove a[i] stones + Transition function.

    for(int i=0;arr[i]<=num && i<n;++i)//Try to remove a[i] stones.Because the number of stones removed must be less than or equal to k.
    {
        int calc=stoneGame(num-arr[i],turn^1);//If the current player removes a[i] stones, then the current player wins.

        //Transition function.
        if(calc==turn)//If the current player wins, then the current player wins.
        {
            dp[num][turn]=turn;//If the current player wins, then the current player wins.
            return dp[num][turn]=turn;//Vise versa.
        }
    }
    dp[num][turn]=turn^1;//If the current player loses, then the current player loses.
    //save and return.
    return dp[num][turn];//Vise versa.

    assert(dp[num][turn]!=0 && dp[num][turn]!=-1 && num!=0);//pruning optimization.
}
signed main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //The first player wins if the nim-sum of the starting position is non-zero. Otherwise, if the nim-sum is zero, then the second player will win.
    for(int i=0;i<100005;++i)
    {
        //dp[i][0]:The first player wins if the nim-sum of the starting position is non-zero.
        //dp[i][1]:The second player wins if the nim-sum of the starting position is zero.
        for(int j=0;j<2;++j)
        {
            dp[i][j]=-1;//This state has not been seen yet.
        }
    }
    for(int i=0;i<=arr[0];i++)
    {
        for(int j=0;j<2;j++)
        {
            //Using the grundy number to calculate the nim-sum.
            dp[i][j]=j^1;//j-1 form of j^1.
        }
    }
    dp[arr[0]][0]=0;//The first player wins if the nim-sum of the starting position is non-zero.
    dp[arr[0]][1]=1;//The second player wins if the nim-sum of the starting position is zero.

    int ans=stoneGame(k,0);//k=total number of stones,0=first player.
    cout<<((!ans)?"First":"Second")<<"\n";
    return 0;
}