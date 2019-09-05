    
class Solution {
public:
    int reverse(int x) {
        long long value = 0;
        int flag = 0;
        int end=0;
        if (x < 0)
            flag = 1;
        string s = to_string(x);
        if(flag==1)
            end=1;
        for (int i = s.size() - 1; i >= end; i--)
        {
            value = value * 10 + s[i] - '0';
            if (value > 2147483647 || value < -2147483648)
                return 0;
        }
        return flag == 0 ? value : -value;
    }
};
