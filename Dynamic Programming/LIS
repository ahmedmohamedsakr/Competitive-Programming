#include<bits/stdc++.h>                                                //Space  O(n)
using namespace std;                                                   //Time   O(n^2)
const int N=1e3+5;
int mem[N],n,A[N],maxi,dp[N];
int LIS(int cur)                 //Top-Down LIS
{
    int & ret=mem[cur];
    if(~ret)return ret;
    ret=1;
    for(int prev=0; prev<cur; ++prev)
        if(A[prev]<A[cur])
            ret=max(ret,LIS(prev)+1);
    return ret;
}
int LIS2(){                                                    //Bottom-Up(table method) LIS
	for(int cur = 0 ; cur < n ; ++cur){
		int & ret = dp[cur];
		ret = 1;
		for(int prev = 0 ; prev < cur ; ++prev)
			if(A[prev] < A[cur])
				ret = max(ret, dp[prev]+1);
		maxi = max(maxi, ret);
	}
	return maxi;
}
void init()
{
    memset(mem,-1,sizeof mem);
}
int main()
{
    scanf("%d",&n);
    init();
    for(int i=0; i<n; ++i)
        scanf("%d",&A[i]);
    for(int i=1; i<n; ++i)
        maxi=max(maxi,LIS(i));
    printf("Top-Down LIS: %d\n",maxi);
    maxi=0;
    printf("Bottom-Up LIS: %d\n",LIS2());
    return 0;
}
