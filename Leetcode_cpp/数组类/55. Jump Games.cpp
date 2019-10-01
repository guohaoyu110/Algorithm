class Solution {
public:
    bool canJump(vector<int>& nums) {
        //这个肯定是要动态规划做吧，因为前一步的操作取决于后面的操作
        //看了九章的答案，居然不要动态规划
        //这个方法虽然简洁，但是比较trick，有点找规律，不是面试的时候能直接想到的！
        int tmpMax = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if (i>tmpMax) return false;
            if (tmpMax<i+nums[i])
                tmpMax=i+nums[i];
            
        }
        
        return true;
    }
};