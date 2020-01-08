class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //用map来做，对每个数出现的次数进行一个统计
        unordered_map<int,int>m;

        for(int i =0;i<nums.size();i++){
            m[nums[i]] = i;
        }
        int t = 
    }
};


//方法二，用先排序，然后再用双指针的方法去做
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        for(int i =0,j=1;j<nums.size();i+=2,j+=2)
        {
            if (nums[i]!=nums[j]) return nums[i];
        }
        return nums[nums.size()-1];
    }
};