//快速排序是不稳定的！
#include <iostream>
using namespace std;
const int N = 1e5+10;
int q[N];

void quick_sort(int q[],int l,int r)
{
    if (l>=r) return;
    int x = q[l+r>>1],i=l-1,j=r+1;
    while(i<j)
    {
        do i++; while (q[i]<x);
        do j--; while (q[j]>x);
        //一直到打破这个平衡的时候，然后把这两个颠倒
        if (i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        cin>>q[i];
    }
    quick_sort(q,0,m-1);
    cout<<q[n-1]<<endl;
    return 0;
}