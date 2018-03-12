class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if (numRows == 1)
            return s;
        for (int i = 0; i<numRows; i++)
        {
            int j = i;
            while (j<s.size())
            {
                result += s[j];
                //处理中间行
                if (i>0 && i<numRows - 1)
                {
                    if ((numRows - i - 1) * 2 + j<s.size())
                        result += s[(numRows - i - 1) * 2 + j];
                }
                j += 2 * (numRows - 1);
            }
        }
        return result;
    }
};
