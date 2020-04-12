class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastLen = nums.size();
        int cnt = 0;
        int currentLen = 1;
        for (int i = 0; i < nums.size() - cnt; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])currentLen++;
            else
            {
                if (currentLen > 2)//数字的个数大于2，进行remove
                {
                    cout << i << endl;
                    for (int j = i - currentLen + 2; j < nums.size() - cnt - (currentLen - 2); j++)
                        nums[j] = nums[j + currentLen - 2];
                    cnt += (currentLen - 2);
                    i = i - (currentLen - 2);//移动后元素位置发生变化，回移i，使i指向要处理的下一个元素
                }
                currentLen = 1;
            }
        }
        if (currentLen>2)
            cnt += currentLen - 2;
        return lastLen - cnt;
    }
};
//2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int end=nums.size(),current_len=1;//当前数字的频次
        for(int i=1;i<end;i++)
        {
            if(nums[i]==nums[i-1])
                current_len++;
            else
            {
                if(current_len>2)
                {
                    for(int j=i;j<end;j++)
                        nums[j-(current_len-2)]=nums[j];
                    end=end-(current_len-2);
                    i=i-(current_len-2);
                    current_len=1;
                }
                else
                    current_len=1;
            }
        }
        return current_len>2?end-(current_len-2):end;
    }
};

//2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3)
            return nums.size();
        int len=2;//新数组长度
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]!=nums[len-2])//如果当前元素不等于已处理数据的倒数第二个元素
                nums[len++]=nums[i];
        }
        return len;
    }
};
