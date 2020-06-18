class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0)return 0;
        int dp[n][3][2];
        dp[0][0][0]=0;dp[0][1][1]=-prices[0];dp[0][1][0]=0;
        dp[0][2][0]=0;dp[0][2][1]=-prices[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0][0]=0;
            dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][1][1]+prices[i]);
            dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][0]-prices[i]);
            dp[i][2][0]=max(dp[i-1][2][0],dp[i-1][2][1]+prices[i]);
            dp[i][2][1]=max(dp[i-1][2][1],dp[i-1][1][0]-prices[i]);
        }
        return max(dp[n-1][0][0],max(dp[n-1][2][0],dp[n-1][1][0]));
    }
};