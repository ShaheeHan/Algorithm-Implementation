#include<cstdio>
#include<iostream>

using namespace std;



int mod(int a, int b, int mod) {
    int ret=1;
    while(b) {
        if(b&1) {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}

int  bigmod(int a, int p, int m)
{
    if(p==0) return 1;

    if(p & 1) return ((a%m) * bigmod(a, p-1, m))%m;
    else{
        int ret = bigmod(a, p/2, m);
        return ((ret%m)*(ret%m))%m;
    }
}

int main()
{
    /// (a^b)%m
    int a, b, m;

    while(scanf("%d %d %d", &a, &b, &m)==3){

        printf("%d\n",mod(a, b, m));
    }

    return 0;
}
