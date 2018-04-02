class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        map<string, int>m;
        vector<string>element;
        int cnt = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());//���ֵ�������
            if (m.find(s) == m.end())//���map��û������ӽ�ȥ
            {
                m[s] = cnt++;
                res.push_back(element);
            }
            res[m[s]].push_back(strs[i]);
        }
        return res;
    }
};