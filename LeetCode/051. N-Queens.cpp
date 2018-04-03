class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>element(n, string(n, '.'));
        solve(res, element, 0, n);
        return res;
    }
    void solve(vector<vector<string>>&res, vector<string>&element, int line, int n)//���еݹ�
    {
        if (line == n)
        {
            res.push_back(element);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            element[line][i] = 'Q';
            if (check(element, n))
                solve(res, element, line + 1, n);
            element[line][i] = '.';
        }
    }
    bool check(vector<string>&res, int n)
    {
        vector<int>v(n, -1);
        vector<int>flag(n, 0);
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].length(); j++)
                if (res[i][j] == 'Q')//����ÿһ�д�ŵ�λ��
                    v[i] = j;
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] != -1)
            {
                if (flag[v[i]] == 1)//�������
                    return false;
                else
                    flag[v[i]] = 1;
                for (int j = i + 1; j < n; j++)//���Խ���
                {
                    if (v[j] != -1 && abs(v[j] - v[i]) == j - i)
                        return false;
                }
            }
        }
        return true;
    }
};