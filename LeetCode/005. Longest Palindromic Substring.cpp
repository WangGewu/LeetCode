class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        int first=0,max=0;
        int cnt;
        for(int i=0;i<s.length();i++)
        {
            //'bab'
            cnt=1;
            for(int j=1;(j+i)<s.length()&&(i-j)>=0;j++)
            {
                if(s[i+j]==s[i-j])
                    cnt+=2;
                else
                    break;
            }
            if(cnt>max)
            {
                max=cnt;
                result=s.substr(i-cnt/2,cnt);
            }
            //'bb'
            if(i>=1&&s[i]==s[i-1])
            {
                cnt=2;
                for(int j=1;(i+j)<s.length()&&(i-j-1)>=0;j++)
                {
                    if(s[i+j]==s[i-j-1])
                        cnt+=2;
                    else
                        break;
                }
                if(cnt>max)
                {
                    max=cnt;
                    result=s.substr(i-cnt/2,cnt);
                }
            }
        }
        return result;
    }
};
