#include <iostream>
using namespace std;
const int N = 10;
int n;
int path[N]; //用这个path数组来记录每一条路径
bool st[N]; //用一个bool数组来记录是不是这个被用过了

//当我们搜到叶节点的时候，path上的每一个数字就填好了
//深度优先的思想，特别典型的一道题目！
// u=0的时候，第一层；u=n的时候，就是最后一层了；dfs就是把所有的情况都遍历一遍
void dfs(int u)
{
    if (u==n){
        //说明走到最底下了
        for(int i = 0;i<n;i++)
            cout<<path[i]<<" ";
        cout<<endl;
        return;//结束这一次dfs
        //已经遍历了一次可能的情况
    }
    for(int i=1;i<=n;i++)//只有1到n可以作为数组的组成部分！
        if(!st[i]){
            path[u] = i;
            st[i] = true;
            dfs(u+1);//u+1就是继续往下走了，一直走到头为止
            //恢复现场
            st[i] = false;
        }
}

int main()
{
    cin>>n;
    dfs(0);
    return 0;
}