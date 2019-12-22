s#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
const int N = 1e5+10;

vector<int>add(vector<int>&A,vector<int>&B)//加上&符号是为了提升效率；如果不加，需要吧整个数组copy一遍
{
    if(A.size()<B.size()) return add(B,A);
    //vector A的第一位是原来string的最后一位啦
    vector<int>C;
    int t=0;
    for(int i=0;i<A.size();i++)//A的位数比B多，A的位数做循环次数，保证所有位循环完
    {
        t += A[i];
        if (i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10
    }
    //这个是判断最后一位的t
    if (t) C.push_back(t);
    return C;
}
int main()
{
    string a,b;
    vector<int>A,B;
    ios::sync_with_stdio(false);
    cin>>a>>b;
    //做大整数加法都是从后面的数字开始加起来
    for(int i=a.size()-1;i>=0;i--)
        A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)
        B.push_back(b[i]-'0');
    auto c =add(A,B);
    for(int i=c.size()-1;i>=0;i--) 
        cout<<c[i];
    cout<<endl;
    return 0;
}