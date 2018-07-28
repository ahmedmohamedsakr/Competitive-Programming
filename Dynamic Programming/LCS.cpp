#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,OO=0x3f3f3f3f;
int mem[N][N];
string s1,s2;
int LCS(int i=s1.size()-1,int j=s2.size()-1)
{
    if(i==-1||j==-1)return 0;
    int &ret=mem[i][j];
    if(~ret)return ret;
    return ret=((s1[i]==s2[j])?LCS(i-1,j-1)+1:max(LCS(i-1,j),LCS(i,j-1)));
    //if(s1[i]==s2[j])return ret=LCS(i-1,j-1)+1;
    //return ret=max(LCS(i-1,j),LCS(i,j-1));
}
void init()
{
    memset(mem,-1,sizeof mem);
}
int main()
{
    init();
    cin>>s1>>s2;
    printf("Longest Common Subsequence = %d\n",LCS());
    return 0;
}
