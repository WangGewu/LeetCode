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
//2
class Solution {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            if (digits[i] != 0) return digits;
        }
        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;
    }
}
