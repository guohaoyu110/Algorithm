class Solution {
public:
    // 如果改成这种可以有重复数字的，在很多edge case需要特殊的考虑！
    int findMin(vector<int>& nums) {
        //和前一道题目的不同之处在于，可能有重复的数字
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid]>nums[r])
                l = mid + 1;
            else if(nums[mid]<nums[r]) 
                r = mid;
            else 
                r--;
        }
        return nums[l];
        
    }
};