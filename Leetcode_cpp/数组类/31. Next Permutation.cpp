class Solution {
public:
    //这道题目对思维和技巧的要求是比较高的，repeat it！
    void nextPermutation(vector<int>& nums) {
        //每次写题目，先从复杂度最大的写起，保证写出来就行
        //int i,j,n = nums.size();
        int n = nums.size(), i = n - 2, j = n - 1;
        while(i>=0 && nums[i]>=nums[i+1])
            i--;
        if (i>=0)
        {
            while(nums[j]<=nums[i])
                j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};