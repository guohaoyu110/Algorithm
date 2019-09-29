class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        
        sort(nums.begin(),nums.end());
        vector<int>nums1;
        //三个元素的题目，最经典的思路都是三个变成两个,吧所有位置全部遍历
        int closest = nums[0]+nums[1]+nums[2];
        int diff = abs(closest - target);
        for(int i=0;i<nums.size()-2;i++)
        {
            int left = i+1,right = nums.size()-1;
            while(left<right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                int newDiff = abs(sum-target);
                if (diff>newDiff)
                {
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target) left++;
                else right--;
            }
        }
       return closest;
    }
};