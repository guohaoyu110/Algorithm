#include <iostream>
using namespace std;
const int N = 1e5+10;
int stk[N],tt;

int main()
{
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        while(tt&&stk[tt]>=x)
            tt--;
        //最后保持一个单调上升的曲线
        if(tt) cout<<stk[tt]<<" ";
        else  cout << -1 <<" ";

        stk[++tt] = x;
    }
    return 0;
}