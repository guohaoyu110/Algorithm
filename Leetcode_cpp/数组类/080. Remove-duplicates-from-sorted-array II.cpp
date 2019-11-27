/*
//这种方法空间复杂度超过了！
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
};*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 2;
        if (nums.size()==0)
            return false;
        if (nums.size()==1)
            return nums[0];
        for(int i=2;i<nums.size();i++)
        {
            if (nums[index-2]!=nums[i])
                nums[index++]=nums[i];
        }
        
        return index;
        
    }
};