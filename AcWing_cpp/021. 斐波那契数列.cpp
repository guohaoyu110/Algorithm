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

//方法二：21ms 这样写的话，快很多！
class Solution {
public:
    int v[100000] = { 0 };

    int Fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n ==2) {
            v[n] = 1;
            return v[n];
        }
        if (v[n] != 0) return v[n];
        for (int i = 3; i <= n; i++) {
            v[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
        }

        return v[n];
    }
};
//方法三：694ms 用for循环，每一步计算出来，速度会快很多
class Solution {
public:
    int v[100000] = { 0 };

    int Fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n ==2) {
            v[n] = 1;
            return v[n];
        }
        //if (v[n] != 0) return v[n]; //这一步还是很重要的
        if (n>=3){
            v[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
        }

        return v[n];
    }
};



