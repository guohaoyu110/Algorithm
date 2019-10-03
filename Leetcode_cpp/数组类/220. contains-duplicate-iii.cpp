class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //什么时候用map，查找的时候，有对应关系的时候？
        //最大是这个数字，是不是一个小于等于的关系？
        //根据k来卡吧
        //这种直观思考是循环里套循环的题目通常的解法是什么？
        //是不是直接找到满足绝对值差条件的数字，更加容易找到符合要求的
        //这道题目还是比较难的，可以算hard题目
        int n=nums.size(),j=0;
        map<double,int>record;
        double T=t;
        for(int i=0;i<n;i++)
        {
            double num=nums[i];
            if (i-j>k)
            {
                record.erase(nums[j++]);
            }
            auto find = record.lower_bound(num-T);
            if(find!=record.end()&&abs(find->first-num)<=T)
                return true;
            record[num]=i;
        }
        return false;
        
    }
};

/*
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
{
	set<double> _set;
	for (int i = 0; i < nums.size(); ++i) 
	{
		auto s = _set.lower_bound((double)nums[i] - (double)t);
		if (s != _set.end() && *s <= (double)nums[i] + (double)t) return true;

		_set.insert(nums[i]);
		if (_set.size() > k) _set.erase(nums[i - k]);
	}
	return false;
}

作者：ikaruga
链接：https://leetcode-cn.com/problems/contains-duplicate-iii/solution/220-by-ikaruga/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/