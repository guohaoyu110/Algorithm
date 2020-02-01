//方法一：最基础的解法

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>nums1;
        //nums1.push_bach()
        int size = nums.size();
        for (int i=0; i<size-1; i++)
        {
            for (int j=i+1;j<size;j++)
            {
                if (nums[i]+nums[j]==target)
                {
                    nums1.push_back(i);
                    nums1.push_back(j);
                    break;
                }  
            }
        }
        return nums1;
    }
};


//方法二：hashmap
//关联容器是对容器概念的一个改进，将值与键关联在一起
//可以降低一重时间复杂度
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int>m;
        vector<int>res;
        for (int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }
        for (int j=0;j<nums.size();j++)
        {
            int t = target- nums[j];
            if (m[t]!=j && m.count(t)){
                res.push_back(j);
                res.push_back(m[t]);
                break;
            }
                
            
        }
        return res;
    }
}; 


// 20190824 update
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();++i){
          if(hash.count(target-nums[i])){
            return vector<int>({hash[target-nums[i]],i});
          }
          hash[nums[i]]=i;
        }
        return vector<int>();
    }
};