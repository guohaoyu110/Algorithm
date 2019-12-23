//这个有点类似归并排序中两个指针在不同的数组里
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int a[N];
int b[N];

int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int j=0;j<m;j++) cin>>b[j];

    for(int i=0,j=m-1;i<n;i++)
    {
        while(j>=0&&a[i]+b[j]>x)
            j--;
        if (a[i]+b[j]==x)
        {
            cout<<i<<" "<<j;
            //break;
        }
    }
    return 0;
}