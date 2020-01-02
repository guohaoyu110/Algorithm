//方法一：第一种用DFS的方法
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 20;
int n;
char g[N][N];//就是存储整个棋盘的矩阵
bool col[N],dg[N],udg[N];

// u=0的时候，第一层；u=n的时候，就是最后一层了；dfs就是把所有的情况都遍历一遍
// u=0意味着第一列
void dfs(int u)
{
    if (u==n)
    {
        for(int i =0;i<n;i++)
            cout<<g[i]<<endl;
        cout<<endl;
        return ;
    }
    //i相当于y轴，u相当于x轴。相当于第u列，第i行！
    //其实dfs那个u是每一列来+1遍历，i是每一行来查看
    for(int i=0;i<n;i++) //根据这个每一行来
    {
        if (!col[i]&&!dg[u+i]&&!udg[n-u+i]) //这一列之前必须没有放过并且对角线和反对角线上也没有放过
        {
            g[u][i] = 'Q';
            col[i] = dg[u+i] = udg[n-u+i] = true;
            dfs(u+1);
            col[i] = dg[u+i] = udg[n-u+i] = false;
            g[u][i] = '.';
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j = 0;j<n;j++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}

//方法二，第二种使用DFS的情况
#include <iostream>
using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int x,int y,int s)
{
    if (s>n) return;
    if (y==n) y=0,x++;
    if (x == n)
    {
        if (s == n)
        {
            for(int i=0;i<n;i++) cout<<g[i]<<endl;
            cout<<endl;
        }
        return;
    }
     g[x][y] = '.';
    dfs(x, y + 1, s);

    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        g[x][y] = 'Q';
        dfs(x, y + 1, s + 1);
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
    }
}

int main()
{
    cin>>n;
    dfs(0,0,0);
    return 0;
}