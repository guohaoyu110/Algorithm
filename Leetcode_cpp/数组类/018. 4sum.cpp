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

//写一种更通用的方法，便于联系起来理解，和3sum的方法本质上是一样的
//思路还是很清晰的，最重要的还是关注临界条件！！！
class Solution {
public:
    //肯定要剪枝，最常规的方法，还是要三重循环
    //最常见的解法还是双指针的方法
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>result;
        vector<int>res;
        sort(nums.begin(),nums.end());
        if (nums.size()<4)
            return result;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i;
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if (j>i+1 && nums[j]==nums[j-1])
                    continue;
                for(int k=j+1;k<nums.size()-1;k++)
                {
                    if (k>j+1&&nums[k]==nums[k-1]) continue;
                    int p = target - nums[i] - nums[j] - nums[k];
                    if (m.count(p)&&j>i&&k>j&&m[p]>k&&m[p]>i&&m[p]>j)
                    {
                        res.push_back(nums[i]);res.push_back(nums[j]);res.push_back(nums[k]);
                        res.push_back(p);
                        result.push_back(res);
                        res.clear();
                    }
                }
            }
            
        }
        return result;
    }
};
