#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5,M=1e4,OO=0x3f3f3f3f;
int n,m,u,v,dis[N],p;
vector<int>adj[N];

void bfs(int src)
{
    memset(dis,OO,sizeof dis);
    queue<int>q;
    q.push(src);
    dis[src]=0;
    while(!q.empty())
    {
        p=q.front(); 
        q.pop();
        for(auto it:adj[p])if(dis[it]==OO)dis[it]=dis[p]+1,q.push(it);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    bfs(p);
    printf("Tree Diameter = %d",dis[p]);
    return 0;
}
