#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e3+4,M=35,OO=0x3f3f3f3f;
int n,arr[N],LIS[N],LDS[N];
int Longest_Bitonic_Subsequence(){
    for(int i=0;i<n;++i)LIS[i]=LDS[i]=1;
    //longest increasing subsequence
    for(int i=1;i<n;++i)
        for(int j=0;j<i;++j)if(arr[j]<arr[i])LIS[i]=max(LIS[i],LIS[j]+1);
    //longest decreasing subsequence:Compute Longest increasing subsequence from right to lift
    for(int i=n-2;i>=0;--i)
        for(int j=n-1;j>i;--j)if(arr[j]<arr[i])LDS[i]=max(LDS[i],LDS[j]+1);
    int maxi=0;
    for(int i=0;i<n;++i)if(maxi<LIS[i]+LDS[i]-1)maxi=LIS[i]+LDS[i]-1;
    return maxi;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",&arr[i]);
    printf("%d",Longest_Bitonic_Subsequence());
    return 0;
}
