class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //找到1所在的位置，然后去进行判断
        //重构数组，去构建一个以1为开头的数组
        //this solving idea is not a good case! has to be something 
        vector<int> nums1;
        if (nums.size()==0) return 1;
        if (nums[0]>0) nums1.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>0&&nums[i]!=nums[i-1])
            {
                nums1.push_back(nums[i]);
            }
                
        }
        if (nums1.size()==0)
            return 1;
        if(nums1[0]>1)
            return 1;
        int flag = 0;
        for(int j=1;j<=nums1.size();j++)
        {
            if (nums1[j-1]==j)
            {
                flag++;
                if (flag==nums1.size())
                    return flag+1;
                continue;//要考虑一下continue执行的顺序问题
            }
            else 
                return j;
        }
        return 1;
    }
};
//一定有更好的方法，虽然时间复杂度和方法都达到要求了，但是思路不够清晰明了。
//方法二，自己写的，击败了百分百的用户hh，这种思路还是比较常规的思路，尤其在这道题目的场景下
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=0;
        if (nums.size()<1) return 1;
        
        if (nums[0]>0) j++;
        for(int i=1;i<nums.size();i++)
        {
            if (nums[i]>0&&nums[i]!=nums[i-1])
            {
                nums[j] = nums[i];
                j++;
            }
        }
        for(int j=0;j<nums.size();j++)
        {
           if (j==0&&nums[j]!=1)
            {
                return 1;
            }
            if (j>0&&nums[j]!=nums[j-1]+1)                    
                return nums[j-1]+1;
            //j++; 
        }
        return nums.size()+1;
    }
};