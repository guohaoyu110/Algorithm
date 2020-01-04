//这种方法思路是对的，但是到后面出来的结果是错的！
'''
class Solution {
public:
    int climbStairs(int n) {
        long long int F[100];
        //相当于先爬n-2，然后爬两级；还是先爬n-1，然后再爬1级
        F[1] = 1; F[2] = 2;
        for(int i = 3;i<=n;i++){
            F[n] = F[n-1]+F[n-2];
        }
        return F[n];
            
    }
};
'''
class Solution {
public:
    int climbStairs(int n) {
        // write your code here
        if(n <= 2)
            return n;
        int* step = new int[n+1];
        step[1] = 1;
        step[2] = 2; 
        for(int i = 3; i <= n; i++) {
            step[i] = step[i-1] + step[i-2];
        }
        return step[n];
    }
};