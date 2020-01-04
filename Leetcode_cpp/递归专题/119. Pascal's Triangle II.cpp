//方法一，这个方法是对的，但是用到了递归，到了第9个以后的数字，就超时了！
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>p;
        //具体到第几行，输出这一行上的数字的数组
        //rowIndex是从第0行开始往后计算的
        if (rowIndex == 0) {p.push_back(1);return p;}
        if (rowIndex == 1) {p.push_back(1);p.push_back(1); return p;}
        p.push_back(1);
        for(int i = 1;i<rowIndex;i++){
            p.push_back(getRow(rowIndex-1)[i-1] + getRow(rowIndex-1)[i]);
        }
        p.push_back(1);
        return p;
    }
};

//方法二，
