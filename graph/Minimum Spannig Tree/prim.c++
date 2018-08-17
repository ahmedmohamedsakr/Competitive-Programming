#include <bits/stdc++.h>                    //O(E*log(V))

using namespace std;
typedef pair<int,int> ii;

const int N=1e5+5,M=1e3,OO=0x3f3f3f3f;

int n,m,u,v,c,total,vis[N],dis[N],par[N];
vector<ii>adj[N];
int prim(int src=1)
{
    priority_queue<ii,vector<ii>,greater<ii>>pq;
    pq.push({0,src});
    vis[src]=1;
    dis[src]=0;
    par[src]=src;
    while(!pq.empty())
    {
        int v=pq.top().second,w=pq.top().first;
        pq.pop();
        vis[v]=1;
        if(dis[v]!=w)continue;
        total+=w;
        for(auto it:adj[v])
        {
            if(!vis[it.second]&&dis[it.second]>it.first)
            {
                dis[it.second]=it.first;
                par[it.second]=v;
                pq.push({it.first,it.second});
            }
        }
    }
    return total;
}
int main ()
{
    scanf("%d%d",&n,&m);
    memset(dis,OO,sizeof dis);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d%d",&u,&v,&c);
        adj[u].push_back({c,v});
        adj[v].push_back({c,u});
    }
    printf("%d\n",prim());
    puts("MST:");
    for(int i=1;i<=n;++i)printf("%d -> %d\n",par[i],i);
    return 0;
}
