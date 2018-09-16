#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N=5e3+4,M=2e2+4,OO=0x3f3f3f3f;
int C[N],R[N],n;
ll mem[N][N];
//Matrix Chain Multiplication
ll MCM(int l=0,int r=n-1){
        if(l==r)return 0;
        ll &ret=mem[l][r];
        if(~ret)return ret;
        ret=OO;
        for(int mid=l;mid<r;++mid){
            ll ans=MCM(l,mid)+MCM(mid+1,r)+R[l]*C[mid]*C[r];
            ret=min(ret,ans);
        }
        return ret;
}

void print(int l=0,int r=n-1){
        if(l==r){
                printf("%c",char('A'+l));
                return;
        }
        ll ret=MCM(l,r);
        printf("(");
        for(int mid=l;mid<r;++mid){
            if(ret==MCM(l,mid)+MCM(mid+1,r)+R[l]*C[mid]*C[r]){
                print(l,mid);
                printf("*");
                print(mid+1,r);
                break;
            }
        }
        printf(")");
}

int main()
{
    memset(mem,-1,sizeof mem);
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d%d",&R[i],&C[i]);
    printf("%lld\n",MCM());
    print();
    return 0;
}
