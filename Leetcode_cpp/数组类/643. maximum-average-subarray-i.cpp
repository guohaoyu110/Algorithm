//用的方法时间复杂度太大了，比较复杂的数超出时间限制了
/*class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //平均数最大并且长度为k的连续子数组
        int max = INT_MIN;
        //int sum =;
        for(int i=0;i<nums.size()-k+1;i++)
        {
            int sum =0;
            for(int j=0;j<k;j++)
            {
                sum += nums[i+j];
            }
            max = std::max(max,sum);
        }
        return (double)max/k;
        
    }
};*/
//想方设法降低时间复杂度
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //平均数最大并且长度为k的连续子数组
        double sum=0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        double max = sum;
        for(int i=k;i<nums.size();i++)
        {
            sum = sum + nums[i] - nums[i-k];
            max = std::max(max,sum);
        }
        return (double)(max/k); 
    }
};