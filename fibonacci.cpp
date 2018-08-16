#include <bits/stdc++.h>

#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define INF INT_MAX
#define pf(x) printf("%lld\n", x)
#define LL long long


LL dp[100];

LL fib(LL n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(dp[n]!=-1) return dp[n];
    else{
        dp[n] = fib(n-1) + fib(n-2);
    }
}

int main()
{

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    mem(dp, -1);
    pf(fib(89));

	return 0;
}
