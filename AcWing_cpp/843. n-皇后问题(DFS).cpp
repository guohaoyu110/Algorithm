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
void dfs(int u) //当前枚举第u行，我们的皇后应该放到哪一列
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
        if (!col[i]&&!dg[u+i]&&!udg[u-i+n]) //这一列之前必须没有放过并且对角线和反对角线上也没有放过
        {
            g[u][i] = 'Q';
            col[i] = dg[u+i] = udg[u-i+n] = true;
            dfs(u+1);
            col[i] = dg[u+i] = udg[u-i+n] = false;
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
'''======================================================================='''
//方法二，第二种使用DFS的情况
//第二种方法的效率比第一种方法要低一些
#include <iostream>
using namespace std;

const int N = 20;

int n;
char g[N][N];
bool row[N],col[N], dg[N], udg[N];//对角线和斜对角线

void dfs(int x,int y,int s) //s是表示皇后的个数
{
    //x是行，y是列
    if (s>n) return;
    if (y==n) y=0,x++;
    if (x == n) //还是按照一列一列的来放皇后的
    {
        if (s == n)
        {
            for(int i=0;i<n;i++) cout<<g[i]<<endl;
            cout<<endl;
        }
        return;
    }
    g[x][y] = '.';
    //不放皇后
    dfs(x, y + 1, s); //递归到下一个格子就可以了
    //放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) //这一行，这一列，这个对角线和反对角线上不能有皇后
    {
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;//更新状态
        g[x][y] = 'Q';
        dfs(x, y + 1, s + 1);
        //为什么递归过后恢复现场要做这个操作呢？
        // 因为如果上面这个行不通的话，就要返回到上一步，所以要恢复现场
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