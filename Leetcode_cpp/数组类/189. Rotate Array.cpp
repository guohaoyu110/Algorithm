/*//方法有问题，看看别人的解法，总结下int和vector<int>的用法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //向右移动k个位置，相当于最后k个调到最前面
        int size = nums.size();
        //vector<int>nums1;
        int nums1[10000];
        for(int i=0;i<size;i++)
        {
            if (i+k<size)
                nums1[i+k]=nums[i];
            else if (i+k>=size)
            {
                nums1[i+k-size]=nums[i];
            }
        }
        //nums=nums1;
        for(int j=0;j<size;j++)
        {
            nums[j]=nums1[j];
        }
    }
};*/

//空间复杂度是O(1)是什么操作？？
class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: rotate the array to the right by k steps
     */
    vector<int> rotate(vector<int> &nums, int k) {
        // Write your code here
        if(k == 0 ||nums.size() < 2) return nums;
        
        k = k%nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
        return nums;
    }
};

