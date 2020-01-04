//思路是对的，大部分的测试用例也是对的，但是对于极端的进度情况不能通过
class Solution {
public:
    double myPow(double x, int n) {
        //这个是用递归的方法吗，还是数位的方法？
        if(n == 0) return 1.0;
        if (n>0){
            return x*myPow(x,--n);;
        }
        int N = -1 * n;
        if (n<0){
            double y = x*myPow(x,--N);
            return 1.0/y;
        }
        return 0.0;
    }
};


//正确解答
//还是用递归的方法来处理这道题目；这个是递归快速幂的方法
//直接用n/2的方法，对降低时间复杂度很好！
class Solution {
public:
    double fastPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } 
        else {
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
};