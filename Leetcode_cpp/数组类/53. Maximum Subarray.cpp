class Solution {
public:
    //找到一个具有最大和的连续子数组
    int maxSubArray(vector<int>& nums) 
    {
        int ans=0;
        int max=0;
        //这个负数的情况在这个函数里应该怎么处理？
        //if(max(nums)<0)
          //  return std::max(nums);
        int max1=INT_MIN;//应该是数组的范围超过界限了
        for(int i=0;i<nums.size();i++){
            max1 = std::max(max1,nums[i]);
        }
        if (max1<0)
            return max1;
        for(int i=0;i<nums.size();i++)
        {
            ans+=nums[i];
            if (ans<=0)
                ans=0;
            if (ans>max)
                max = ans;  
        }
        return max;
    }
};