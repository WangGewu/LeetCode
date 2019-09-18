class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        if(strs.size()==0)
            return result;
        for(int i=0;i<strs[0].length();i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j][i]!=strs[0][i]||i>=strs[j].length())
                    return result;
            }
            result+=strs[0][i];
        }
        return result;
    }
};
