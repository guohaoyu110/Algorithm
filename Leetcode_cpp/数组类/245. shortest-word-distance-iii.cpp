class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1=-1,p2=-1, ans = INT_MAX;
        //如果前面的值需要改变的，保持前面一个可以被改为-1这样，方便初始化。
        for(int i=0;i<words.size();i++)
        {
            if (words[i]==word1)
                p1=i;
            if (words[i]==word2)
            {
                if (word1==word2)
                    p1=p2;
                p2=i;
            }
            if (p1!=-1&&p2!=-1)
                ans=min(ans,abs(p1-p2));
        }
        
        return ans;
        
    }
};