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

//方法二：这种方法更加容易想到一点
'''
解释:
第一行: 0
第二行: 01
第三行: 0110
第四行: 01101001
'''
'''
当 N=1 时，结果是 0。

而如果 N-1 行的第 (K+1)/2 个数字是 0 ，那么产生 01 ，否则产生 10 。

那具体产生的是前面的数字还是后面的数字呢？这就要看原来的 K 了，可以通过求余数操作来判断。

比如要计算第 2 行的第 2 个数，因为第 1 行的第 (2+1)/2=1 个数字是 0，于是结果就为 (2-1)%2=1。
'''
//这种也是递归的思路！
class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        return kthGrammar(N-1, (K+1)/2)==0 ? (K-1)%2 : K%2;
    }
};