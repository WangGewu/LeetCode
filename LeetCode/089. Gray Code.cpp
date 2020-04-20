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

//2
/**
关键是搞清楚格雷编码的生成过程, G(i) = i ^ (i/2);---------^表异或
如 n = 3: 
G(0) = 000, 
G(1) = 1 ^ 0 = 001 ^ 000 = 001
G(2) = 2 ^ 1 = 010 ^ 001 = 011 
G(3) = 3 ^ 1 = 011 ^ 001 = 010
G(4) = 4 ^ 2 = 100 ^ 010 = 110
G(5) = 5 ^ 2 = 101 ^ 010 = 111
G(6) = 6 ^ 3 = 110 ^ 011 = 101
G(7) = 7 ^ 3 = 111 ^ 011 = 100
**/
class Solution {
public:
    vector<int> grayCode(int n) {
        int size=pow(2,n);
        cout<<size;
        vector<int>result;
        for(int i=0;i<size;i++)
            result.push_back(i^i/2);
        return result;
    }
};
