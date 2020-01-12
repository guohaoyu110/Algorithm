#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
//这道题目求最短相关的问题，明显用BFS来做
//至少经过多少次交换能够把x换到最右下角的位置
//思考：如何记录每个状态的距离，距离数组的坐标如何表示
//distance可以用C++里的哈希表，java或者python里的字典，就可以存了。
int bfs(string start){
    string end = "12345678x";
    queue<string>q;//宽搜都需要定义一个队列
    unordered_map<string,int> d;//用这样的一个数据结构来存distance，距离数组

    q.push(start);
    d[start] = 0;//start是起初的那个字符串
    int dx[4] ={-1,0,1,0}, dy[4] = {0,1,0,-1};
//这是一个经典的BFS过程
//在这个BFS过程中，queue的用法是这样的
    while(q.size()){
        string t = q.front();
        q.pop();
        //尝试往上下左右四个方向扩展
        int distance = d[t];
        if (t == end) return distance;//判断t是不是终点，如果是终点的话，可以提前结束了
        //状态转移
        int k = t.find('x');//k表示在字符串中的位置

        int x = k/3, y = k%3;//找到x所在的坐标

        for(int i=0;i<4;i++)
        {
            int a = x + dx[i], b = y + dy[i];//a b是x y上下左右的某一个数字
            if (a>=0&&a<3&&b>=0&&b<3){
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