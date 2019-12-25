#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;

int idx;
int e[N],ne[N];
int head;

void init()
{
    head = -1;
    idx = 0;
}
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head; // idx 的next指针是head的next指针
    head = idx;
    idx ++;
}

void add (int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx ++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    init();
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        char op;
        cin>>op;
        int k,x;
        if (op=='H')
        {
            //int k;
            cin>>k;
            add_to_head(k);
        }
        else if (op=='D')
        {
            //int k;
            cin>>k;
            if (!k) head = ne[head];
            remove(k-1);
        }
        else if (op=='I')
        {
            //int k,x;
            cin>>k>>x;
            add(k-1,x);
        }
    }
    
    for(int i=head;i!=-1;i=ne[i])
    {
        cout<<e[i]<<" ";
    }
    return 0;
}