class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string s[10]{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        vector<string>result;
        int len = digits.length();
        if (len == 0)
            return result;
        string value(len, 'a');//使用value保存每次遍历的结果
        dfs(result, digits, value, s, 0);
        return result;
    }
    void dfs(vector<string>&v, string &s1, string &s2, string(&s3)[10], int pos)//s1=digits,s2=value,s3=s
    {
        if (pos == s1.length())//到达digits的末尾，存入vector，且返回
        {
            v.push_back(s2);
            return;
        }
        for (int i = 0; i < s3[s1[pos] - '0'].length(); i++)
        {
            s2[pos] = s3[s1[pos] - '0'][i];
            dfs(v, s1, s2, s3, pos + 1);
        }
    }
};