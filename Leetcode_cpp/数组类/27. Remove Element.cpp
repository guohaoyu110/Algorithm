class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>nums1;
        int len = nums.size();
        for(int i=0;i<len;i++){
            if (nums[i]!=val)
                nums1.push_back(nums[i]);
        }
        nums = nums1;
        return nums1.size();
    }
};