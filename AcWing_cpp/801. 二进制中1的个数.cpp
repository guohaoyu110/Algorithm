//位运算的题目还是很重要的
#include <iostream>
#include <algorithm>
using namespace std;
//const int N = 1e9+10;
//int q[N];

int lowbit(int x)
{
    return x & -x;
}

//int b;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int res = 0;
        while(x) 
        {
            x -=lowbit(x); res++;
        }
        cout<<res<<" ";
    }
    

    return 0;
}