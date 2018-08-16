#include<bits/stdc++.h>
using namespace std;
#define mx 100
int a[] = {-100000,5,0,9,2,7,3,4};
int n=7;
int dp[mx];
int dir[mx];
int LIS(int u)
{
    if(dp[u]!=-1) return dp[u];
    int maxi = 0;
    for(int v = u+1;v<=n;v++)
    {
        if(a[v]>a[u])
        {
            int t = LIS(v);
            if(t>maxi)
            {
                maxi = t;
                dir[u] = v;
            }
        }
    }
    dp[u] = 1+ maxi;
    return dp[u];
}
void solution(int start)
{
    while(dir[start]!= -1)
    {
        printf("%d ",a[start]);
        start= dir[start];
    }
    printf("%d ",a[start]);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    /*cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];*/
    int l = LIS(0);
    printf("Max length is : %d\n\n",l);
    int lis=-12,start;
    for(int i=0;i<n;i++)
    {
        printf("longest path from %d: %d\n",i,LIS(i));
        if(LIS(i)>lis)
        {
            lis=LIS(i);
            start=i;
        }
    }
    cout<<start<<endl;
    cout<<"Solution :"<<endl;
    solution(start);
    return 0;
}
