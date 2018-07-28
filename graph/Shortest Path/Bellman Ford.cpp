#include<bits/stdc++.h>                         //O(V*E)
using namespace std;                            //VE<=10M
typedef pair<int,int> ii;
const int N=1e5,OO=0x3f3f3f3f;
int dis[N],n,m,u,v,c;
vector<ii>adj[N];
bool CheckNegativeCycle()
{
    for(int u=1; u<=n; ++u)
        for(ii ch:adj[u])
            if(dis[ch.second]>dis[u]+ch.first)return 0;
    return 1;
}
void BellmanFord(int src)
{
    dis[src]=0;
    for(int i=0; i<n-1; ++i)
        for(int u=1; u<=n; ++u)       // 1 based
            for(ii ch:adj[u])
                dis[ch.second]=min(dis[ch.second],dis[u]+ch.first);
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
    BellmanFord(1);
    for(int i=2; i<=n; ++i)
        printf("SSSP from 1 to %d=%d\n",i,dis[i]);
    puts(CheckNegativeCycle()?"there is no NC":"there is NC");

    return 0;
}
