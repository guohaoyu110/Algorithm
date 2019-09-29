class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;//1 1 1 2 2 2 2 
        int i = 1;
        while(i<nums.size())
        {
            if(nums[i]==nums[i-1])
            {
                count++;
                if (count>nums.size()/2)
                    return nums[i];
            }
            else if (nums[i]!=nums[i-1])
            {
                count=1;
            }
            i++;
        }
        return nums[0];
    }
};