//方法一：
//一个从最高位，一个从最低位，两个夹击，相等的时候就一样了
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x && x % 10 == 0) return false;
        
        int s =0;
        while(s<=x){
            s = s*10 + x%10;
            if (s == x || s == x / 10) return true;
            x /= 10;
        }
        return false;
    }
};

//方法二：用int转string的方法来做
//这个方法对库函数的依赖更大一点，写的更快，不过第一种方法是一定要理解的！
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        string y = to_string(x);
        string s1= y;
        reverse(s1.begin(),s1.end());
        if (y == s1) return true;
        else return false;
        
    }
};