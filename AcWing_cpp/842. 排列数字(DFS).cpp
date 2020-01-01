#include <iostream>
using namespace std;
const int N = 10;
int n;
int path[N]; //用这个path数组来记录每一条路径
bool st[N]; //用一个bool数组来记录是不是这个被用过了

//当我们搜到叶节点的时候，path上的每一个数字就填好了
void dfs(int u)
{
    if (u==n){
        //说明走到最底下了
        for(int i = 0;i<n;i++)
            cout<<path[i]<<" ";
        cout<<endl;
        return;//结束这一次dfs
    }
    for(int i=1;i<=n;i++)
        if(!st[i]){
            path[u] = i;
            st[i] = true;
            dfs(u+1);
            st[i] = false;
        }
}

int main()
{
    cin>>n;
    dfs(0);
    return 0;
}