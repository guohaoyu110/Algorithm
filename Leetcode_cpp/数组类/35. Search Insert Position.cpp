//方法一
//最基础和容易想到的解法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            if(target==nums[i])
                return i;
            else if (target<nums[i])
                return i;
            //else 
               // return nums.size();
            else if (target>nums[nums.size()-1])
                return nums.size();
        }
        return 0;
    }
};
//方法二：
class Solution {
public:
    //二分法的high最好比最后一个数值位数大一个
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        int mid;
        while(low<high)
        {
            mid = low+(high-low)/2;
            if (nums[mid]>target)
                high = mid;
            else if (nums[mid]<target)
                low = mid + 1;
            else
                return mid;
        }
        return low;
    }
};








