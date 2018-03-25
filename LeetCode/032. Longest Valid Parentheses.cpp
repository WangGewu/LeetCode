class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>sta;//��ջ�洢�ƻ�����ƥ������ŵ��±꣬��"()(()",�洢2
        int len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                sta.push(i);
            else
            {
                if (!sta.empty())
                {
                    if (s[sta.top()] == '(')sta.pop();
                    else
                        sta.push(i);
                }
                else sta.push(i);
            }
        }
        if (sta.empty())
            return s.length();
        else
        {
            int right = s.length() - 1;
            while (!sta.empty())//���ݶ�ջ������±꽫ԭs�ָ���������ĳ���
            {
                int left = sta.top();
                sta.pop();
                len = max(len, right - left);
                right = left - 1;
            }
            len = max(len, right + 1);
        }
        return len;
    }
};