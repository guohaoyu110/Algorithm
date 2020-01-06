//判断有多少个质数
class Solution {
public:
    bool isPrime(int num){
        if (num<=1) return false;
        for(int i = 2;i*i<=num;i++){
            if (num % i == 0) return false;
        }
        return true;
    }
    
    int countPrimes(int n) {
        int count = 0;
        for(int i = 1;i<n;i++){
            if (isPrime(i)) count++;
        }
        return count;
    }
};