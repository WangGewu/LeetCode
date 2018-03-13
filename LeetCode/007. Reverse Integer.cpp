class Solution {
public:
    int reverse(int x) {
        long long value = 0;
        int flag = 0;
        if (x < 0)
        {
            flag = 1;
            x = -x;
        }
        string s = to_string(x);
        for (int i = s.size() - 1; i >= 0; i--)
        {
            value = value * 10 + s[i] - '0';
        }
        if (value > 2147483647 || value < -2147483648)
            return 0;
        return flag == 0 ? value : -value;
    }
};