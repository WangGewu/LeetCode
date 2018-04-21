class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int temp = (digits[i] + flag) / 10;
            digits[i] = (digits[i] + flag) % 10;
            flag = temp;
        }
        if (flag)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};