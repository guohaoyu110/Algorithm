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
//这道题目确实是用left right去卡，方便一些。如果是双重循环，后面一个变量查找比较困难。
/*
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    { 
        sort(nums.begin(),nums.end());
        //vector<int>nums1;
        int diff = INT_MAX;
        int min1;
        //三个元素的题目，最经典的思路都是三个变成两个,吧所有位置全部遍历
        if (nums.size()>=3)
        {
        for(int i=0;i<nums.size()-2;i++)
        {
            
            for(int j=i+1;j<nums.size()-1;j++)
            {
                int m = target - nums[i]-nums[j];
                //diff = abs(min(m-,diff),0);
                diff = std::min(abs(m-nums[j+1]),diff);
                if (abs(m-nums[j+1])<diff)
                    min1 =  
                
            }
        }
        }
        
        
    }
};
*/