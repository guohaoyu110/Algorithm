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

//第二种方法，时间复杂度和空间复杂度都会更好一些。
class Solution{
public:
    int removeElement(vector<int>& nums, int val)
    {
        //必须原地修改
        int len = 0;
        for(int i =0;i<nums.size();i++)
        {
            //nums[len++] = 
            if (nums[i]!=val)
            {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};