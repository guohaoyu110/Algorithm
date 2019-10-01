//这道题目改了太多次，说明思路不清晰
//最后还是看了答案，这种方法还是暴力的算法，思考下更好得奖解法
//卡住一个特别的条件，不能每次都是大于，这样条件太宽泛了。
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size= nums.size();
        //是不是用map来做统计好一些---no
        vector<int>resV;
        int rescount=0;
        if (nums.size()==0) return resV;
        sort(nums.begin(),nums.end());
        int res_sign = size/3;
        //int count=1;
        int res=nums[0];
        for(int i=0;i<size;i++)
        {
            if (res==nums[i])
            {
                ++rescount;
                if (rescount-res_sign==1)//卡住一个特别的条件，不能每次都是大于，这样条件太宽泛了
                    resV.push_back(res);
            }
            else {
                rescount=1;
                res=nums[i];
                if (rescount-res_sign==1)
                    resV.push_back(res);
            }
        }
        return resV;
        
    }
};