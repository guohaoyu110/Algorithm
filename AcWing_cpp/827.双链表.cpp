#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
int l[N],r[N],e[N],idx;
//可以不定义head和tail

//初始化
void init()
{
    //0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0;
    idx = 2;//因为0和1被占用了 
}

//在下标是k的右边，插入一个点x
void add(int k,int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;//先调用r[k],后修改
    r[k] = idx;
    idx ++;
}

//删除第k个节点
void remove (int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    int m;
    init();
    cin>>m;
    for(int i=0;i<m;i++)
    {
        //只能用string类型，不能用char类型，因为有IL这些，不是一个字母
        string op;
        cin>> op;
        int k,x;
        if (op == "R")
        {
            cin>>x;
            add(l[1], x);
        }
        else if (op == "D")
        {
            cin>>k;
            remove(k+1);
        }
        else if (op == "L")
        {
            cin>>x;
            add(0,x);
        }
        //第k个节点应该是k+1，因为idx从2开始的
        else if (op == "IL")
        {
            cin>>k>>x;
            add (l[k+1],x);
        }
        else if (op == "IR")
        {
            cin>>k>>x;
            add (k+1,x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i]) 
        cout << e[i] <<  ' ';
    cout<<endl;
    return 0;
}