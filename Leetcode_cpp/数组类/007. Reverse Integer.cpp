//第一个解答是错的，rst*10会溢出
/*
class Solution {
public:
    int reverse(int x) {
         // Write your code here
        int rst = 0;
        
        while(x != 0){
            int next_rst = rst * 10 + x % 10;
            x = x / 10;
            if(next_rst/10 != rst) {
                rst  = 0;
                break;
            }
            rst = next_rst;
        }
        return rst;
    }
};*/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (res < INT_MIN/10) return 0;
            if (res > INT_MAX/10) return 0;
            res *= 10;
            int m = x % 10;
            if (m < 0 && res < INT_MIN - m) return 0;
            if (m > 0 && res > INT_MAX - m) return 0;
            res += m;
            x /= 10;
        }
        return res;
    }
};