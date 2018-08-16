#include<bits/stdc++.h>

using namespace std;

#define mx 1000
char A[mx],B[mx];
int l1,l2;
int dp[mx][mx];
bool visited[mx][mx];
string ans;

int LCS(int i,int j)
{
    if(A[i]=='\0' || B[j]=='\0')
        return 0;

    if(visited[i][j])
        return dp[i][j];

    int ans=0;

    if(A[i]==B[j])
        ans=1+LCS(i+1,j+1);

    else
    {
        int val1 = LCS(i+1,j);
        int val2 = LCS(i,j+1);
        ans=max(val1,val2);
    }

    visited[i][j]=1;
    dp[i][j]=ans;

    return dp[i][j];
}


void print(int i,int j)
{
    if(A[i]=='\0' || B[j]=='\0')
    {
        cout<<ans<<endl;
        return;
    }

    if(A[i]==B[j])
    {
        ans+=A[i];
        print(i+1,j+1);
    }

    else
    {
        if(dp[i+1][j]>dp[i][j+1]) print(i+1,j);
        else print(i,j+1);
    }
}

void print_All(int i,int j)
{
    if(A[i]=='\0' or B[j]=='\0')
    {
        cout<<ans<<endl;
        return;
    }

    if(A[i]==B[j])
    {
        ans+=A[i];
        print_All(i+1,j+1);
        ans.erase(ans.end()-1);
    }

    else
    {
        if(dp[i+1][j]>dp[i][j+1])
            print_All(i+1,j);
        else if(dp[i+1][j]<dp[i][j+1])
            print_All(i,j+1);
        else
        {
            print_All(i+1,j);
            print_All(i,j+1);
        }
    }
}

int main()
{
    scanf("%s %s",A,B);
    l2 = strlen(A);
    l1 = strlen(B);
    printf("%d\n",LCS(0,0));
    print_All(0,0);
    return 0;
}
