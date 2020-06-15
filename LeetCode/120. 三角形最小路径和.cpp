class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        if(n>0)dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++)
            for(int j=0;j<=i;j++)
            {
                int length;
                if(j==0)
                    length=dp[i-1][j]+triangle[i][j];
                else if(j==i)
                    length=dp[i-1][j-1]+triangle[i][j];
                else
                    length=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
                dp[i][j]=length;
            }
        int result = *min_element(dp[n-1].begin(),dp[n-1].end());
        return result;
    }
};