class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int p = a.length() - 1;
        int q = b.length() - 1;
        int add1, add2;
        int flag = 0;//标志进位
        while (p >= 0 && q >= 0)
        {
            add1 = a[p] - '0';
            add2 = b[q] - '0';
            res += (add1 + add2 + flag) % 2 + '0';
            flag = (add1 + add2 + flag) / 2;
            p--; q--;
        }
        while (p >= 0)
        {
            add1 = a[p] - '0';
            res += (add1 + flag) % 2 + '0';
            flag = (add1 + flag) / 2;
            p--;
        }
        while (q >= 0)
        {
            add2 = b[q] - '0';
            res += (add2 + flag) % 2 + '0';
            flag = (add2 + flag) / 2;
            q--;
        }
        if (flag)
            res += flag + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};
