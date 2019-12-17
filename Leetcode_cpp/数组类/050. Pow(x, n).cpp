//最后的边界超出时间限制了！
class Solution {
private:
    //要注意区分正数和负数，分别进行计算
    double _myPow(double x, long long n) 
    {
        double res = 1.0;
        for(double i = x;n!=0;n--)
            res *=i;
        return res;
    }
public:
    double myPow(double x, int n) 
    {
       return n < 0 ? 1.0 / _myPow(x, -n) : _myPow(x, n);
   
    }
};

//这种解法通过了所有的例子
class Solution {
private:
    //要注意区分正数和负数，分别进行计算
    double _myPow(double x, long long n) 
    {
        double res = 1.0;
        for(double i = x;n!=0;n/=2,i*=i)
            if (n%2)
                res *=i;
        return res;
    }
public:
    double myPow(double x, long long n) 
    {
       return n < 0 ? 1.0/_myPow(x, -n) : _myPow(x, n);
        
    }
};