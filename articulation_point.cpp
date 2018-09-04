#include<bits/stdc++.h>
using namespace std;


#define nil -1
#define inf 10000
#define mx 1000
#define white 0
#define black 2
#define grey 1
vector<int>edge[mx],cost[mx];
int color[mx],low[mx],f[mx],d[mx];
int parent[mx+1];
int time;
int e,n;
bool arti[mx];

void init()
{
	for(int i=0;i<n;i++)
	{
		color[i]=white;
		parent[i] = nil;
		low[i]=inf;
		f[i]=inf;
		d[i]=inf;

	}

}
void dfs(int p)
{
	time++;int children = 0;
	color[p]=grey;
	d[p] =time;
	for(int i=0;i<edge[p].size();i++)
	{
		int v =edge[p][i];
		if(color[v]==white)
		{
			children++;

			parent[v] = p;
			dfs(v);
			low[p] = min(low[v],low[p]);
			if(children>1 && parent[p]==nil)
				arti[p]=true;
			if(parent[p]!=nil && low[v]>=d[p])
				arti[p] =true;

		}
		else if(v != parent[p])
			low[p]=min(low[p],d[v]);
	}
	color[p]=black;
	time++;
	f[p] =time;


}
int  main()
{

	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);

	}
	init();
	time=0;
	for(int i=0;i<n;i++)
	{
		if(color[i]==white)
		{
			dfs(i);
		}

	}
	cout<<"articulation point"<<endl;
	for(int i=0;i<n;i++)
	{
		if(arti[i])
			cout<<i<<" ";
	}
	return 0;
}
