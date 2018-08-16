#include<bits/stdc++.h>

using namespace std;
#define M 100
vector<int>graph[100],re_g[100];

int visited[100],color[100], cycle = 0;
vector<int> v;
vector<int> ans;
void dfs(int p)
{
    visited[p]=1;
    for(int i=0;i<graph[p].size();i++)
    {
        int x = graph[p][i];
        if(!visited[x])
            dfs(x);
    }
    visited[p] = 2;
    v.push_back(p);

}
void printtop()
{
    cout<<":::::TOPSORT:::::"<<endl;
    for(int i=v.size()-1;i>=0;i--)
    {
        printf("%d ",v[i]);
    }
    puts("\n-------------");
}

void scc(int p)
{

    color[p]=1;
    for(int i=0;i<re_g[p].size();i++)
    {
        int x = re_g[p][i];
        if(!color[x])
            scc(x);
    }
    color[p] = 2;
    ans.push_back(p);
}
int main()
{
    freopen("inp.txt","r",stdin);
    int node,edge;
    cin>>node>>edge;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<edge;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        re_g[y].push_back(x);
    }

    for(int i=1;i<=node;i++)
        if(!visited[i])
            dfs(i);

    printtop();//print top sort


    for(int i=v.size()-1;i>=0;i--)
    {
        int x = v[i];
        if(!color[x])
        {
            scc(x);
            cout<<"Components"<<endl;
            for(int j=0;j<ans.size();j++)
                printf("%d ",ans[j]);
             puts("");
             ans.clear();
        }


    }
    return 0;
}
