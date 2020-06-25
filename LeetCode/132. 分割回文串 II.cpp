//超时

class Solution {
public:
    int minCut(string s) {
        int result = s.size()-1;
        int cnt=0;
        solve(s,0,cnt,result);
        return result;
    }
    void solve(string s,int start,int& cnt,int& result)
    {
        if(start>=s.length())
        {
            if(cnt<result)
                result=cnt;
            return;
        }
        for(int i=1;i<=s.length()-start;i++)
        {
            string sub=s.substr(start,i);
            if(isPalindrome(sub))
            {   if(i!=s.length()-start)
                    cnt++;
                solve(s,start+i,cnt,result);
                if(i!=s.length()-start)
                    cnt--;
            }
        }
    }
    bool isPalindrome(string s)
    {
        int l=0,r=s.length()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;r--;
        }
        return true;
    }
};

//dp 超时
class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        if(n==0)return 0;
        int dp[n];
        dp[0]=0;
        for(int i=1;i<s.length();i++)
        {
            int m=INT_MAX;
            string sub=s.substr(0,i+1);
            if(isPalindrome(sub))
                dp[i]=0;
            else
            {
                for(int j=0;j<=i;j++)
                {
                    if(isPalindrome(s.substr(j,i-j+1))&&dp[j-1]<m)
                    {
                        m=dp[j-1];
                        dp[i]=m+1;
                    }

                }
            }
        }
        return dp[n-1];
    }
    bool isPalindrome(string s)
    {
        int l=0,r=s.length()-1;
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;r--;
        }
        return true;
    }
};