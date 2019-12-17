//典型的二分法解题
class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int l=0,r=size-1;
        while(l<r)
        {
            int mid = l + r >> 1;
            if (nums[mid] > nums[r])   //当mid位置的数字比右侧大时，寻找区间就需要向右移动
                l = mid+1;
            else
                r = mid;
        }
        
        
        return nums[r];
    }
};