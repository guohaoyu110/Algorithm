#include <iostream>
using namespace std;
const int N = 1e5+10;
int h[N],e[N],ne[N],idx;

//向哈希表中插入一个数
void insert(int x){
    
}

//在哈希表中查询某个数是否存在
bool find (int x){

}

int main(){
    int m;
    cin>>m;
    while(m--){
        char op;
        if (op == 'I')
        {
            int x;
            cin>>x; 
            insert(x);
        }
        else if (op == 'Q')
        {
            int x;
            cin>>x;
            find(x);
        }
    }


    return 0;
}