class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1)
            return 1;
        if (x == -1 && n % 2 == 0)
            return 1;
        if (x == -1 && n % 2 != 0)
            return -1;
        if (n == -2147483648)
            return 0;
        if (n == 0)
            return 1;
        if (n < 0)
        {
            n = -n;
            x = 1 / x;//如果是负数次方，将x变为1/x再处理
        }
        return (n % 2 == 0) ? myPow(x*x, n / 2) : x*myPow(x*x, n / 2);//分别处理奇数次方和偶数次方
    }
};