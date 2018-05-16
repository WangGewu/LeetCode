class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>result;
        vector<string>s;
        string num;
        //result.push_back(0);
        for (int i = 0; i<n; i++)
            num += '0';
        //s.push_back(num);
        solve(result, s, num, n);
        return result;
    }
    void solve(vector<int>&result, vector<string>&s, string &num, int n)
    {
        if (find(s.begin(), s.end(), num) == s.end())
        {
            s.push_back(num);
            int m = 0;
            for (int i = 0; i<n; i++)
            {
                m = m * 2 + (num[i] - '0');
            }
            result.push_back(m);
        }
        else return;
        string temp = num;
        for (int i = n - 1; i >= 0; i--)
        {
            if (num[i] == '0')
                num[i] = '1';
            else
                num[i] = '0';
            solve(result, s, num, n);
            num = temp;
        }
    }
};