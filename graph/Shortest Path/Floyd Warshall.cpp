#include <bits/stdc++.h>                      //O(V^3)
using namespace std;
const int V=4e3,OO=0x3f3f3f3f;                //V<=400
int AdjMat[V][V],n,m,u,v,c,par[V][V];

void calcShortestPath()
{
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            par[i][j]=i;                 //initialize the parent matrix with last vertex before j
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
            {
                if(AdjMat[i][k]+AdjMat[k][j]<AdjMat[i][j])
                {
                    AdjMat[i][j]=AdjMat[i][k]+AdjMat[k][j];
                    par[i][j]=par[k][j];
                }
            }

}
void printPath(int i,int j)
{
    if(i!=j)printPath(i,par[i][j]);
    printf("%d ",j);
}
void floydWarshall()
{
    for(int k=0; k<n; k++)             //0 based
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                AdjMat[i][j]=min(AdjMat[i][j],AdjMat[i][k]+AdjMat[k][j]);
}
void init()
{
    memset(AdjMat,OO,sizeof AdjMat);
}
int main()
{
    scanf("%d%d",&n,&m);
    init();
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d%d",&u,&v,&c);
        AdjMat[u][v]=c;
    }
    //floydWarshall();
    calcShortestPath();
    printf("distance from 0 to 2=%d\n",AdjMat[0][2]);
    printPath(0,2);
    return 0;
}
