/*

https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

k ==> Number of floors
n ==> Number of Eggs
  eggDrop(n, k) ==> Minimum number of trials needed to find the critical
                    floor in worst case.
  eggDrop(n, k) = 1 + min{max(eggDrop(n - 1, x - 1), eggDrop(n, k - x)):
                 x in {1, 2, ..., k}}
*/


#include <bits/stdc++.h>

using namespace std;
const int N = 1e4+5, M = 1e4, OO = 0x3f3f3f3f;
int n,k,T[N][N],mem[N][N];

int eggDropping(int eggs=n,int floors=k)
{

    for(int i=0; i<=k; ++i)T[1][i]=i;

    for(int e=2; e<=eggs; ++e)
    {
        for(int f=1; f<=floors; f++)
        {
            T[e][f]=OO;
            for(int j=1; j<=f; ++j)
                T[e][f]=min(T[e][f],1+max(T[e-1][j-1],T[e][f-j]));
        }
    }
    return T[eggs][floors];
}

int recEggDropping(int eggs=n,int floors=k)
{
    if(eggs==1)return floors;
    if(floors==0||floors==1)return floors;

    int &ret=mem[eggs][floors];
    if(ret!=OO)return ret;


    for(int j=1; j<=floors; j++)
        ret=min(ret,1+max(recEggDropping(eggs-1,j-1),recEggDropping(eggs,floors-j)));

    return ret;
}

void init()
{
    memset(mem,OO,sizeof mem);

}

int main()
{
    scanf("%d%d",&n,&k);
    init();
    printf("Minimum number of trials in worst case with %d eggs and %d floors is %d\n",n,k,eggDropping());
    printf("recursion:Minimum number of trials in worst case with %d eggs and %d floors is %d\n",n,k,recEggDropping());


    return 0;
}
