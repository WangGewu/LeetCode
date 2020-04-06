class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++)//word1为空
            dp[0][i] = i;
        for (int i = 0; i <= m; i++)//word2为空
            dp[i][0] = i;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])//减一是从字符串的第一个字符开始拿
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        return dp[m][n];
        ;
    }
};