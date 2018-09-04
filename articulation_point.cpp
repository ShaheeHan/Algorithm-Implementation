#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
 
#define mx 10009
#define nil -1
#define inf 10000
#define white 0
#define black 2
#define grey 1
vector<int>edge[mx],cost[mx];
int color[mx],low[mx],f[mx],d[mx],num_of_children[mx];
int parent[mx+1];
int tme;
bool arti[mx];
int e,n;
int cnt;
void init()
{
    for(int i=0;i<=n;i++)
    {
        color[i]=white;
        parent[i] = nil;
        low[i]=inf;
        f[i]=inf;
        d[i]=inf;
    }
 
}
void dfs(int u)
{
    tme++;int children = 0;
    color[u]=grey;
    d[u] =tme;
    for(int i=0;i<edge[u].size();i++)
    {
        int v =edge[u][i];
        if(color[v]==white)
        {
            children++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
 
            if(low[v]>=d[u])
                arti[u] =true;
 
        }
        else if(v != parent[u])
            low[u]=min(low[u],d[v]);
    }
    num_of_children[u]=children;
    color[u] = black;
    //tme++;
    f[u]=tme;
}
int  main()
{
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++)
    {
        fill_n(num_of_children,10005,0);
        cin>>n>>e;
        for(int i=0;i<e;i++)
        {
            int x,y;
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
 
        }
        init();
        tme=0;
        for(int i=0;i<mx;i++) arti[i] =false;
        //memset(arti,false,sizeof(arti));
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==white)
            {
                dfs(i);
                arti[i]=(num_of_children[i]>1);
            }
 
        }
        for(int i=1;i<=n;i++)
            if(arti[i]==true) cnt++;
        printf("Case %d: %d\n",cases,cnt);
        for(int i=0;i<mx;i++)
            edge[i].clear();
    }
    return 0;
}
