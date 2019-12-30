#include <iostream>
#include<cstring>
using namespace std;
const int N = 1e5+3;
int h[N],e[N],ne[N],idx;

//向哈希表中插入一个数
void insert(int x){
    int k = (x%N+N)%N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++;
}

//在哈希表中查询某个数是否存在
bool find (int x){
    int k = (x%N+N)%N;
    for(int i = h[k]; i!=-1;i = ne[i]){
        if (e[i] == x)
        {
            //cout<<"Yes"<<endl;
            return true;
        }
            
    }
    return false;
}

int main(){
    int m,x;
    ios::sync_with_stdio(false);
    cin>>m;
    memset (h,-1,sizeof(h));//sizeof(h) 加不加括号都可以
    while(m--){
        char op;
        cin>>op>>x;
        if (op == 'I')
        {
            insert(x);
        }
        else if (op == 'Q')
        {
            if (find(x) == true)
                cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }


    return 0;
}