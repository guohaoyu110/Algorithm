//方法一，利用swap库函数
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

//方法二，利用递归的原理去做这道题目,不用现成的库函数，用自己写的递归也非常好！
class Solution {
public:
    void helper(int start,int end, vector<char>&ls)
    {
        if (start>=end) return;
        char tmp = ls[start];
        ls[start] = ls[end];
        ls[end] = tmp;
        helper(start+1,end-1,ls);
        
    }
    void reverseString(vector<char>& s) 
    {
        helper(0,s.size()-1,s);
    }
};