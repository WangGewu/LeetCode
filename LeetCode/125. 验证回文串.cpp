class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.length()-1;
        while(1)
        {
            while(l<s.length()&&!check(s[l]))l++;
            while(r>=0&&!check(s[r]))r--;
            if(l>r)break;
            s[l] = s[l]& 0b11011111;
            s[r] = s[r]& 0b11011111;
            if((abs(s[l]-s[r])!=0))return false;
            l++;r--;
        }
        return true;
    }
    bool check(char c)
    {
        if(c>='0'&&c<='9')return true;
        else if(c>='a'&&c<='z')return true;
        else if(c>='A'&&c<='Z')return true;
        else return false;
    }
};