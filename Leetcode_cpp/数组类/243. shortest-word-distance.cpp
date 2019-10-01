class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        //得到这几个字符串的所在的几个数组标号
        //这种一个数组里面出现几个相同的字符串的情况怎么处理呢？
        //map只能是一对一的，这个如果写一个对应关系是一对多了
        //看答案了，这个思路还是很清晰的
        int p1=-1,p2=-1, ans = INT_MAX;
        for(int i=0;i<words.size();i++)
        {
            if (words[i]==word1)
                p1=i;
            else if (words[i]==word2)
                p2=i;
            if (p1!=-1&&p2!=-1)
                ans=min(ans,abs(p1-p2));
        }
        
        return ans;
    }
};