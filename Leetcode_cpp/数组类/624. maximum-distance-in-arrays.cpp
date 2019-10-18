//wrong solution
/*
class Solution {
public:
    //这个题目有一个坑，就是每个子数组只能选一个数作为比较
    int maxDistance(vector<vector<int>>& arrays) {
        //数组列表中的最大距离
        //就是找所有的数组中的最大值和最小值
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0;i<arrays.size();i++)
        {
            for(int j=0;j<arrays[i].size();j++)
            {
                min = std::min(min,arrays[i][j]);
                max = std::max(max,arrays[i][j]);
            }
        }
        int result = max-min;
        return result;
        
    }
};
*/

