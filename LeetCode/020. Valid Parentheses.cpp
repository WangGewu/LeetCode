class Solution {
public:
    bool isValid(string s) {
        map<char, char>m;
        stack<char>sta;
        m.insert(make_pair<char, char>(')', '('));
        m.insert(make_pair<char, char>(']', '['));
        m.insert(make_pair<char, char>('}', '{'));
        for (auto i : s)
        {
            if (i != ')'&&i != ']'&&i != '}')
                sta.push(i);
            else
            {
                if (sta.empty())
                    return false;
                char c = sta.top();
                sta.pop();
                if (c != m[i])
                    return false;
            }
        }
        if (sta.empty())
            return true;
        else
            return false;
    }
};