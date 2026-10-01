class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxDiff = 0;
        while(r < prices.size())
        {
            int diff = prices[r] - prices[l];
            maxDiff = max(maxDiff, diff);
            if(prices[r] < prices[l])
            {
                l = r;
            }
            r++;
            
        }
        return maxDiff;
    }
};
