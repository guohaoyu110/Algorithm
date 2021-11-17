class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 二分查找的问题
        // 数组是有序排列的
        // int left = 0, right = nums.size()-1; 
        // int mid; 
        if (nums.size() == 0) return {-1, -1};
        vector<int> res ;
        // 分下来找，写两个二分法，一个是找左边界，一个是找右边界
        int num1 = getlowerbound(nums, target); 
        int num2 = gethigherbound(nums, target);
        return {num1, num2};
    }
    int getlowerbound(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        int mid; 
        while(left < right){
            mid = (left + right)/2; 
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else  {
                right = mid; 
            }
            // else {
            //     return left; 
            // }
        }
        // return -1;
        if (nums[left] != target) return -1; 
        return left; 
    }
    int gethigherbound(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        int mid; 
        while (left < right){
            mid = (left + right + 1)/2; 
            if (nums[mid] > target){
                right = mid - 1;
            }
            else {
                left = mid; 
            }
        }
        // return -1;
        if (nums[left] != target) return -1; 
        return left; 
    }
};