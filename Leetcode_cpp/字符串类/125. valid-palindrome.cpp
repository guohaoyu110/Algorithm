class Solution {
public:
    //利用了快排的思想
    //两个指针从后和前两边夹击
    bool isPalindrome(string s) {
        if(s.length()==0)
            return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);//very important!
        int start=0;
        int end=s.length()-1;
        while(start<end){
            while(start<end&&!IsCharOrNumber(s[start]))
                start++;
            while(start<end&&!IsCharOrNumber(s[end]))
                end--;
            if(start<end && s[start]!= s[end])
                return false;
            start++;
            end--;
                
        }
        return true;
    }
    bool IsCharOrNumber(char s){
        if((s>='a'&&s<='z')||(s>='0'&&s<='9'))
            return true;
        return false;
    }

};