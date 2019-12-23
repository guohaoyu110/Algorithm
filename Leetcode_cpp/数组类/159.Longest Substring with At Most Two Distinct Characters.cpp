//典型的hashmap + 双指针的题目，和ACWing的题目交叉起来看。
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        //用hash map或者双指针来做这道题目
        int res =0;
        unordered_map<char,int>hash;//用这个来代表出现的次数
        for (int i=0,j=0,d=0;i<s.size();i++)
        {
            if (!hash[s[i]]) d++;
            hash[s[i]]++;
            while(j<i&&d > 2)
            {
                hash[s[j]]--;
                if (!hash[s[j]]) d--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};