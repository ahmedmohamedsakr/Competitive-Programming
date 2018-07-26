#include <bits/stdc++.h>                     //O(V+E)
using namespace std;                         //unweighted graph

const int N = 1e4 + 5, OO = 0x3f3f3f3f;
int dis[N],n,m,u,v, x;
vector<int> adj[N];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int ch : adj[p])
        {
            if(dis[ch]==OO)
            {
                dis[ch]=dis[p]+1;
                q.push(ch);
            }
        }
    }
}
void init()
{
    memset(dis, OO, sizeof dis);
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < m ; ++i)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(1);
    for(int i = 2 ; i <= n ; ++i)
        printf("SSSP from 1 to %d=%d \n",i,dis[i]);
    return 0;
}
