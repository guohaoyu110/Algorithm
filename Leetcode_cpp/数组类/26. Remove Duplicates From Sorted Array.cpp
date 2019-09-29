/*
//这种方法是基础的，最容易想到的
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>nums1;
        int len = nums.size();
        //nums1[0] = nums[0];
        //if (nums != NULL)
        if(nums.size()==0){
            return 0;
        }
        nums1.push_back(nums[0]);
        for (int i=1;i<len;i++)
        {
            if(nums[i]!=nums[i-1])
                nums1.push_back(nums[i]);
        }
        nums = nums1;
        
        return nums.size();
          
        
    }
};*/

//用C++双指针的方法

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        while(j<nums.size())
        {
            int tmp = nums[j];
            nums[i++] = nums[j++];//是相等过之后+1
            while(j<nums.size() && tmp == nums[j])
                j++;
        }
        return i; 
        
    }
};











