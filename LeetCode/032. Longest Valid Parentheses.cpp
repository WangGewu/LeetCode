class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>sta;//堆栈存储破坏括号匹配的括号的下标，如"()(()",存储2
        int len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                sta.push(i);
            else
            {
                if (!sta.empty())
                {
                    if (s[sta.top()] == '(')sta.pop();
                    else
                        sta.push(i);
                }
                else sta.push(i);
            }
        }
        if (sta.empty())
            return s.length();
        else
        {
            int right = s.length() - 1;
            while (!sta.empty())//根据堆栈保存的下标将原s分割开，计算最大的长度
            {
                int left = sta.top();
                sta.pop();
                len = max(len, right - left);
                right = left - 1;
            }
            len = max(len, right + 1);
        }
        return len;
    }
};

//2刷
//动态规划
class Solution {
public:
    int longestValidParentheses(string s) {
        int length=s.length();
        int max=0;
        vector<int>dp(length);
        for(int i=1;i<length;i++)
        {
            if(s[i]==')'&&s[i-1]=='(')
                dp[i]=2+((i-2)>=0?dp[i-2]:0);
            if(s[i]==')'&&s[i-1]==')')
                if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='(')
                    dp[i]=dp[i-1]+2+((i-dp[i-1]-2)>=0?dp[i-dp[i-1]-2]:0);
            if(dp[i]>max)
                max=dp[i];
        }
        return max;
    }
};
