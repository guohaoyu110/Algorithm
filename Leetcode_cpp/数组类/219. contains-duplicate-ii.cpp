class Solution {
public:
    //正常循环判断解法显示堆栈溢出，这是为什么呢？
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(nums[i]) && i-m[nums[i]]<=k)
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};