class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), begin = 0, maxLen = 1;
        if (len == 1) return s;
        for(int i =0;i<len;i++){
            int l = i - 1, r = i;
            while (r + 1 < len && s[r] == s[r + 1]) 
                r++;
            i = r++; // 下一个i直接从相同字符的下一个开始遍历
            // 中心扩展
            while (l >= 0 && r < len && s[l] == s[r]) {
                l--;
                r++;
            }
            // 记录最值
            if (r - l - 1 > maxLen) {
                maxLen = r - l - 1;
                begin = l + 1;
            }
        }
        return s.substr(begin,begin+maxLen);
    }
};














