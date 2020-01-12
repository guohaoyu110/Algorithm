#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int N = 110;
int n,m;
int g[N][N],d[N][N];

int bfs()
{
    queue<PII> q;
    memset (d,-1,sizeof(d));
    d[0][0] = 0;
    q.push({0,0});

    int dx[4]={-1,0,1,0}; dy[4] = {0,1,0,-1};
    while(q.size()){
        auto t = q.front();
        q.pop();
        
    }
}
int main()
{

    return 0;
}