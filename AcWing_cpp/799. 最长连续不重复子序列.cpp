//双指针的问题，一个快指针，一个是慢指针
//用再开一个数组的方式来判断这个数字在数组中有没有多个！
//双指针的问题，一个快指针，一个是慢指针
//用再开一个数组的方式来判断这个数字在数组中有没有多个！

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int a[N],s[N];
int res = 0;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0,j=0;i<n;i++)
    {
        s[a[i]] ++;
        while(j<=i&&s[a[i]]>1)
        {
            //j++;
            s[a[j]]--;
            j++;
            res = max(res,i-j+1);
        }
        
    }
    cout << res;
    return 0;
}