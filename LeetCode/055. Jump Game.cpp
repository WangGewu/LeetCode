#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        for(int reach=0;i<nums.size()&&i<=reach;i++)
        {
            reach = max(i + nums[i], reach);//reachΪ���Ե������Զλ��
        }
        return i == nums.size();
    }
};