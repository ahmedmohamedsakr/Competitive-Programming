#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,OO=0x3f3f3f3f;
int col[N],n,m,u,v;
vector<int>adj[N];

bool CheckBiPartite(int src)
{

    queue<int>q;
    q.push(src);
    col[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto it:adj[u])
        {
            if(col[it]==OO)
            {
                col[it]=!col[u];
                q.push(it);
            }
            else if(col[it]==col[u])return 0;
        }
    }
    return 1;
}

int main ()
{
    memset(col,OO,sizeof col);
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; ++i)
    {
        if(col[i]==OO)if(!CheckBiPartite(i))return puts("Not BiPartite");
    }
    puts("BiPartite");
    return 0;
}
