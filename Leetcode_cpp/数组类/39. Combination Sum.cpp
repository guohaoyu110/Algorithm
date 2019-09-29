class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //看有多少种组合，可以组成target这种数字
        //感觉这个题目类似贪心算法
        //在一个函数中完成递归，然后去遍历
        vector<vector<int>>res;
        vector<int>out;
        sort(candidates.begin(),candidates.end());
        if (target < 0 ) 
            return res;
        for(int i=0;i<candidates.size();i++)
        {
            if (candidates[i]>target) break;
            if (candidates[i]==target) 
            {
                res.push_back({candidates[i]});//花括号相当于包括在一个数组里面
                break;
            }
            //especially important
            vector<int>vec = vector<int>(candidates.begin()+i,candidates.end());
            vector<vector<int>>tmp= combinationSum(vec,target-candidates[i]);
            //waht does this mean?
            for(auto a:tmp)
            {
                a.insert(a.begin(),candidates[i]);
                res.push_back(a);
            }
            
        }
         return res;   
    }
};
//方法二：
