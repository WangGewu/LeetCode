class Solution {
public:
    int numDistinct(string s, string t) {
        int l1=s.length(),l2=t.length();
        vector<vector<long>>dp(l2+1,vector<long>(l1+1));
        for(int i=0;i<l1+1;i++)
            dp[0][i]=1;
        for(int i=1;i<l2+1;i++)
            dp[i][0]=0;
        for(int i=1;i<l2+1;i++)
            for(int j=1;j<l1+1;j++)
            {
                if(t[i-1]==s[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1]; //用第s[j]+不用s[j]
                else
                    dp[i][j]=dp[i][j-1];
            }
        return dp[l2][l1];
    }
};