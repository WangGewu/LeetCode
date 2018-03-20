class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        if (n == 0)
            return result;
        dfs(result, "", n, n);
        return result;
    }
    //¶þ²æÊ÷+µÝ¹é
    void dfs(vector<string>&v, string s, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            v.push_back(s);
            return;
        }
        if (left>0)
            dfs(v, s + '(', left - 1, right);
        if (left<right)
        {
            dfs(v, s + ')', left, right - 1);
        }
    }
};