class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i1 = m - 1, i2 = n - 1;
	  while(i1 >= 0 && i2 >= 0) 
      {
		if(nums1[i1] > nums2[i2]) {
			nums1[i1 + i2 + 1] = nums1[i1];
			i1--;
		}
		else 
        {    
			nums1[i1 + i2 + 1] = nums2[i2];
			i2--;
		}
	 }
        //如果是i1的话，多下来的话，直接用，位置不变
	while(i2 >= 0) {
		nums1[i1 + i2 + 1] = nums2[i2];
		i2--;
	}
        
        
    }
};


/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int j = 0;
        nums1.erase(nums1.end()-n,nums1.end());
        for(int i = 0; i < n; ++i)
        {
            while(j!=m+1)
            {
                if(nums1[j]>=nums2[i])
                {
                    nums1.insert(nums1.begin()+j,nums2[i]);
                    ++j;
                    ++m;
                    break;
                }
                ++j;
            }
            if(j==m+1)
            {
                nums1.push_back(nums2[i]);
            }
        }
    }
};
*/