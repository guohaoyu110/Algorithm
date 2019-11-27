//方法一，错误的，二分法中有重复元素的写法和无重复元素的写法不同，值得注意！
/*class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int first =0,last=nums.size();
        if (nums.size()==0)
            return false;
        if (nums.size()==1&&target ==nums[0])
            return true;
        while(first!=last)
        {
            int mid = (first+last)/2;
            if (nums[mid]==target)
                return true;
            if (nums[first]<=nums[mid])
            {
                if(nums[first]<=target&&target<nums[mid])
                    last = mid;
                else 
                    first = mid+1;
            }
            else
            {
                if(nums[mid]<target&&target<=nums[last])
                    first = mid+1;
                else last = mid;
            }
        }
        
        return false;
        
    }
};*/

//方法二：
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int first =0,last=nums.size();
        if (nums.size()==0)
            return false;
        if (nums.size()==1&&target ==nums[0])
            return true;
        while(first!=last)
        {
            int mid = (first+last)/2;
            if (nums[mid]==target)
                return true;
            if (nums[first]<nums[mid])
            {
                if(nums[first]<=target&&target<nums[mid])
                    last = mid;
                else 
                    first = mid+1;
            }
            else if(nums[first]>nums[mid])
            {
                if(nums[mid]<target&&target<=nums[last-1])
                    first = mid+1;
                else last = mid;
            }
            else first++;
        }
        
        return false;
        
    }
};