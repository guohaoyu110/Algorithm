//第一种方法，非常基础，和two sum的一样
class Solution {
public:
    //关键是要求达到这个时间复杂度，我应该怎么做？
    int search(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]] = i;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(m.count(target))
                return m[target];
            else 
                return -1;
        }
        return -1;
    }
};
//第二种方法，考虑如何达到要求的时间复杂度
