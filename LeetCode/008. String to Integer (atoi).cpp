class Solution {
public:
    int myAtoi(string str) {
        string value;
        int flag = 0;
        long long x = 0;
        int i;
        for (i = 0; i<str.size(); i++)
        {
            if (!isspace(str[i]))
                break;
        }
        if (str[i] == '+')
        {
            flag = 0;
            i++;
        }
        else if (str[i] == '-')
        {
            flag = 1;
            i++;
        }
        for (; i<str.size(); i++)
        {
            if (isdigit(str[i]))
            {
                value += str[i];
            }
            else
                break;
        }
        if (value.size()>10)
            return flag == 0 ? 2147483647 : -2147483648;
        for (auto i : value)
        {
            x = x * 10 + i - '0';
        }
        if (flag == 1)
            x = -x;
        if (x>2147483647)
            return 2147483647;
        if (x<-2147483648)
            return -2147483648;
        return x;
    }
};