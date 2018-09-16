#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N=5e3+4,M=2e2+4,OO=0x3f3f3f3f;
int mem[N][N],n;
string s;
//Longest Palindromic Subsequence
int LPS(int i=0,int j=n)
{
    if(i>j)return 0;
    if(i==j)return 1;
    int &ret=mem[i][j];
    if(~ret)return ret;
    if(s[i]==s[j])return ret=2+LPS(i+1,j-1);
    return ret=max(ret,max(LPS(i+1,j),LPS(i,j-1)));
}

void print(int i=0,int j=n)
{
    if(i>j)return;
    if(i==j)
    {
        printf("%c",s[i]);
        return;
    }
    int ret=LPS(i,j);
    if(ret==LPS(i+1,j))
    {
        print(i+1,j);
    }
    else if(ret ==LPS(i,j-1))
    {
        print(i,j-1);
    }
    else
    {
        printf("%c",s[i]);
        print(i+1,j-1);
        printf("%c",s[i]);
    }
}

int main()
{
    memset(mem,-1,sizeof mem);
    cin>>s;
    n=s.size()-1;
    printf("%d\n",LPS());
    print();
    return 0;
}
