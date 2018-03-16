class Solution {
public:
    int romanToInt(string s) {
        char c[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int t[] = {1, 5, 10, 50, 100, 500, 1000};
        map<char,int>v;
        for(int i=0;i<7;i++)
            v.insert(pair<char, int> (c[i], t[i]));
        int num=0;
        int i;
        for(i=0;i<s.length()-1;i++)
        {
            if(v[s[i+1]]<=v[s[i]])
                num+=v[s[i]];
            else
                num+=-v[s[i]];
        }
        num+=v[s[i]];
        return num;
    }
};
