//方法一：
class Solution {
public:
    int Fibonacci(int n) {
        int a = 0, b =1;
        int c;
        while(n--){
            c = a+c;
            a = b; b = c;
        }
        return a;
    }
};

//方法二：
