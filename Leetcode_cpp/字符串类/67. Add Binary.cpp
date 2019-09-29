class Solution {
public:
    string addBinary(string a, string b) {
        //对字符串进行分解
        string res = "";
        //stack<char>p1;
        int m =a.size()-1,n=b.size()-1,carry=0;
        //两个字符串之间的比较不要用两个for循环，这种形式更加正常一点
        while(m>=0||n>=0)
        {
            int p = m>=0?a[m--]-'0':0;
            int q = n>=0?b[n--]-'0':0;
            int sum = p+q+carry;
            //p1.push(to_string(sum));
            res = to_string(sum%2)+res;
            //这种形式相当于把字符串结合起来
            carry = sum/2;
        }
        //return p1;
        return carry == 1?"1"+res:res;//就是看最后一个数字是多少，进行处理
    }
};