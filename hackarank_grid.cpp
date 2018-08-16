
#include <bits/stdc++.h>

using namespace std;

#define mx 11
int n;
int grid[mx][mx];
bool visited[mx][mx];
void Clear()
{
    for(int i=0;i<mx;i++)
        for(int j=0;j<mx;j++)
            visited[i][j] = false;

}
bool isvalid(int x,int y)
{
    if(x>=0 && y< n && x < n && y >=0 )
        return true;
    return false;

}
int cnt = -12;
void f(int x,int y,int c)
{
    //cnt++;
    visited[x][y] = true;

    //printf("%d\n",cnt);
    if (grid[x][y]==0)
    {
        cnt = max(c,cnt);
        return ;
    }


   // if(isvalid(x-1,y) && !visited[x-1][y]&& grid[x-1][y])
     //   f(x-1,y,c+1);
    //if(isvalid(x,y-1)&& !visited[x][y-1]&& grid[x][y-1])
        //f(x,y-1,c+1);
     if(isvalid(x,y+1 && !visited[x][y+1] && grid[x][y+1]))
        f(x,y+1,c+1);
     if(isvalid(x+1,y-1) && !visited[x+1][y-1] && grid[x+1][y-1])
        f(x+1,y-1,c+1);
     if(isvalid(x+1,y) && !visited[x+1][y]&& grid[x+1][y])
        f(x+1,y,c+1);
     if(isvalid(x+1,y+1) && !visited[x+1][y+1] && grid[x+1][y+1])
        f(x+1,y+1,c+1);
}

int main()
{

    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            int xx;
            cin >> xx;
            grid[i][j] = xx;

        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int cmp  =-12;
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(grid[i][j])
            {
                cnt = 0;
                Clear();

                f(i,j,0);
                cmp =max(cnt,cmp);
                //printf("[%d,%d] = %d\n",i,j,cnt);

            }

        }

    }
    printf("%d\n",cmp);

    return 0;
}
