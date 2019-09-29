class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        vector<int>nums1;
        if (nums.size()==0)
            return;
        vector<int>w = {0,1,2};
        int count0=0;
        int count1=0;
        int count2=0;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]==0)
                count0++;
            else if (nums[i]==1)
                count1++;
            else if (nums[i]==2)
                count2++;
        }
        for (int i=0;i<count0;i++)
            nums1.push_back(w[0]);
        for (int i=0;i<count1;i++)
            nums1.push_back(w[1]);
        for (int i=0;i<count2;i++)
            nums1.push_back(w[2]);
        nums = nums1;
        return ;
        
    }
};