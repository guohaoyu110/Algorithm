class Solution
{
//还是不会写，直接理解答案吧。。。
  public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        int ans = 0;
        if (k >= prices.size() / 2)
        {
            for (int i = 1; i < prices.size(); ++i)
            {
                if (prices[i] - prices[i - 1] > 0)
                {
                    ans += prices[i] - prices[i - 1];
                }
            }
        }
        else
        {
            vector<int> local(k + 1);
            vector<int> global(k + 1);

            for (int i = 0; i < prices.size() - 1; ++i)
            {
                int increase = prices[i + 1] - prices[i];

                for (int j = k; j >= 1; --j)
                {
                    local[j] = max(global[j - 1] + max(increase, 0), local[j] + increase);
                    global[j] = max(global[j], local[j]);
                }
            }
            ans = global[k];
        }
        return ans;
    }
};