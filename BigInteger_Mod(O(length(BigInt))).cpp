#include <bits/stdc++.h>

using namespace std;

char arr[] = {'a','b','c','d'};
vector<char>result;
int taken[20]={0};
int len;
int mod  = 5;

long long f (long long a, long long b)
{
    if(b == 0)
        return 1;
    if(b%2==0)
    {
        long long ret = f(a,b/2);
        return ((ret%mod)*(ret%mod))%mod;
    }
    return ((a%mod)*(f(a,b-1)%mod))%mod;
}
int calc(int a,int b)
{
    return ((a%mod)+(b%mod))%mod;
}
int main()
{



    char ar[] ="12068e9083048230820332";
    len = strlen(ar);
    //cout<<len<<endl;
    int res = 0;
    for(int i=0;i<len;i++)
    {
        res = ((res%mod)*(10%mod))%mod;

        res  = calc(res,(int)(ar[i]-'0'));

    }

    printf("%d\n",res);

    return 0;

}
