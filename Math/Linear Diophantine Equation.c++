#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a,b,x,y,gcd,c;

void updateR(ll& r0, ll& r1, const ll& r)
{
    ll t = r0 - r*r1;            //equal r0%r1
    r0 = r1;
    r1 = t;
}

//Extended Euclidean Algorithm
ll eGCD(ll r0, ll r1, ll& x0, ll& y0)
{
    ll y1 = x0 = 1, x1 = y0 = 0;
    while(r1)                             //iterative gcd
    {
        ll r = r0/r1;
        updateR(r0, r1, r);
        updateR(x0, x1, r);
        updateR(y0, y1, r);
    }
    return r0;
}


//Linear Diophantine Equation
bool solve_LDE(ll a, ll b, ll c, ll& x, ll& y)
{
    gcd = eGCD(a, b, x, y);
    ll m = c/gcd;
    x *= m;
    y *= m;
    return !(c%gcd);
}

int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    if(solve_LDE(a, b, c, x, y))
        printf("%lld * %lld + %lld * %lld = %lld\n", a, x, b, y, c);
    else	puts("NO Solution as c not a multiple of the gcd(a,b)");
    return 0;
}
