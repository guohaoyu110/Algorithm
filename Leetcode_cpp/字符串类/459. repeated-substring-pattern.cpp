class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n =s.size();
        //是不是可以用其中的一个子串来构成！
        //照这个规律一定是某个数字的倍数！
        //改换思路，不一定要分解成最小的组成部分，这种思路也很好！
        for(int i=n/2;i>=1;--i)
        {
            if (n%i==0)
            {
                int c=n/i; //可能有多少个重复的组合！
                string t = "";
                for(int j=0;j<c;j++)
                    t += s.substr(0,i);//substr复制子字符串
                if (t==s) 
                    return true;
            }
        }
        return false;
            
    }
};