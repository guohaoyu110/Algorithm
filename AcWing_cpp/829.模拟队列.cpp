#include <iostream>
using namespace std;
const int N = 1e5+10;
int q[N],tt=-1, hh;

int main()
{
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string op;
        cin>> op;
        if (op == "push")
        {
            int x;
            cin>>x;
            q[++tt] = x;
        }
        else if (op == "pop")
        {
            hh++;
        }
        else if (op == "empty")
        {
            if (hh<=tt) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else if (op == "query")
        {
            cout<<q[hh]<<endl;
        }
    }
    return 0;
}