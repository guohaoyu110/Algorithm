//方法一：第一种用DFS的方法
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 20;
int n;
char g[N][N];//就是存储整个棋盘的矩阵
bool col[N],dg[N],udg[N];

void dfs(int u)
{
    if (u==n)
    {
        for(int i =0;i<n;i++)
            cout<<g[i]<<endl;
        cout<<endl;
        return ;
    }
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