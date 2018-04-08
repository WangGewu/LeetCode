#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        for(int reach=0;i<nums.size()&&i<=reach;i++)
        {
            reach = max(i + nums[i], reach);//reach为可以到达的最远位置
        }
        return i == nums.size();
    }
};