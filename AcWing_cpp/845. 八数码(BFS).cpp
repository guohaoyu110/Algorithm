#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
//这道题目求最短相关的问题，明显用BFS来做
//至少经过多少次交换能够把x换到最右下角的位置
int bfs(string start){
    string end = "12345678x";
    queue<string>q;
    unordered_map<string,int> d;
    q.push(start);
    d[start] = 0;
    int dx[4] ={-1,0,1,0}, dy[4] = {0,1,0,-1};
    while(q.size()){//这是一个经典的BFS过程
        auto t = q.front();
        q.pop();
        //尝试往上下左右四个方向扩展
        int distance = d[t];
        if (t == end) return distance;
        //状态转移
        int k = t.find('x');
        int x = k/3, y = k%3;

        for(int i=0;i<4;i++)
        {
            int a = x + dx[i], b = y + dy[i];//a b是x y上下左右的某一个数字
            if (a>=0&&a<3&&b>=0&&b<3){
                //swap(t[k],t[a*3+b]);
                swap(t[a*3+b],t[k]);
                if(!d.count(t)){
                    d[t] = distance + 1;
                    q.push(t);
                }
                //swap(t[k],t[a*3+b]);
                swap(t[a*3+b],t[k]);
            }
        }
    }
    return -1;
}

int main()
{
    string start;
    for(int i =0;i<9;i++){
        char c;
        cin>>c;
        start += c;

    }
    cout<<bfs(start)<<endl;
    return 0;
}