#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e3+5,M=1e4,OO = 0x3f3f3f3f;

int mem[N][N],sz1,sz2;
string s1,s2;
int EditDistance(int i=0,int j=0)
{
    if(i==sz1)return sz2-j;
    if(j==sz2)return sz1-i;
    int &ret=mem[i][j];
    if(~ret)return ret;
    if(s1[i]==s2[j])return ret=EditDistance(i+1,j+1);
    //EditDistance(i,j+1)->add s2[j] before s1[i]
    //EditDistance(i+1,j+1)->replace s1[i]=s2[j]
    //EditDistance(i+1,j)->remove s1[i]
    return ret=min(EditDistance(i,j+1),min(EditDistance(i+1,j+1),EditDistance(i+1,j)))+1;
}

int main()
{
    memset(mem,-1,sizeof mem);
    cin>>s1>>s2;
    sz1=s1.size(),sz2=s2.size();
    printf("%d\n",EditDistance());
    return 0;
}
