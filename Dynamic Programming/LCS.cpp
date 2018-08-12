#include <bits/stdc++.h>

using namespace std;
const int N = 1e2+5, M = 1e4, OO = 0x3f3f3f3f;

int n, m;
char s1[N], s2[N];
int mem[N][N];

int solve(int i=n-1,int j=m-1)
{
    if(i==-1||j==-1)return 0;
    int &ret=mem[i][j];
    if(~ret)return ret;
    return ret=((s1[i]==s2[j])?solve(i-1,j-1)+1:max(solve(i-1,j),solve(i,j-1)));
    //if(s1[i]==s2[j])return ret=LCS(i-1,j-1)+1;
    //return ret=max(LCS(i-1,j),LCS(i,j-1));
}
void print(int i = n-1, int j = m-1)
{
    if(i == -1||j == -1)return ;
    int ret = solve(i,j);
    if(ret == solve(i-1,j))
        print(i-1,j);
    else if(ret == solve(i,j-1))
        print(i,j-1);
    else
    {
        print(i-1,j-1);
        printf("%c",s1[i]);
    }
}

int main()
{
    scanf("%s%s", s1, s2);
    n = strlen(s1);
    m = strlen(s2);
    memset(mem, -1, sizeof mem);
    printf("%d\n", solve());
    print();
    puts("");
    return 0;
}

