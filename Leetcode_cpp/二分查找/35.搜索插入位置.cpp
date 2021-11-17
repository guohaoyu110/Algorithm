class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left)/2;
            if(target == nums[mid]) {
                return mid;
            }
            else if(nums[mid] < target) {
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return left == mid + 1 ? left : mid; 
    }
}

// 这个可以当做模板去用来写