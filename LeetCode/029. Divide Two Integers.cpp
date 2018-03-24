//采用位运算，divisor每次乘2去逼近dividend
class Solution {
public:
    int divide(int dividend, int divisor) {
        int num = 0;
        if ((dividend == INT_MIN&&divisor == -1) || divisor == 0)
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0) == 1) ? 0 : 1;
        long long p = labs(dividend), q = labs(divisor);
        while (p >= q)
        {
            long long cnt = 1;
            long long t = q;
            while (p >= (t << 1))
            {
                t = t << 1;
                cnt = cnt << 1;
            }
            p = p - t;
            num += cnt;
        }
        return sign == 1 ? num : -num;
    }
};