#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], q[N], hh, tt = -1;//head 和 tail
//后加入的是队尾

int main()
{
    //int hh=0,tt =-1;
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    //得出最小元素
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if (hh<=tt&&i-k+1>q[hh]) 
            ++hh; // hh+1
        while(hh<=tt&&a[i]<=a[q[tt]])
            --tt; //把它删掉
        q[++tt] = i;
        if (i+1>=k) cout<<a[q[hh]]<<" ";
    }
    //这样做可以在O(1)的时间找到最值！
    //不懂的话可以模拟一下这个全过程
    cout<<endl;
    //得出最大元素
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++ i)
    {
        if (i - k + 1 > q[hh]) 
            ++ hh;
        while (hh <= tt && a[i] >= a[q[tt]]) 
            -- tt;
        q[++ tt] = i;
        if (i + 1 >= k) 
            //printf("%d ", a[q[hh]]);
            cout<< a[q[hh]]<<" ";
    }
    return 0;
}