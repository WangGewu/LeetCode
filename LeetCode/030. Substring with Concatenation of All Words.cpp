class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>result;
        if (words.size() == 0)
            return result;
        map<string, int>m;
        for (auto i = words.begin(); i != words.end(); ++i)
            ++m[*i];
        map<string, int>temp;
        int i, j;
        for (i = 0; i < s.length() - words[0].length()*words.size() + 1; i++)
        {
            temp.clear();
            for (j = 0; j < words.size(); j++)
            {
                string subs = s.substr(i + j*words[0].length(), words[0].length());//将s中取出的子串以words元素的长度分割截取
                ++temp[subs];
            }
            if (m == temp)
                result.push_back(i);
        }
        return result;
    }
};