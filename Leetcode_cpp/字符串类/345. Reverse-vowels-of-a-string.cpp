class Solution {
public:
    //算法思路还是指针对撞的思想，比较常见
    bool isVowel(char v)
    {
        return v=='a'||v=='i'||v=='o'||v=='u'||v=='e'||
        v=='A'||v=='I'||v=='O'||v=='U'||v=='E';
    }
    string reverseVowels(string s) {
        int m = s.size();
        for(int i=0, j=m-1; i<j; ++i,--j)
        {
            while(i<j && !isVowel(s[i]))//表示不是元音字母
            {++i;}
            while(i<j && !isVowel(s[j]))
            {--j;}
            swap(s[i],s[j]);
        }
        return s;
        
    }
    
   
};