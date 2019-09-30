class Solution {
public:
    int firstUniqChar(string s) {
        int m[256]={0};
        
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        for(int j=0;j<s.size();j++)
        {
            if (m[s[j]]==1)
                return j;
        }
        return -1;
    }
};