'''
//错误解法
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>sub(vector<int>&A,vector<int>&B)
{
    //if (A.size()<B.size()) return sub(B,A)
    vector<int>C;
    int t=0;
    int flag = 0;
    for(int i=0;i<A.size();i++)
    {
        //int flag = 0;
        t+=A[i] - flag;
        if (i<B.size()){
            if (A[i]>=B[i]) {t =A[i]-B[i]; flag = 0;}
            else{
                t = 10+A[i]-B[i];
                flag = 1;
            } 
            C.push_back(t);
            t/=10;
        }
    }
    return C;
}

int main()
{
    string a,b;
    vector<int>A,B;
    ios::sync_with_stdio(false);
    cin>>a>>b;
    //auto c = sub(A,B);
    auto c;
    if (A.size()>=B.size())  c = sub(A,B);
    else  c = sub(B,A);
    for(int i=c.size()-1;i>=0;i--)
        cout<<c[i];
    cout<<endl;
    
    return 0;
    
}
'''
//主要注意几点：
//1. 数据处理前，去0操作；
//2. 计算结果之后，去0操作。
#include <iostream>
#include <vector>
using namespace std;

const int N = 1000010;

bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size()) return A.size() >= B.size();
    for (int i = A.size() - 1; i >= 0; i--) 
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;
}

void trimZero(vector<int> &A)
{
    while (A.back() == 0 && A.size() > 1) A.pop_back();
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    trimZero(C);

    return C;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B, C;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    trimZero(A), trimZero(B);

    if (cmp(A, B)) C = sub(A, B);
    else {
        C = sub(B, A);
        printf("-");
    }
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

    return 0;
}

