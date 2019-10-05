/*class Solution {
public:
    int maxProfit(vector<int>& nums) {
        //最多可以完成两笔交易
        int min = 0;
        int target=nums[0];
        //如何得到一开始增长的那个数字
        for(int i=1;i<nums.size();i++)
        {
            if (nums[i]>=nums[i-1])
            {
                if (i!=nums.size()-1)
                {
                    target=std::min(target,nums[i]);
                    i++;
                }                
                else
                {min += nums[i]-target; return min;}
            }
            else 
                min+=nums[i-1]-target;
            
        }
        
        return min;
    }
};*/
//自己写错了，还是看答案吧
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        vector<int> profit(prices.size());
        int buy = 0;
        buy = prices[0];
        profit[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit[i] = max(profit[i - 1], prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        
        int sell = prices[prices.size() - 1];
        int best = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            best = max(best, sell - prices[i] + profit[i]);
            sell = max(sell, prices[i]);
        }
        
        return best;
    }
};