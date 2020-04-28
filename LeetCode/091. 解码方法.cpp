//边界条件真的让人糟心
class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0)return 0;
        if(s.length()==1)
            return s[0]=='0'?0:1;
        vector<int>dp(s.length()+1,0);
        dp[0]=1;
        dp[1]=s[0]=='0'?0:1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='0')
                dp[i+1]=(s[i-1]=='1'||s[i-1]=='2')?dp[i-1]:0;
            else
            {
                if(s[i-1]=='0'||((s[i-1]-'0')*10+s[i]-'0')>26)
                    dp[i+1]=dp[i];
                else
                    dp[i+1]=dp[i]+dp[i-1];
            }
        }
        return dp[s.length()];
    }
};
//超时
class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0)
            return 0;
        if(s.length()==1)
            return s[0]=='0'?0:1;
        if(s.length()==2)
        {
            if(s[0]=='0'||(s[1]=='0'&&(s[0]!='1'&&s[0]!='2')))
                return 0;
            return (((s[0]-'0')*10+s[1]-'0')>26||(s[1]=='0'&&(s[0]=='1'||s[0]=='2')))?1:2;
        }
        if(s[0]=='0'||(s[1]=='0'&&(s[0]!='1'&&s[0]!='2')))
            return 0;
        else if((s[1]=='0'&&(s[0]=='1'||s[0]=='2')))
            return numDecodings(s.substr(2,s.length()-2));
        else if((s[0]-'0')*10+s[1]-'0'>26)
            return numDecodings(s.substr(1,s.length()-1));
        else
            return numDecodings(s.substr(1,s.length()-1))+numDecodings(s.substr(2,s.length()-2));
    }
};