//暴力计算的方法肯定是超时的！
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>m;
        unordered_map<int,int> p;
        //至少要一重循环的
        //vector<int>nums1=sort(nums);
        sort(nums.begin(),nums.end());
        if (nums.size()>=3){
            for (int i=0;i<nums.size();i++)
            {
                p[nums[i]]=i;
            }
        
            for (int i=0;i<nums.size()-2;i++)
            {
                if (i>0 && nums[i] == nums[i - 1]) 
                    continue;        
                p[nums[i]]=i;
                vector<int>res;
                //这个前后可能有重复的，我怎么判断呢？
                for(int j=i+1;j<nums.size()-1;j++)
                {
                    p[nums[j]]=j;
                    int t = -nums[i]-nums[j];
                //因为有两个-1，这个判断时候优先判断的是前面的一个
                //if(p[t]<j) 
                    if (p.count(t) && p[t]>i && p[t]>j)
                    {
                        res.push_back(nums[i]);res.push_back(nums[j]);res.push_back(t);
                    //break;
                        m.push_back(res);
                        res.clear();
                    }
                 //m.push_back(res);
                }
            }
        }
        return m;
    }
};
//1.将数组排序 2.定义三个指针，i，j，k。遍历i，那么这个问题就可以转化为在i之后的数组中寻找nums[j]+nums[k]=-nums[i]这个问题，也就将三数之和问题转变为二数之和---（可以使用双指针）
