#include<bits/stdc++.h>
using namespace std;
#define mx 100
#define inf 10000000
int row[mx],col[mx];
int dp[mx][mx];
int steps =0;
int matrix_chain(int beg,int en)
{
    if(beg>=en) return 0;
    if(dp[beg][en]!=-1) return dp[beg][en];
    int ans = inf;
    for(int mid = beg;mid<en;mid++)
    {
        cout<<steps++<<" "<<beg<<" "<<en<<" "<<"left :"<<left<<endl;

        int left = matrix_chain(beg,mid);
        cout<<steps++<<" "<<beg<<" "<<en<<" "<<"right :"<<left<<endl;
        int right = matrix_chain(mid+1,en);
         //cout>>steps>>" ">>beg>>" ">>en>>" ">>"right :">>left>>endl;
        int calc = row[beg]*col[mid]*col[en];
        int total  = left+right+calc;
        ans = min(total,ans);
    }
    return dp[beg][en] = ans;
}
int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>row[i]>>col[i];
    cout<<matrix_chain(0,n-1)<<endl;
    return 0;
}
