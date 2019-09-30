class Solution {
public:
    string addStrings(string num1, string num2) {
        int m=num1.size(), n=num2.size();
        string res = "";
        int i=m-1,j=n-1,carry=0;
        while(i>=0||j>=0)
        {
            int a = i>=0 ? num1[i--]-'0':0;
            int b = j>=0 ? num2[j--]-'0':0;
            int sum = a + b + carry;
            res.insert(res.begin(),sum%10+'0');
            carry = sum/10;
                
        }
        return carry? '1'+res:res;//双引号和单引号都可以，都是表示字符串
        
    }
};