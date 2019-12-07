//建树的过程
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        vector<int>deep(nums.size(), 0);
        queue<int>q;
        int i = 0;
        q.push(i);
        deep[i] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int i = 1; i <= nums[node]; i++)
            {
                if (deep[i + node] == 0)
                {
                    deep[i + node] = deep[node] + 1;
                    q.push(i + node);
                }
                if (i + node >= nums.size() - 1)
                    return deep[nums.size() - 1];
            }
        }
    }
};
