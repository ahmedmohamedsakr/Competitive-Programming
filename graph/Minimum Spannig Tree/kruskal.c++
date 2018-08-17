#include <bits/stdc++.h>           //O(E*log(V))

using namespace std;

const int N = 2e5+5,M=1e4+5,OO=0x3f3f3f3f;

int n,m,u,v,c,cnt,total;
int par[N];

struct edge{
	int f, t, c;
	bool operator <(const edge & e) const{
		return c < e.c;
	}
}E[M];

void init(){
	iota(par, par+n, 0);
}

int find(int u){
	return (par[u] == u ? u : par[u] = find(par[u]));
}

inline void join(int a, int b){
	a = find(a), b = find(b);
	if(a == b)	return;
	par[b] = a;
}

inline bool sameSet(int a, int b){
	return find(a) == find(b);
}


int main(){

	scanf("%d%d",&n,&m);
	init();
	for(int i = 0 ; i < m ; ++i){
			scanf("%d%d%d",&u,&v,&c);
			E[cnt++] ={u,v,c};
	}
	sort(E, E+cnt);
	for(int i = 0;i<cnt;++i){
		if(!sameSet(E[i].f,E[i].t)){
			join(E[i].f, E[i].t);
			total+= E[i].c;
		}
	}
	printf("%d\n",total);
	return 0;
}
