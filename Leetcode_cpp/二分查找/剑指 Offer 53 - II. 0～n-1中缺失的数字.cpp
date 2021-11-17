class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 考点就是二分查找
        int left = 0, right = nums.size() -1 ;
        int mid; 
        while (left <= right) {
            // 从零开始的
            mid = (left + right) / 2;
            if (nums[mid] == mid ) {
                left = mid + 1; // 说明前面的都没有问题，可以朝后面遍历
            }
            else {
                right = mid - 1;
            }
        }
        return left == nums.size()-1 && nums[left] == left ? left + 1 : left; 
    }
};