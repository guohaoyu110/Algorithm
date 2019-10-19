class Solution {
public:
    //这个时间复杂度只有O(n)
    //使用while循环，一定要找准那个让循环增加或者减少的那个点，非常重要。
    //using namespace std;
    int maxArea(vector<int>& height)
    {
        int max = 0, i = 0, j = height.size() - 1;
        while (i < j)
        {
            max = std::max(max,std::min(height[i],height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return max;
    
    }
        
};
//这种方法复杂度太大了，尽管结果通过了，能不暴力写就不要这样写
/*
    int maxArea(vector<int>& height) 
    {
        int sum = 0;int sum1,sum2;
        for (int i=0;i<height.size();i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
                sum1 = (j-i)*height[i];
                sum2 = (j-i)*height[j];
                if (height[j]>=height[i]&&sum1>=sum)
                    sum = sum1;
                else if (height[j]<height[i])
                {
                    if (sum2>sum)
                        sum = sum2;
                }
            
            }
            
        }
        return sum;
    }*/
