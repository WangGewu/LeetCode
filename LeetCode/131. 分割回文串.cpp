class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>temp;
        solve(s,0,temp,result);
        return result;
    }
    void solve(string s,int start,vector<string>&temp,vector<vector<string>>&result)
    {
        if(start>=s.length())
        {
            result.push_back(temp);
            return;
        }
        for(int i=1;i<=s.length()-start;i++)
        {
            string sub=s.substr(start,i);
            if(isPalindrome(sub))
            {
                temp.push_back(sub);
                solve(s,start+i,temp,result);
                temp.pop_back();
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