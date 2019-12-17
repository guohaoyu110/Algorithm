//这种方法是清晰明了的，但是没有达到时间复杂度！
class Solution {
private:
    int nums[100001];
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //先用归并的那种办法把两个数组拼起来，然后用二分法去判断中间的一个数是多少呢
        //vector<int>nums;
        int n_size = nums1.size()+nums2.size();
        int m=nums1.size();int n=nums2.size();
        int k=0,i=0,j=0;
        while(i<m && j<n)
        {
            if (nums1[i]<nums2[j]) nums[k++] = nums1[i++];
            else nums[k++] = nums2[j++];
        }
        while(i<m)  nums[k++] = nums1[i++];
        while(j<n)  nums[k++] = nums2[j++];
        //到这里就得到了新的nums数组，是把这个两个数组排列到一起的
        if(n_size%2==1)
            return (double)nums[(n_size-1)/2];
        else
            return (double)(nums[n_size/2]+nums[n_size/2-1])/2;       
        
    }
};