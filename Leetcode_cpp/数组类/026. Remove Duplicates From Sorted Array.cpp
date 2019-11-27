/*
为什么return的是int值，最后得到的确是一个数组？
—// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

*/
/*
//这种方法是基础的，最容易想到的
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>nums1;
        int len = nums.size();
        //nums1[0] = nums[0];
        //if (nums != NULL)
        if(nums.size()==0){
            return 0;
        }
        nums1.push_back(nums[0]);
        for (int i=1;i<len;i++)
        {
            if(nums[i]!=nums[i-1])
                nums1.push_back(nums[i]);
        }
        nums = nums1;
        
        return nums.size();
          
        
    }
};*/

//用C++双指针的方法

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        while(j<nums.size())
        {
            int tmp = nums[j];
            nums[i++] = nums[j++];//是相等过之后+1
            while(j<nums.size() && tmp == nums[j])
                j++;
        }
        return i; 
        
    }
};

//方法二：时间复杂度更低一些，达到了题目的时间复杂度的要求
class Solution{
  public:
    int removeDuplicates(vector<int>& nums){
        int i=0,j=0;
        if (nums.size()==0)
            return 0;
        int len = 0;
        for(i=1;i<nums.size();i++)
        {
            if (nums[len]!=nums[i])
                nums[++len] = nums[i];
        }
        return len+1;
        //return i;
    }
};



















