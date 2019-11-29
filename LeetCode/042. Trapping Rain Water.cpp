class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l<r)
        {
            int minHeight = min(height[l], height[r]);
            if (height[l] == minHeight)
            {
                while (++l<r&&height[l]<minHeight)
                    res += minHeight - height[l];

            }
            else
            {
                while (--r>l&&height[r]<minHeight)
                {
                    res += minHeight - height[r];
                }
            }
        }
        return res;
    }
};

//2刷
class Solution {
public:
    int trap(vector<int>& height) {
        int result=0;
        //按行遍历，每行每行算，超时
        while(1)
        {
            int last_pos=-1;
            int current=0;
            for(int i=0;i<height.size();i++)
            {
                if(height[i]>0&&last_pos==-1)
                {
                    last_pos=i;
                }
                else if(last_pos!=-1&&height[i]>0)
                {
                    current+=1*(i-last_pos-1);
                    last_pos=i;
                }
                height[i]--;
            }
            if(last_pos==-1)
                break;
            result+=current;
        }
        return result;
    }
};
