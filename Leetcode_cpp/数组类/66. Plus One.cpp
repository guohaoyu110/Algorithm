/*class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //先将数组类型转化为数字类型，然后把数字类型转为数组类型
        //有没有其他方法吧
        int vec=0;
        int digit_size = digits.size()-1;
        for(int i=digit_size;i>=0;i--)
        {
            vec+=digits[i]*pow(10,digit_size-i);
        }
        vec = vec +1;
        int flag = 0;
        int temp1 = vec;
        while(temp1>10)
	    {
		    temp1=temp1/10;
		    flag++;
	    }
        
        
        vector<int>digits1;
        for (int j=0;j<=flag;j++)
        {
            digits1.push_back(vec/pow(10,flag-j));
            //vec = vec - 
            //vec = vec - (vec/pow(10,flag-j))*pow(10,flag-j);
        }
        return digits1;
    }
};*/
//可不可以写的简结一点，这样实在是太麻烦了！！

class Solution {
public:
    //这种写法还是比较训练思维的
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1 ; i >= 0; i--){
            int tmp = (digits[i] + carry) % 10;//得到每个数字位应该是什么数字
            carry = (digits[i] + carry)/10;
            digits[i] = tmp;
            if(carry == 0)//因为这样，前面就不要动了，可以节省运行时间
               break;
        }
        //carry = (digits[0]+carry) % 10;
        //这是判断最前面一个数字的情况
        if(carry != 0)
            digits.insert(digits.begin(),1);  
        return digits;
        
    }
};










