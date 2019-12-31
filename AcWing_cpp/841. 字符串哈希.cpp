//朴素做法，但是这种做法是超时的！
'''
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1e5+10;

int main()
{
    int m,n;
    cin>>m>>n;//m个字母，n个询问
    string s;
    for(int i=1;i<=m;i++){
        cin>>s[i];
    }
    for(int i = 0; i<n;i++)
    {
        int l1,l2,r1,r2;
        cin>>l1>>r1>>l2>>r2;
        int flag = 0;
        for(int i=l1,j=l2;i<=r1,j<=r2;){
            if (s[i] == s[j]){
                i++;j++;
            }
            flag ++;
             
        }
        if (flag == r1-l1+1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}
'''
// 之前那种两种循环的复杂度太高，可以用哈希的方式
//当我们需要快速判断两个字符串是不是相等，就可以用这种做法！
#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5+10;
ULL h[N],p[N]; //h[k] 存储字符串前k个字母的哈希值，p[k]存储p^k mod 2 ^64
char str[N];

const int P = 131;

ULL get (int l, int r)
{
    return h[r] - h[l-1]*p[r-l+1];
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    scanf("%s",str+1);//输入str第一个元素之后的字符串，就是不是从0开始读，从1开始读
    //string类型的话，全部都是从0开始读入的。
    //理解为从str[1]开始往后读，全部都是读进去的！
    p[0] = 1;
    for (int i = 1;i<=n;i++)
    {
        h[i] = h[i-1]*P + str[i];
        p[i] = p[i-1]*P;
    }
     while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if (get(l1,r1)==get(l2,r2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}