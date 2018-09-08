//601A - The Two Routes ->codeforces
#include <bits/stdc++.h>
                       
using namespace std;

const int N=4e3+5,M=1e6+5,OO=0x3f3f3f3f;
int n,m,u,v,vis[N],dis[N],ans;
int adj[N][N];
int Dijkstra(int src)
{
    queue<int>q;
    q.push(src);
    dis[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int j=1; j<=n; ++j)
        {
            if(adj[u][j]&&dis[j]==OO)
            {
                dis[j]=dis[u]+1;
                q.push(j);
            }
        }
    }
    return dis[n];
}
void init()
{
    memset(dis,OO,sizeof dis);
}
int main ()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    ans=Dijkstra(1);
    init();
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)adj[i][j]=1-adj[i][j];
    ans=max(ans,Dijkstra(1));
    printf("%d",(ans!=OO)?ans:-1);
    return 0;
}
