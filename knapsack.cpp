
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)n; i++)

#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define INF INT_MAX

#define sf(x) scanf("%d",&x)
#define sff(x,y) scanf("%d%d",&x,&y)

using namespace std;


int n, cap, dp[100][1000], weight[100], cost[100];

int knap_Sack(int i, int w)
{
    if(i==n) return 0;
    if(dp[i][w] != -1) return dp[i][w];

    int profit1=0, profit2;

    if(w+weight[i] <= cap) profit1 = cost[i] + knap_Sack(i+1, w+weight[i]);
    profit2 = knap_Sack(i+1, w);

    dp[i][w] = max(profit1, profit2);

    return dp[i][w];

}

int main()
{

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int j, ans;

    sff(n, cap);
    for(j=0; j<n; j++){
        sff(weight[j], cost[j]);
    }

    mem(dp, -1);
    ans = knap_Sack(0, 0);

    cout << ans << endl;

	return 0;
}
