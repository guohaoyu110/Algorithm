class Solution {
public:
    //这个是对称的一个结构，很适合用堆栈的方法去做！
    bool isValid(string s) {
        if (s.empty())
            return true;
        stack<char>p;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                p.push(s[i]);
            }
            else {
                if (p.empty()) return false;
                if (s[i]==')'&&p.top()!='(')
                    return false;
                if (s[i]==']'&&p.top()!='[')
                    return false;
                if (s[i]=='}'&&p.top()!='{')
                    return false;
                p.pop();
            }
        }
        return p.empty();
        
        //return false;
    }
};