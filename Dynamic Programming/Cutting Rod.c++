/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and 
the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
*/


#include <bits/stdc++.h>               //Space complexity is -> O(n^2) , Time complexity is -> O(n^2)

using namespace std;
const int N = 1e4+5, M = 1e4, OO = 0x3f3f3f3f;

int len,l[N],P[N],mem[N][N],n;

int CuttingRod(int i=0,int rem=len)
{

    if(rem<0)return -OO;
    if(rem==0)return 0;
    if(i==n)
    {
        if(rem!=0)return -OO;
        return 0;
    }

    int &ret=mem[i][rem];
    if(~ret)return ret;
    ret=CuttingRod(i+1,rem);
    return ret=max(ret,CuttingRod(i,rem-l[i])+P[i]);
}


void PrintSolution(int i=0,int rem=len)
{

    if(rem<=0||i==n)return;

    int ret=CuttingRod(i,rem);
    if(ret==CuttingRod(i+1,rem))PrintSolution(i+1,rem);
    else printf("%d ",l[i]),PrintSolution(i,rem-l[i]);
}


int main()
{
    memset(mem,-1,sizeof mem);
    scanf("%d%d",&len,&n);
    for(int i=0; i<n; ++i)scanf("%d%d",l+i,P+i);
    printf("Maximum Profit: %d\n",CuttingRod());
    PrintSolution();
    return 0;
}
