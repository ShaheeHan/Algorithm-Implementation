#include<bits/stdc++.h>

using namespace std;
#define mx 10001
int kadane(int sub[], int x)
{
    int Local_mx=0, Global_mx=0;
    for(int i=0; i<x; i++)
    {
        Local_mx = max(0, Local_mx+sub[i]);
        Global_mx = max(Global_mx, Local_mx);
    }
    return Global_mx;
}

int main()
{
    int x;
    int a[1000];
    scanf("%d",&x);
    for(int i=0;i<x;i++)
        cin>>a[i];
    printf("%d\n",kadane(a,x));
}
