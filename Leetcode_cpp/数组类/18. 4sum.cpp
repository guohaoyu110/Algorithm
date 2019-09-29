class Solution {
public:
    //肯定要剪枝，最常规的方法，还是要三重循环
    //最常见的解法还是双指针的方法
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        //vector内部有一个机制，如果你返回的是不达标的结果；构造的起初默认就是0，不用刻意的返回0
        vector<vector<int>>result;
        set<vector<int>>res;
        sort(nums.begin(),nums.end());
        if (nums.size()<4)
            return result;
        for(int i=0;i<nums.size()-3;i++)
        {
            for(int j=i+1;j<nums.size()-2;j++)
            {
                //if (j>i+1 && nums[j]==nums[j-1])
                  //  continue;
                int left = j+1, right = nums.size()-1;
                while(left<right)
                {
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if (sum==target)
                    {
                        vector<int>out{nums[i],nums[j],nums[left],nums[right]};
                        res.insert(out);
                        left++;right--;
                    }
                    else if (sum<target)
                        left++;
                    else right--;
                }
            }
            
        }
        //return res;
        return vector<vector<int>>(res.begin(),res.end());
    }
};