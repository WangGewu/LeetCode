class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
        if(s1.length()!=s2.length())
            return false;
        int cnt[26]={0};
        for(int i=0;i<s1.length();i++)
        {
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++)
            if(cnt[i]!=0)
                return false;
        for(int i=1;i<s1.length();i++)
            if((isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))||(isScramble(s1.substr(0,i),s2.substr(s1.length()-i))&&isScramble(s1.substr(i),s2.substr(0,s1.length()-i))))
                return true;
        return false;
    }
};