class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size()==0)
            return 0;
        if (nums.size()==1)
            return 1;
        vector<int>nums1;
        //nums1[0]=nums[0];
        //nums1[1]=nums[1];
        nums1.push_back(nums[0]);
        nums1.push_back(nums[1]);
        for (int i=2;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-2])
                nums1.push_back(nums[i]);
                
        }
        nums = nums1;
        return nums.size();
    }
};