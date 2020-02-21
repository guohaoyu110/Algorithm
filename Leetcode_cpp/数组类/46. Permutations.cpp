//方法一：
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        result.push_back(nums);
        while(std::next_permutation(nums.begin(),nums.end())){
            result.push_back(nums);
        }
        return result;
    }
};

//方法二：


