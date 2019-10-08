class Solution {
public:
    //这道题目对思维和技巧的要求是比较高的，repeat it！
    void nextPermutation(vector<int>& nums) {
        //每次写题目，先从复杂度最大的写起，保证写出来就行
        //int i,j,n = nums.size();
        int n = nums.size(), i = n - 2, j = n - 1;
        while(i>=0 && nums[i]>=nums[i+1])
            i--;
        if (i>=0)
        {
            while(nums[j]<=nums[i])
                j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};


//方法二：
class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        int i = nums.size() - 2;  
        while (i >= 0 && nums[i] >= nums[i + 1]) {  
            i--;  
        }  
        if (i < 0) {  
            reverse(nums.begin(), nums.end() - 1);  
        }  
        else {  
            int j = i + 2;  
            while (j < nums.size() && nums[j] > nums[i]) {  
                j++;  
            }  
            j--;  
              
            nums[i] ^= nums[j];  
            nums[j] ^= nums[i];  
            nums[i] ^= nums[j];  
              
            reverse(nums.begin() + i + 1, nums.end() - 1);  
        }  
        return nums;
    }
    private:  
    void reverse(vector<int>::iterator i1, vector<int>::iterator i2) {  
        while (i1 < i2) {  
            *i1 ^= *i2;  
            *i2 ^= *i1;  
            *i1 ^= *i2;  
       
            i1++;  
            i2--;  
        }  
    }
};

//方法三：这样写更好一些
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int mid = l + (r - l >> 2); 
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[r]) // 右半边有序
            {
                if (nums[mid] < target && nums[r] >= target) l = mid + 1;
                else r = mid - 1;
            }
          
            else// 左半边有序
            {
                if (nums[l] <= target && nums[mid] > target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
};