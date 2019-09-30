class Solution {
public:
    void reverseString(vector<char>& s) {
        //原地修改输入数组，使用O(1)空间
        //应该是用队列吗？
        int i=0,j=s.size()-1;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
        return ;
        
    }
};