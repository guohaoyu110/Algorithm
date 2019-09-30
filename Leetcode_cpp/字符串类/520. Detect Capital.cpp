class Solution {
public:
    bool detectCapitalUse(string word) {
        //判断单词的大写使用是否正确
        int count1=0;
        int count2=0;
        int count3=0;
        for(int i=0;i<word.size();i++)
        {
            if (word[i]>='A'&&word[i]<='Z')
            {
                count1++;
                if (word[1]>='a'&&word[1]<='z')
                    break;
            }
            if (count1==word.size())
                return true;
            if (word[i]>='a'&&word[i]<='z')
                count2++;
            if (count2==word.size())
                return true;
            //if (word[0]>='A'&&word[0]<='Z')
        }
        for(int i=1;i<word.size();i++)
        {
            if (word[i]>='a'&&word[i]<='z')
                count3++;
            if (count3==word.size()-1)
                return true;
        }
        return false;
        
    }
};