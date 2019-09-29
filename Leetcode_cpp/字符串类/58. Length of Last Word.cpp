class Solution {
public:
    int lengthOfLastWord(string s) {
        //返回最后一个单词的长度
        int res = 0;
        for(int i=0;i<s.size();i++)
        {
            //首先要把那个最后是空格的情况排除掉，不能计算在内！
            if (s[i]!=' ')
            {
                if (i!=0 && s[i-1]==' ')
                    res = 1;
                else res++;
            }
        }
        return res;
        
    }
};