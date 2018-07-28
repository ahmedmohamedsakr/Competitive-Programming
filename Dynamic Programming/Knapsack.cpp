#include<bits/stdc++.h>                                                //Space  O(n*k)
using namespace std;                                                   //Time   O(n*k)
const int N=1e3+5,OO=0x3f3f3f3f;
int mem[N][N],W[N],P[N],dp[N];
int n,k;
int knapsack(int i=0,int rem=k)
{
    if(rem<0)return -OO;
    if(i==n)return 0;
    int & ret=mem[i][rem];
    if(~ret)return ret;
    ret=knapsack(i+1,rem);
    ret=max(ret,knapsack(i+1,rem-W[i])+P[i]);
    return ret;
}
void init()
{
    memset(mem,-1,sizeof mem);
}
int main()
{
    init();
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; ++i)scanf("%d%d",W+i,P+i);
    printf("maximum benfit = %d\n",knapsack());
    return 0;
}
