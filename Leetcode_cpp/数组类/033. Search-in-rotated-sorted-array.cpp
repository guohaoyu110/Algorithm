//用二分法的题目关键是找到上下的边界！

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
//第二种方法，考虑如何达到要求的时间复杂度
//这个复杂度要求，很明显要用二分法
//不能同时做i++，j--;容易出问题


//能写else if一定要写else if，不要全是if，降低时间复杂度
class Solution{
public:
    int search(vector<int>& nums, int target)
    {
        
        int i=0,j=nums.size()-1;
        if (nums.size()==0) return -1;
        if (nums.size()==1&&target == nums[0])
            return 0;
        if (nums.size()>=2){
        while(i<j)
        {
            if(target < nums[i] && target < nums[j])
            {
                //i++;
                j--;
            }
            else if (target == nums[i])
                return i;
            else if (target == nums[j])
                return j;
            else if (target > nums[i] && target > nums[j])
            {
                i++;//j--;
            }
            else if (target > nums[i]&& target < nums[j])
                i++;
            else if (target < nums[i]&& target > nums[j])
                j--;
         
        }
        }
        return -1;
    }
};
//第三种方法,这种方法思路清晰，而且速度是最快的！
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first=0,last=nums.size();
        if (nums.size()==0)
            return -1;
        if (nums.size()==1&&target == nums[0])
            return 0;
        while(first!=last)
        {
            int mid=(first+last)/2;
            if(nums[mid]==target)
                return mid;
            if (nums[first]<=nums[mid])
            {
                if (nums[first]<=target && target<nums[mid])
                    last = mid;
                else 
                    first = mid +1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[last-1])
                    first = mid + 1; 
                else last = mid;
            }
            
        }
        return -1;
    }
};



