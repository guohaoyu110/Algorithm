class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //看有没有公共的字母
        if (strs.empty())
            return "";
        //主要是看前缀，最前面的几个字母
        string res = "";
        //必定要用到双重循环，正常的思路而言
        for(int j=0;j<strs[0].size();j++)
        {
            char c = strs[0][j];
            for(int i=0;i<strs.size();i++)
            {
                if (j>=strs[i].size()|| strs[i][j]!=c)
                    return res;
            }
            res.push_back(c);
        }
        return res;
    }
};