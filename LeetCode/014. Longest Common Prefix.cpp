class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int j = 0, i;
        if (strs.size() == 0)
            return result;
        while (j<strs[0].length())
        {
            for (i = 1; i<strs.size(); i++)
            {
                if (j >= strs[i].length() || strs[i][j] != strs[0][j])
                    return result;
            }
            result += strs[0][j];
            j++;
        }
        return result;
    }
};