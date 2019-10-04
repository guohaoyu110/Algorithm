/*class Solution {
public:
    int jump(vector<int>& nums) {
        //每个动作是基于前面变化的，是不是应该用动态规划？
        //和55那道题目对应起来去看
        //使用最少的跳跃次数到达数组的最后一个位置
        int max=0;
        int jump = nums[0];
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if (nums[i]+i>=nums.size()-1)
            {
                count++;
                return count;
            }            
            
            jump = max(nums[i],1);
        }
        
        return count;
    }
};
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int minstep =0;
        int ldist=0;
        int hdist=0;
        if (n==1) return 0;
        //这种循环里的循环又不是无限循环的，直接两个循环就解决问题了，正常外面是while循环的节省空间
        while(ldist<=hdist)
        {
            ++minstep;
            int lastdist = hdist;
            for(int i=ldist;i<=lastdist;i++)
            {
                int possibledist=i+nums[i];
                if (possibledist>=n-1)
                    return minstep;
                if (possibledist>hdist)
                    hdist = possibledist;
                
            }
            ldist = lastdist + 1;
        }
        return 0;
    }
};