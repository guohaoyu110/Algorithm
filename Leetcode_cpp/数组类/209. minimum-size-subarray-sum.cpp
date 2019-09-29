/*
//这种方法根本就不行，题目要求是连续的子数组，重新sort之后就不符合要求了
class Solution {
public:
    // 有几个测试点一直过不了，不知道为什么了!
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int sum = 0;
        //max = std::max(max,std::min(height[i],height[j]) * (j - i));
        //nums.std::sort();
        std::sort(nums.begin(),nums.end());//直接先sort一下是完全可行的
        int len = nums.size()-1;
        for (int i=len;i>=0;i--)
        {
            sum +=nums[i];
            if (sum>=s)
                return len-i+1;
            else 
                continue;
        
            
        }
        return 0;
    }
};*/

//这种解法非常好！！
//要在连续的数组里面
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start=-1, minlength=nums.size()+1, sum=0;
        for (int i=0;i<nums.size();i++) {
            sum+=nums[i];
            while (sum >= s) {
                minlength=min(minlength, i-start);
                start++;
                sum-=nums[start];               
            }
        }
        return minlength == nums.size()+1 ? 0 : minlength;
    }
};
/*
//这种解法也可以，比较容易理解！！
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int min = n + 1;
        
        for (int start = 0, end = 0; start < n && end < n;)
        {
            while (sum < s && end < n)
                sum += nums[end++];
                
            while (sum >= s && start < n)
            {
                if (min > (end - start))
                    min = end - start;
                
                sum -= nums[start++];
            }
        }
        
        if (min == (n + 1))
            return 0;
        
        return min;
    }
};*/