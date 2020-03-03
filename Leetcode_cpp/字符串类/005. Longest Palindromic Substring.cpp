// c++的方法，中心扩展法，还是有一些测试用例没有通过
// 方法一：
// 这种方法很清晰，测试用例除了最极端的，其他都通过了
// l 和 r找到左端和右端
class Solution {
public:
    bool is_parlindrome(string &s, int l, int r){//判断是否回文
        while(l < r)
            if(s[l] == s[r]) l ++ , r -- ;
            else return false;
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size(); 
        int l = 0, r = 0;
        for(int i = 0; i < n; i ++ )//枚举所有子串
            for(int j = 0; j <= i; j ++ )
                if(is_parlindrome(s, j, i)&& r - l < i - j)
                    l = j, r = i;
        return s.substr(l, r - l + 1);
    }
};



//方法二：暴力解法，测试用例全部通过了
class Solution {
public:
    string longestPalindrome(string s) {
        int res = 0;
        string str;
        for (int i = 0; i < s.size(); i ++ ){
            for (int j = 0; i - j >= 0 && i + j < s.size(); j ++ )
                if (s[i - j] == s[i + j]){
                    if (j * 2 + 1 > res){
                        res = j * 2 + 1;
                        str = s.substr(i - j, j * 2 + 1);
                    }
                }
                else break;

            for (int j = i, k = i + 1; j >= 0 && k < s.size(); j -- , k ++ )
                if (s[j] == s[k]){
                    if (k - j + 1 > res) {
                        res = k - j + 1;
                        str = s.substr(j, k - j + 1);
                    }
                }
                else break;
        }
        return str;
    }
};


/*java 解法，击败了百分之97*/
class Solution {
    public String longestPalindrome(String s) {
        char[] arr = s.toCharArray();
        int len = arr.length, begin = 0, maxLen = 1;
        if (len < 2) return s;
        for (int i = 0; i < len; i++) {
            int l = i - 1, r = i;
            // 跳过相同字符(必回文)
            while (r + 1 < len && arr[r] == arr[r + 1]) r++;
            i = r++; // 下一个i直接从相同字符的下一个开始遍历
            // 中心扩展
            while (l >= 0 && r < len && arr[l] == arr[r]) {
                l--;
                r++;
            }
            // 记录最值
            if (r - l - 1 > maxLen) {
                maxLen = r - l - 1;
                begin = l + 1;
            }
        }
        return s.substring(begin, begin + maxLen);
    }

}










