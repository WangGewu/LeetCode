class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string result;
        string temp;
        int flag;
        for (int i = num1.length() - 1; i >= 0; i--)
        {
            flag = 0;
            temp.clear();
            for (int j = num2.length() - 1; j >= 0; j--)
            {
                temp += ((num1[i] - '0')*(num2[j] - '0') + flag) % 10 + '0';
                flag = ((num1[i] - '0')*(num2[j] - '0') + flag) / 10;
            }
            if (flag)
                temp += flag + '0';
            reverse(temp.begin(), temp.end());
            result = add(temp, result, (num1.length() - 1) - i);
        }
        return result;
    }
    string add(string num1, string num2, int n) {
        if (num2.length() == 0)
            return num1;
        string result;
        for (int i = 0; i < n; i++)
            num1 += '0';
        int flag = 0;
        int cnt = 0;
        int i = num1.length() - 1, j = num2.length() - 1;
        while (i >= 0 && j >= 0)
        {
            result += (num1[i] - '0' + num2[j] - '0' + flag) % 10 + '0';
            flag = (num1[i] - '0' + num2[j] - '0' + flag) / 10;
            i--; j--;
        }
        while (i >= 0)
        {
            result += (num1[i] - '0' + flag) % 10 + '0';
            flag = (num1[i] - '0' + flag) / 10;
            i--;
        }
        while (j >= 0)
        {
            result += (num2[j] - '0' + flag) % 10 + '0';
            flag = (num2[j] - '0' + flag) / 10;
            j--;
        }
        if (flag == 1)
            result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};
