/*class Solution {
public:
    int countSegments(string s) {
        //根据空格和逗号这些来分割
        int res=0, n =s.size();
        for (int i=0;i<n;i++)
        {
            if (s[i]==' ')
                continue;
            ++res;
            while(i<n && s[i]!=' ')
                i++;
        }
        //用两个循环，每个单词内部还有一个循环，从而方便计算中间有多少个空格
        return res;
    }
};*/
class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for(int i=0;i<s.size();i++)
        {
            if (s[i]!=' '&& (i==0||s[i-1]==' '))
                res++;
        }
        return res;
    }
    
};