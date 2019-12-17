#include <iostream>
using namespace std;
const int N = 1e5+10;
int q[N];
void merge_sort(int q[],int l,int r)
{
    int tmp[N];
    if (l>=r) return;
    int mid = (l + r )>> 1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    //after merge_sort，两个数组分别排好了，现在下面的步骤是要把两个排好的数组合起来。
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if (q[i]<q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while(i<=mid) tmp[k++] = q[i++];
    while(j<=r) tmp[k++] = q[j++];
        
    for(i=l,j=0;i<=r;i++,j++)
        q[i] = tmp [j];
}
int main()
{
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>q[i];
    }
    merge_sort(q,0,m-1);
    for(int i=0;i<m;i++)
        cout<<q[i]<<" ";
    return 0;
}