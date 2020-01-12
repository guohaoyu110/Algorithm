#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int N = 110;
int n,m;
int g[N][N],d[N][N];//g数组存的是这个地图
//d数组存的是每个点到起点的距离

int bfs()
{
    queue<PII> q;
    memset (d,-1,sizeof(d));
    d[0][0] = 0;
    q.push({0,0});//两个数字分别代表坐标x和坐标y,x是多少行，y是多少列

    int dx[4]={-1,0,1,0}; int dy[4] = {0,1,0,-1};
    while(q.size()){
        auto t = q.front();
        q.pop();
        //尝试往上下左右四个方向扩展
        for(int i=0;i<4;i++)
        {
            int x = t.first + dx[i], y =t.second + dy[i];
            if (x>=0 && x<n && y>=0 && y<m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x,y});
             }
        }
    }
    return d[n-1][m-1];
}
int main()
{
    cin>> n >> m;
    for(int i = 0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    cout<<bfs()<<endl;

    return 0;
}