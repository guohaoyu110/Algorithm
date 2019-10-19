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