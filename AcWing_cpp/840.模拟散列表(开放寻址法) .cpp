#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 200003;//一定要找一个在这个大概数据范围的质数

int h[N],null = 0x3f3f3f3f;
//如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
int find(int x)
{
    int t = (x%N+N)%N;
    while(h[t]!=null && h[t]!=x ){
        t++;
        if (t== N) t = 0;//这个是循环的
    }
    return t;
}

int main(){
    int m,x;
    ios::sync_with_stdio(false);
    cin>>m;
    memset (h,0x3f,sizeof(h));
    while(m--){
        char op;
        cin>>op>>x;
        int k = find(x);
        if (op == 'I') h[k] = x;
        else if (op == 'Q') {
            if (h[k]!=null) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}