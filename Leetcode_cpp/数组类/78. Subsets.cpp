class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //返回所有的子集
        //permutations那个排列的函数查一下，这个不行
        vector<vector<int>> results;
        vector<int> subset;
        helper(results, subset, nums, 0);
        return results;
        
    }
    
    void helper(vector<vector<int> > &results, vector<int> &subset,
    vector<int> &nums,int start) {
        results.push_back(subset);
        for(int i=start;i<nums.size();i++){
            subset.push_back(nums[i]);
            //helper(results, subset,nums,start+1);
            helper(results, subset, nums,i+1);
            subset.pop_back();
        }
    }
};