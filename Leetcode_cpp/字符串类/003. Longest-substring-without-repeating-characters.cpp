/*
//解法一：
class Solution {
public:
    //经典解法，对每个不同的字母进行计算出现次数
    int lengthOfLongestSubstring(string s) {
        //对string的进行分析，不含有重复字符的字符串
       int m[256]={0},res=0,left=0;
        for(int i=0;i<s.size();i++)
        {
            if (m[s[i]]==0 || m[s[i]]<left)
                res = max(res,i-left+1);
            else 
                left=m[s[i]];
            m[s[i]]=i+1;
        }
        return res;
    }
};
*/
//解法二：
class Solution {
public:
    //经典的滑动窗口的解法
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) 
            return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++)
        {
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;
    }
};















