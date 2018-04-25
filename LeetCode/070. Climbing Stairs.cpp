//动态规划
class Solution {
public:
    int climbStairs(int n) {
        vector<int>res{ 1,2 };
        int last1 = 1;
        int last2 = 2;
        for (int i = 2; i < n; i++)
        {
            res.push_back(last1 + last2);
            last1 = last2;
            last2 = res[i];
        }
        return res[n - 1];
    }
};
