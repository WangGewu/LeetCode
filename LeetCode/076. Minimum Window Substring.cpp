class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>flag(256, 0);
        int min = INT_MAX;
        int begin = 0, end = 0, head = 0, cnt = t.size();//cntͳ��t��ʣ��δ�ҵ�����ĸ��
        for (int i = 0; i < t.size(); i++)
            flag[t[i]]++;
        while (end < s.size())
        {
            if (flag[s[end]] > 0)//�ҵ�һ��t��һ����ĸ
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
                if (flag[s[begin]] == 0)
                    cnt++;
                flag[s[begin]]++;
                begin++;
            }
        }
        return min == INT_MAX ? "" : s.substr(head, min);
    }
};