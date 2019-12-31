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

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    
    return 0;
}