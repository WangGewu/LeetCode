class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>dp;
        int result=0;
        if(prices.size()==0)
            return result;
        dp.push_back(0);
        int min_price=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            dp.push_back(max(dp[i-1],prices[i]-min_price));
            if(dp[i]>result)
                result=dp[i];
            if(min_price>prices[i])
                min_price=prices[i];
        }
        return result;
    }
};