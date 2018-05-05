class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>flag(256, 0);
        int min = INT_MAX;
        int begin = 0, end = 0, head = 0, cnt = t.size();//cnt统计t中剩余未找到的字母数，head记录首位置
        for (int i = 0; i < t.size(); i++)
            flag[t[i]]++;
        while (end < s.size())
        {
            if (flag[s[end]] > 0)//找到一个t中一个字母
                cnt--;
            flag[s[end]]--;
            end++;
            while (cnt == 0)
            {
                if (end - begin< min)
                {
                    min = end - begin;
                    head = begin;
                }
                if (flag[s[begin]] == 0)//begin为t中的字母,此时除t中字母外的其他字母数都是负的
                    cnt++;
                flag[s[begin]]++;
                begin++;
            }
        }
        return min == INT_MAX ? "" : s.substr(head, min);
    }
};
