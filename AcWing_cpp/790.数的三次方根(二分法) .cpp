#include <iostream>
using namespace std;
int main()
{
    double l=-10000,r=10000;
    double m;
    cin>>m;
    while(r-l>1e-8)
    {
       double mid=(r+l)/2;
       if (mid*mid*mid>=m)
            r=mid;
       else l=mid;
    }
    printf("%lf",l);
    
    
    return 0;
}