//先用数组做一遍，再用STL 做一遍
//STL可以做的，数组都可以做；数组可以做的，STL不一定可以做！

#include<iostream>
#include<string>

using namespace std;

const int N = 1e5+10;
int stk[N], tt;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string op;
        int x;
        cin >> op;
        if (op == "push") 
        {
            cin >> x;
            stk[++ tt] = x;
        }
        else if (op == "pop")
        {
            tt --;
        }
        else if (op == "query")
        {
            cout<<stk[tt]<<endl;
        }
        else if (op == "empty")
        {
            if (tt>0) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}