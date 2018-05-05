class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int min = 0;//记录vector中值最小的元素，下一次递归从比min大的数开始
        vector<vector<int>> result;
        vector<int>element;
        solve(result, element, n, k, min);
        return result;
    }
    void solve(vector<vector<int>>&res, vector<int>&element, int n, int k, int &min)
    {
        if (element.size() == k)
        {
            res.push_back(element);
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (i <= min)continue;
            element.push_back(i);
            min = i;
            solve(res, element, n, k, min);
            element.pop_back();
            min = element[element.size() - 1];
        }
    }
};