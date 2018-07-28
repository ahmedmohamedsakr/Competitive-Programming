#include<bits/stdc++.h>                                    //O((V+E)log(V))
using namespace std;                                       //V,E<=300K
typedef pair<int,int> ii;
const int N=1e5,OO=0x3f3f3f3f;
int dis[N],n,m,u,v,c,pt[N];
vector<ii>adj[N];
void printpath(int u)
{
    if(pt[u]==u)
    {
        printf("%d",u);
        return;
    }
    printpath(pt[u]);
    printf(" %d",u);
}
void Dijkstra(int s)
{
    priority_queue<ii,vector<ii>,greater<ii>>pq;
    pq.push({0,s});
    dis[s]=0;
    pt[s]=s;
    while(!pq.empty())
    {
        int d=pq.top().first,u=pq.top().second;
        pq.pop();
        if(dis[u]<d)continue;   //if the node is repeated in the pq take the smallest one
        for(ii ch:adj[u])
        {
            if(d+ch.first<dis[ch.second])
            {
                dis[ch.second]=d+ch.first;
                pt[ch.second]=u;
                pq.push({dis[ch.second],ch.second});
            }
        }
    }
}
void init()
{
    memset(dis,OO,sizeof dis);
}
int main()
{
    scanf("%d%d",&n,&m);
    init();
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d%d",&u,&v,&c);
        adj[u].push_back({c,v});
    }
    Dijkstra(1);
    for(int i=2;i<=n;++i)
    {
        printf("SSSP from 1 to %d=%d\n",i,dis[i]);
    }
    printpath(3);
}
