//方法一：
class Solution {
public:
    int kthGrammar(int N, int K) {
        int n;
        for (n = 0, K -= 1; K ; K &= (K - 1)){  //求解K-1的二进制中1的个数
            n++;
        }
        return n & 1;
    }
};

//方法二：

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        return kthGrammar(N-1, (K+1)/2)==0 ? (K-1)%2 : K%2;
    }
};