class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        int b = x;
        long long a = 0;
        while (b != 0)
        {
            a = a * 10 + b % 10;
            b /= 10;
        }
        if (x == a)
            return true;
        else
            return false;
    }
};